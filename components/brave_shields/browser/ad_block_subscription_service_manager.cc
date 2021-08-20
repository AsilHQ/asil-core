/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/brave_shields/browser/ad_block_subscription_service_manager.h"

#include <memory>
#include <utility>
#include <vector>

#include "base/base64url.h"
#include "base/bind.h"
#include "base/files/file_util.h"
#include "base/json/json_value_converter.h"
#include "base/strings/string_util.h"
#include "base/task/post_task.h"
#include "base/task/thread_pool.h"
#include "base/time/time.h"
#include "base/util/values/values_util.h"
#include "base/values.h"
#include "brave/components/adblock_rust_ffi/src/wrapper.h"
#include "brave/components/brave_shields/browser/ad_block_service_helper.h"
#include "brave/components/brave_shields/browser/ad_block_subscription_service.h"
#include "brave/components/brave_shields/browser/ad_block_subscription_service_manager_observer.h"
#include "brave/components/brave_shields/common/brave_shield_constants.h"
#include "brave/components/brave_shields/common/pref_names.h"
#include "components/prefs/pref_service.h"
#include "components/prefs/scoped_user_pref_update.h"
#include "content/public/browser/browser_task_traits.h"
#include "crypto/sha2.h"
#include "net/base/filename_util.h"

namespace brave_shields {

namespace {

const base::TimeDelta kListUpdateInterval = base::TimeDelta::FromDays(7);

SubscriptionInfo BuildInfoFromDict(const GURL& sub_url,
                                   const base::Value* dict) {
  DCHECK(dict);
  DCHECK(dict->is_dict());

  SubscriptionInfo info;
  base::JSONValueConverter<SubscriptionInfo> converter;
  converter.Convert(*dict, &info);

  info.subscription_url = sub_url;

  return info;
}

const base::FilePath::CharType kSubscriptionsDir[] =
    FILE_PATH_LITERAL("FilterListSubscriptionCache");

}  // namespace

AdBlockSubscriptionServiceManager::AdBlockSubscriptionServiceManager(
    brave_component_updater::BraveComponent::Delegate* delegate,
    AdBlockSubscriptionDownloadManager::DownloadManagerGetter
        download_manager_getter,
    const base::FilePath& profile_dir)
    : delegate_(delegate),
      subscription_path_(profile_dir.Append(kSubscriptionsDir)),
      subscriptions_(new base::DictionaryValue()) {
  LoadSubscriptionServices();
  std::move(download_manager_getter)
      .Run(base::BindOnce(
          &AdBlockSubscriptionServiceManager::OnGetDownloadManager,
          weak_ptr_factory_.GetWeakPtr()));
}

AdBlockSubscriptionServiceManager::~AdBlockSubscriptionServiceManager() {}

base::FilePath AdBlockSubscriptionServiceManager::GetSubscriptionPath(
    const GURL& sub_url) const {
  // Subdirectories are generated by taking the SHA256 hash of the list URL
  // spec, then base64 encoding that hash. This generates paths that are:
  //     - deterministic
  //     - unique
  //     - constant length
  //     - path-safe
  //     - not too long (exactly 45 characters)
  const std::string hash = crypto::SHA256HashString(sub_url.spec());

  std::string pathsafe_hash;
  base::Base64UrlEncode(hash, base::Base64UrlEncodePolicy::INCLUDE_PADDING,
                        &pathsafe_hash);

  return subscription_path_.AppendASCII(pathsafe_hash);
}

GURL AdBlockSubscriptionServiceManager::GetListTextFileUrl(
    const GURL sub_url) const {
  base::FilePath cached_list_path = GetSubscriptionPath(sub_url).Append(
      brave_shields::kCustomSubscriptionListText);

  const GURL file_url = net::FilePathToFileURL(cached_list_path);

  return file_url;
}

void AdBlockSubscriptionServiceManager::OnUpdateTimer(
    const GURL& sub_url,
    bool from_ui,
    component_updater::TimerUpdateScheduler::OnFinishedCallback on_finished) {
  ready_.Post(FROM_HERE,
              base::BindOnce(&AdBlockSubscriptionServiceManager::StartDownload,
                             weak_ptr_factory_.GetWeakPtr(), sub_url, from_ui));

  std::move(on_finished).Run();
}

void AdBlockSubscriptionServiceManager::StartDownload(const GURL& sub_url,
                                                      bool from_ui) {
  DCHECK(ready_.is_signaled());
  // The download manager is tied to the lifetime of the system profile, but
  // the AdBlockSubscriptionServiceManager lives as long as the browser process
  if (download_manager_) {
    download_manager_->StartDownload(sub_url, from_ui);
  }
}

void AdBlockSubscriptionServiceManager::CreateSubscription(
    const GURL& sub_url) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  SubscriptionInfo info;
  info.subscription_url = sub_url;
  info.last_update_attempt = base::Time();
  info.last_successful_update_attempt = base::Time();
  info.enabled = true;

