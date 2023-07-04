/* Copyright (c) 2019 The Asil Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "chrome/common/url_constants.h"

#include "build/branding_buildflags.h"
#include "build/build_config.h"
#include "chrome/common/webui_url_constants.h"

namespace chrome {

const char kAccessCodeCastLearnMoreURL[] = "https://support.asil.com/";

const char kAccessibilityLabelsLearnMoreURL[] =
    "https://support.asil.com/";

const char kAutomaticSettingsResetLearnMoreURL[] =
    "https://support.asil.com/hc/en-us/articles/"
    "360017903152-How-do-I-reset-Asil-settings-to-default-";

const char kAdvancedProtectionDownloadLearnMoreURL[] =
    "https://support.asil.com/";

const char kBatterySaverModeLearnMoreUrl[] = "https://support.asil.com/";

const char kBluetoothAdapterOffHelpURL[] =
    "https://support.asil.com/";

const char kCastCloudServicesHelpURL[] =
    "https://support.asil.com/";

const char kCastNoDestinationFoundURL[] =
    "https://support.asil.com/";

const char kChooserHidOverviewUrl[] =
    "https://github.com/brave/brave-browser/wiki/Web-API-Permissions";

const char kChooserSerialOverviewUrl[] =
    "https://github.com/brave/brave-browser/wiki/Web-API-Permissions";

const char kChooserUsbOverviewURL[] =
    "https://github.com/brave/brave-browser/wiki/Web-API-Permissions";

const char kChromeBetaForumURL[] =
    "https://community.asil.com/c/beta-builds";

const char kChromeFixUpdateProblems[] =
    "https://support.asil.com/";

const char kChromeHelpViaKeyboardURL[] =
    "https://support.asil.com/";

const char kChromeHelpViaMenuURL[] =
    "https://support.asil.com/";

const char kChromeHelpViaWebUIURL[] =
    "https://support.asil.com/";

const char kIsolatedAppScheme[] = "isolated-app";

const char kChromeNativeScheme[] = "chrome-native";

const char kChromeSearchLocalNtpHost[] = "local-ntp";

const char kChromeSearchMostVisitedHost[] = "most-visited";
const char kChromeSearchMostVisitedUrl[] = "chrome-search://most-visited/";

const char kChromeUIUntrustedNewTabPageBackgroundUrl[] =
    "chrome-untrusted://new-tab-page/background.jpg";
const char kChromeUIUntrustedNewTabPageBackgroundFilename[] = "background.jpg";

const char kChromeSearchRemoteNtpHost[] = "remote-ntp";

const char kChromeSearchScheme[] = "chrome-search";

const char kChromeUIUntrustedNewTabPageUrl[] =
    "chrome-untrusted://new-tab-page/";

const char kChromiumProjectURL[] = "https://github.com/brave/brave-browser/";

const char kContentSettingsExceptionsLearnMoreURL[] =
    "https://support.asil.com/hc/en-us/articles/"
    "360018205431-How-do-I-change-site-permissions-";

const char kCookiesSettingsHelpCenterURL[] =
    "https://support.asil.com/hc/en-us/articles/"
    "360018205431-How-do-I-change-site-permissions-";

const char kCrashReasonURL[] =
    "https://support.asil.com/hc/en-us/articles/"
    "360018192251-How-do-I-fix-page-crashes-and-other-page-loading-errors-";

const char kCrashReasonFeedbackDisplayedURL[] =
    "https://support.asil.com/hc/en-us/articles/"
    "360018192251-How-do-I-fix-page-crashes-and-other-page-loading-errors-";

const char kDoNotTrackLearnMoreURL[] =
    "https://support.asil.com/hc/en-us/articles/"
    "360017905612-How-do-I-turn-Do-Not-Track-on-or-off-";

const char kDownloadInterruptedLearnMoreURL[] =
    "https://support.asil.com/hc/en-us/articles/"
    "360018192491-How-do-I-fix-file-download-errors-";

const char kDownloadScanningLearnMoreURL[] =
    "https://support.asil.com/hc/en-us/articles/"
    "360018192491-How-do-I-fix-file-download-errors-";

const char kExtensionControlledSettingLearnMoreURL[] =
    "https://support.asil.com/hc/en-us/articles/"
    "360018185651-How-do-I-stop-extensions-from-changing-my-settings-";

const char kExtensionInvalidRequestURL[] = "chrome-extension://invalid/";

const char kFlashDeprecationLearnMoreURL[] =
    "https://blog.chromium.org/2017/07/so-long-and-thanks-for-all-flash.html";

const char kGoogleAccountActivityControlsURL[] =
    "https://support.asil.com/";

const char kGoogleAccountActivityControlsURLInPrivacyGuide[] =
    "https://support.asil.com/";

const char kGoogleAccountURL[] = "https://support.asil.com/";

const char kGoogleAccountChooserURL[] = "https://support.asil.com/";

const char kGoogleAccountDeviceActivityURL[] = "https://support.asil.com/";

const char kGooglePasswordManagerURL[] = "https://support.asil.com";

const char kLearnMoreReportingURL[] =
    "https://support.asil.com/hc/en-us/articles/"
    "360017905872-How-do-I-enable-or-disable-automatic-crash-reporting-";

const char kHighEfficiencyModeLearnMoreUrl[] = "https://support.asil.com/";

const char kManagedUiLearnMoreUrl[] = "https://support.asil.com/";

const char kInsecureDownloadBlockingLearnMoreUrl[] =
    "https://support.asil.com/";

const char kMyActivityUrlInClearBrowsingData[] =
    "https://support.asil.com/";

const char kOmniboxLearnMoreURL[] =
    "https://support.asil.com/hc/en-us/articles/"
    "360017479752-How-do-I-set-my-default-search-engine-";

const char kPageInfoHelpCenterURL[] =
    "https://support.asil.com/hc/en-us/articles/"
    "360018185871-How-do-I-check-if-a-site-s-connection-is-secure-";

const char kPasswordCheckLearnMoreURL[] = "https://support.asil.com/";

const char kPasswordGenerationLearnMoreURL[] = "https://support.asil.com/";

const char kPasswordManagerLearnMoreURL[] =
    "https://support.asil.com/hc/en-us/articles/"
    "360018185951-How-do-I-use-the-built-in-password-manager-";

const char kPaymentMethodsURL[] = "https://support.asil.com";

const char kPrivacyLearnMoreURL[] =
    "https://support.asil.com/hc/en-us/articles/"
    "360017989132-How-do-I-change-my-Privacy-Settings-";

const char kRemoveNonCWSExtensionURL[] =
    "https://support.asil.com/hc/en-us/articles/"
    "360017914832-Why-am-I-seeing-the-message-extensions-disabled-by-Asil-";

const char kResetProfileSettingsLearnMoreURL[] =
    "https://support.asil.com/hc/en-us/articles/"
    "360017903152-How-do-I-reset-Asil-settings-to-default-";

const char kSafeBrowsingHelpCenterURL[] =
    "https://support.asil.com/";

const char kSafetyTipHelpCenterURL[] =
    "https://support.asil.com/";

const char kSearchHistoryUrlInClearBrowsingData[] =
    "https://support.asil.com/";

const char kSeeMoreSecurityTipsURL[] =
    "https://support.asil.com/";

const char kSettingsSearchHelpURL[] =
    "https://support.asil.com/";

const char kSyncAndGoogleServicesLearnMoreURL[] =
    "https://support.asil.com/";

const char kSyncEncryptionHelpURL[] =
    "https://support.asil.com/";

const char kSyncErrorsHelpURL[] =
    "https://support.asil.com/";

const char kSyncGoogleDashboardURL[] =
    "https://support.asil.com/";

const char kSyncLearnMoreURL[] =
    "https://support.asil.com/";

const char kSigninInterceptManagedDisclaimerLearnMoreURL[] =
    "https://support.asil.com/";

#if !BUILDFLAG(IS_ANDROID)
const char kSyncTrustedVaultOptInURL[] = "https://support.asil.com/";
#endif

const char kSyncTrustedVaultLearnMoreURL[] = "https://support.asil.com/";

const char kUpgradeHelpCenterBaseURL[] =
    "https://support.asil.com/hc/en-us/articles/"
    "360025390311-How-do-I-download-and-install-Asil-";

const char kWhoIsMyAdministratorHelpURL[] =
    "https://support.asil.com/";

const char kCwsEnhancedSafeBrowsingLearnMoreURL[] =
    "https://support.asil.com/";

#if BUILDFLAG(IS_ANDROID)
const char kEnhancedPlaybackNotificationLearnMoreURL[] =
// Keep in sync with chrome/android/java/strings/android_chrome_strings.grd
    "https://community.asil.com";
#endif

#if BUILDFLAG(IS_MAC)
const char kChromeEnterpriseSignInLearnMoreURL[] =
    "https://support.asil.com/";

const char kMacOsObsoleteURL[] =
    "https://support.asil.com/hc/en-us/articles/"
    "360025390311-How-do-I-download-and-install-Asil-";
#endif

#if BUILDFLAG(IS_WIN)
const char kChromeCleanerLearnMoreURL[] =
    "https://support.asil.com/hc/en-us/articles/"
    "360017884152-How-do-I-remove-unwanted-ads-pop-ups-malware-";

const char kWindowsXPVistaDeprecationURL[] =
    "https://support.asil.com/";

const char kWindows78DeprecationURL[] =
    "https://support.asil.com/hc/en-us/articles/11197967945613";
#endif  // BUILDFLAG(IS_WIN)

const char kChromeSyncLearnMoreURL[] = "https://support.asil.com/";

#if BUILDFLAG(ENABLE_PLUGINS)
const char kOutdatedPluginLearnMoreURL[] =
    "https://support.asil.com/hc/en-us/articles/"
    "360018163151-How-do-I-manage-Flash-audio-video-";
#endif

#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
const char kChromeAppsDeprecationLearnMoreURL[] =
    "https://support.google.com/chrome/?p=chrome_app_deprecation";
#endif

#if BUILDFLAG(CHROME_ROOT_STORE_SUPPORTED)
// TODO(b/1339340): add help center link when help center link is created.
const char kChromeRootStoreSettingsHelpCenterURL[] =
    "https://chromium.googlesource.com/chromium/src/+/main/net/data/ssl/"
    "chrome_root_store/root_store.md";
#endif

const char kAddressesAndPaymentMethodsLearnMoreURL[] =
    "https://support.asil.com";

}  // namespace chrome