  auto subscription_service = std::make_unique<AdBlockSubscriptionService>(
      info, GetSubscriptionPath(sub_url).Append(kCustomSubscriptionListText),
      delegate_);
  UpdateSubscriptionPrefs(sub_url, info);

  std::unique_ptr<component_updater::TimerUpdateScheduler> timer =
      std::make_unique<component_updater::TimerUpdateScheduler>();
  timer->Schedule(
      base::TimeDelta(), kListUpdateInterval,
      base::BindRepeating(&AdBlockSubscriptionServiceManager::OnUpdateTimer,
                          weak_ptr_factory_.GetWeakPtr(), sub_url, true),
      base::DoNothing());

  {
    base::AutoLock lock(subscription_services_lock_);
    // this could allow more than one service for a given url
    subscription_services_.insert(
        std::make_pair(sub_url, std::move(subscription_service)));
    subscription_update_timers_.insert(
        std::make_pair(sub_url, std::move(timer)));
  }
}

std::vector<SubscriptionInfo>
AdBlockSubscriptionServiceManager::GetSubscriptions() {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  auto infos = std::vector<SubscriptionInfo>();

  for (const auto& subscription_service : subscription_services_) {
    auto info = GetInfo(subscription_service.first);
    DCHECK(info);
    infos.push_back(*info);
  }

  return infos;
}

void AdBlockSubscriptionServiceManager::EnableSubscription(const GURL& sub_url,
                                                           bool enabled) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  auto info = GetInfo(sub_url);
  DCHECK(info);

  info->enabled = enabled;

  UpdateSubscriptionPrefs(sub_url, *info);
}

void AdBlockSubscriptionServiceManager::DeleteSubscription(
    const GURL& sub_url) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  {
    base::AutoLock lock(subscription_services_lock_);
    auto it = subscription_services_.find(sub_url);
    DCHECK(it != subscription_services_.end());
    subscription_services_.erase(it);

    auto timer_it = subscription_update_timers_.find(sub_url);
    DCHECK(timer_it != subscription_update_timers_.end());
    subscription_update_timers_.erase(timer_it);
  }
  ClearSubscriptionPrefs(sub_url);

  base::ThreadPool::PostTask(
      FROM_HERE,
      {base::MayBlock(), base::TaskPriority::BEST_EFFORT,
       base::TaskShutdownBehavior::BLOCK_SHUTDOWN},
      base::BindOnce(base::IgnoreResult(&base::DeletePathRecursively),
                     GetSubscriptionPath(sub_url)));
}

void AdBlockSubscriptionServiceManager::RefreshSubscription(const GURL& sub_url,
                                                            bool from_ui) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);

  auto it = subscription_update_timers_.find(sub_url);
  DCHECK(it != subscription_update_timers_.end());
  it->second->Stop();
  it->second->Schedule(
      base::TimeDelta(), kListUpdateInterval,
      base::BindRepeating(&AdBlockSubscriptionServiceManager::OnUpdateTimer,
                          weak_ptr_factory_.GetWeakPtr(), sub_url, true),
      base::DoNothing());
}

void AdBlockSubscriptionServiceManager::OnGetDownloadManager(
    AdBlockSubscriptionDownloadManager* download_manager) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  download_manager_ = download_manager->AsWeakPtr();
  // base::Unretained is ok here because AdBlockSubscriptionServiceManager will
  // outlive AdBlockSubscriptionDownloadManager
  download_manager_->set_subscription_path_callback(base::BindRepeating(
      &AdBlockSubscriptionServiceManager::GetSubscriptionPath,
      base::Unretained(this)));
  download_manager_->set_on_download_succeeded_callback(base::BindRepeating(
      &AdBlockSubscriptionServiceManager::OnSubscriptionDownloaded,
      base::Unretained(this)));
  download_manager_->set_on_download_failed_callback(base::BindRepeating(
      &AdBlockSubscriptionServiceManager::OnSubscriptionDownloadFailure,
      base::Unretained(this)));
  ready_.Signal();
}

absl::optional<SubscriptionInfo> AdBlockSubscriptionServiceManager::GetInfo(
    const GURL& sub_url) {
  auto* list_subscription_dict = subscriptions_->FindKey(sub_url.spec());
  if (!list_subscription_dict)
    return absl::nullopt;

  return absl::make_optional<SubscriptionInfo>(
      BuildInfoFromDict(sub_url, list_subscription_dict));
}

void AdBlockSubscriptionServiceManager::LoadSubscriptionServices() {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);

  PrefService* local_state = delegate_->local_state();
  if (!local_state)
    return;

  base::AutoLock lock(subscription_services_lock_);
  subscriptions_ = base::DictionaryValue::From(base::Value::ToUniquePtrValue(
      local_state->GetDictionary(prefs::kAdBlockListSubscriptions)->Clone()));

  for (base::DictionaryValue::Iterator it(*subscriptions_); !it.IsAtEnd();
       it.Advance()) {
    const std::string key = it.key();
    SubscriptionInfo info;
    const base::Value* list_subscription_dict =
        subscriptions_->FindDictKey(key);
    if (list_subscription_dict) {
      GURL sub_url(key);
      info = BuildInfoFromDict(sub_url, list_subscription_dict);

      auto subscription_service = std::make_unique<AdBlockSubscriptionService>(
          info,
          GetSubscriptionPath(sub_url).Append(kCustomSubscriptionListText),
          delegate_);

      std::unique_ptr<component_updater::TimerUpdateScheduler> timer =
          std::make_unique<component_updater::TimerUpdateScheduler>();

      if (info.enabled) {
        base::TimeDelta initial_delay =
            kListUpdateInterval -
            (base::Time::Now() - info.last_update_attempt);
        if (initial_delay < base::TimeDelta()) {
          initial_delay = base::TimeDelta();
        }
        timer->Schedule(initial_delay, kListUpdateInterval,
                        base::BindRepeating(
                            &AdBlockSubscriptionServiceManager::OnUpdateTimer,
                            weak_ptr_factory_.GetWeakPtr(), sub_url, false),
                        base::DoNothing());
      }

      subscription_services_.insert(
          std::make_pair(sub_url, std::move(subscription_service)));
      subscription_update_timers_.insert(
          std::make_pair(sub_url, std::move(timer)));
    }
  }
}

// Updates preferences to reflect a new state for the specified filter list
// subscription. Creates the entry if it does not yet exist.
void AdBlockSubscriptionServiceManager::UpdateSubscriptionPrefs(
    const GURL& sub_url,
    const SubscriptionInfo& info) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  PrefService* local_state = delegate_->local_state();
  if (!local_state)
    return;

  DictionaryPrefUpdate update(local_state, prefs::kAdBlockListSubscriptions);
  base::DictionaryValue* subscriptions_dict = update.Get();
  auto subscription_dict = base::Value(base::Value::Type::DICTIONARY);
  subscription_dict.SetBoolKey("enabled", info.enabled);
  subscription_dict.SetKey("last_update_attempt",
                           util::TimeToValue(info.last_update_attempt));
  subscription_dict.SetKey(
      "last_successful_update_attempt",
      util::TimeToValue(info.last_successful_update_attempt));
  subscriptions_dict->SetKey(sub_url.spec(), std::move(subscription_dict));

  // TODO(bridiver) - change to pref registrar
  base::AutoLock lock(subscription_services_lock_);
  subscriptions_ = base::DictionaryValue::From(
      base::Value::ToUniquePtrValue(subscriptions_dict->Clone()));
}

// Updates preferences to remove all state for the specified filter list
// subscription.
void AdBlockSubscriptionServiceManager::ClearSubscriptionPrefs(
    const GURL& sub_url) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  PrefService* local_state = delegate_->local_state();
  if (!local_state)
    return;

  DictionaryPrefUpdate update(local_state, prefs::kAdBlockListSubscriptions);
  base::DictionaryValue* subscriptions_dict = update.Get();
  subscriptions_dict->RemoveKey(sub_url.spec());

  // TODO(bridiver) - change to pref registrar
  base::AutoLock lock(subscription_services_lock_);
  subscriptions_ = base::DictionaryValue::From(
      base::Value::ToUniquePtrValue(subscriptions_dict->Clone()));
}

bool AdBlockSubscriptionServiceManager::Start() {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  for (const auto& subscription_service : subscription_services_) {
    subscription_service.second->Start();
  }
  return true;
}

void AdBlockSubscriptionServiceManager::ShouldStartRequest(
    const GURL& url,
    blink::mojom::ResourceType resource_type,
    const std::string& tab_host,
    bool aggressive_blocking,
    bool* did_match_rule,
    bool* did_match_exception,
    bool* did_match_important,
    std::string* mock_data_url) {
  base::AutoLock lock(subscription_services_lock_);
  for (const auto& subscription_service : subscription_services_) {
    auto info = GetInfo(subscription_service.first);
    if (info && info->enabled) {
      subscription_service.second->ShouldStartRequest(
          url, resource_type, tab_host, aggressive_blocking, did_match_rule,
          did_match_exception, did_match_important, mock_data_url);
      if (did_match_important && *did_match_important) {
        return;
      }
    }
  }
}

void AdBlockSubscriptionServiceManager::EnableTag(const std::string& tag,
                                                  bool enabled) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  for (const auto& subscription_service : subscription_services_) {
    subscription_service.second->EnableTag(tag, enabled);
  }
}

void AdBlockSubscriptionServiceManager::AddResources(
    const std::string& resources) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  for (const auto& subscription_service : subscription_services_) {
    subscription_service.second->AddResources(resources);
  }
}

absl::optional<base::Value>
AdBlockSubscriptionServiceManager::UrlCosmeticResources(
    const std::string& url) {
  absl::optional<base::Value> first_value = absl::nullopt;

  base::AutoLock lock(subscription_services_lock_);
  for (auto it = subscription_services_.begin();
       it != subscription_services_.end(); it++) {
    auto info = GetInfo(it->first);
    if (info && info->enabled) {
      absl::optional<base::Value> next_value =
          it->second->UrlCosmeticResources(url);
      if (first_value) {
        if (next_value) {
          MergeResourcesInto(std::move(*next_value), &*first_value, false);
        }
      } else {
        first_value = std::move(next_value);
      }
    }
  }

  return first_value;
}

absl::optional<base::Value>
AdBlockSubscriptionServiceManager::HiddenClassIdSelectors(
    const std::vector<std::string>& classes,
    const std::vector<std::string>& ids,
    const std::vector<std::string>& exceptions) {
  absl::optional<base::Value> first_value = absl::nullopt;

  base::AutoLock lock(subscription_services_lock_);
  for (auto it = subscription_services_.begin();
       it != subscription_services_.end(); it++) {
    auto info = GetInfo(it->first);
    if (info && info->enabled) {
      absl::optional<base::Value> next_value =
          it->second->HiddenClassIdSelectors(classes, ids, exceptions);
      if (first_value && first_value->is_list()) {
        if (next_value && next_value->is_list()) {
          for (auto i = next_value->GetList().begin();
               i < next_value->GetList().end(); i++) {
            first_value->Append(std::move(*i));
          }
        }
      } else {
        first_value = std::move(next_value);
      }
    }
  }

  return first_value;
}

void AdBlockSubscriptionServiceManager::OnSubscriptionDownloaded(
    const GURL& sub_url) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  auto it = subscription_services_.find(sub_url);
  if (it == subscription_services_.end())
    return;

  auto info = GetInfo(sub_url);
  if (!info)
    return;

  info->last_update_attempt = base::Time::Now();
  info->last_successful_update_attempt = info->last_update_attempt;
  UpdateSubscriptionPrefs(sub_url, *info);

  it->second->ReloadList();

  NotifyObserversOfServiceEvent();
}

void AdBlockSubscriptionServiceManager::OnSubscriptionDownloadFailure(
    const GURL& sub_url) {
  auto info = GetInfo(sub_url);
  if (!info)
    return;

  info->last_update_attempt = base::Time::Now();
  UpdateSubscriptionPrefs(sub_url, *info);

  NotifyObserversOfServiceEvent();
}

void AdBlockSubscriptionServiceManager::NotifyObserversOfServiceEvent() {
  for (auto& observer : observers_) {
    observer.OnServiceUpdateEvent();
  }
}

void AdBlockSubscriptionServiceManager::AddObserver(
    AdBlockSubscriptionServiceManagerObserver* observer) {
  observers_.AddObserver(observer);
}

void AdBlockSubscriptionServiceManager::RemoveObserver(
    AdBlockSubscriptionServiceManagerObserver* observer) {
  observers_.RemoveObserver(observer);
}

}  // namespace brave_shields
