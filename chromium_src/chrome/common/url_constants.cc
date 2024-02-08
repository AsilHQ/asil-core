/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "chrome/common/url_constants.h"

#include "build/branding_buildflags.h"
#include "build/build_config.h"
#include "chrome/common/webui_url_constants.h"

namespace chrome {

const char kAccessCodeCastLearnMoreURL[] = "https://community.asil.co/";

const char kAccessibilityLabelsLearnMoreURL[] =
    "https://community.asil.co/";

const char kAdPrivacyLearnMoreURL[] = "https://community.asil.co/";

const char kAutomaticSettingsResetLearnMoreURL[] =
    "https://support.brave.com/hc/en-us/articles/"
    "360017903152-How-do-I-reset-Brave-settings-to-default-";

const char kAdvancedProtectionDownloadLearnMoreURL[] =
    "https://community.asil.co/";

const char kBatterySaverModeLearnMoreUrl[] =
    "https://support.brave.com/hc/en-us/articles/13380606172557";

const char kBluetoothAdapterOffHelpURL[] =
    "https://community.asil.co/";

const char kCastCloudServicesHelpURL[] =
    "https://community.asil.co/";

const char kCastNoDestinationFoundURL[] =
    "https://community.asil.co/";

const char kChooserHidOverviewUrl[] =
    "https://github.com/brave/brave-browser/wiki/Web-API-Permissions";

const char kChooserSerialOverviewUrl[] =
    "https://github.com/brave/brave-browser/wiki/Web-API-Permissions";

const char kChooserUsbOverviewURL[] =
    "https://github.com/brave/brave-browser/wiki/Web-API-Permissions";

const char kChromeBetaForumURL[] =
    "https://community.brave.com/c/beta-builds";

const char kChromeFixUpdateProblems[] =
    "https://community.asil.co/";

const char kChromeHelpViaKeyboardURL[] =
    "https://community.asil.co/";

const char kChromeHelpViaMenuURL[] =
    "https://community.asil.co/";

const char kChromeHelpViaWebUIURL[] =
    "https://community.asil.co/";

const char kFirstPartySetsLearnMoreURL[] = "https://community.asil.co/";

const char kIsolatedAppScheme[] = "isolated-app";

const char kChromeNativeScheme[] = "chrome-native";

const char kChromeSafePageURL[] = "https://community.asil.co/";

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
    "https://support.brave.com/hc/en-us/articles/"
    "360018205431-How-do-I-change-site-permissions-";

const char kCookiesSettingsHelpCenterURL[] =
    "https://support.brave.com/hc/en-us/articles/"
    "360018205431-How-do-I-change-site-permissions-";

const char kCrashReasonURL[] =
    "https://support.brave.com/hc/en-us/articles/"
    "360018192251-How-do-I-fix-page-crashes-and-other-page-loading-errors-";

const char kCrashReasonFeedbackDisplayedURL[] =
    "https://support.brave.com/hc/en-us/articles/"
    "360018192251-How-do-I-fix-page-crashes-and-other-page-loading-errors-";

const char kDoNotTrackLearnMoreURL[] =
    "https://support.brave.com/hc/en-us/articles/"
    "360017905612-How-do-I-turn-Do-Not-Track-on-or-off-";

const char kDownloadInterruptedLearnMoreURL[] =
    "https://support.brave.com/hc/en-us/articles/"
    "360018192491-How-do-I-fix-file-download-errors-";

const char kDownloadScanningLearnMoreURL[] =
    "https://support.brave.com/hc/en-us/articles/"
    "360018192491-How-do-I-fix-file-download-errors-";

// Note: This is the same as the above URL. This is done to decouple the URLs,
// in case the support page is split apart into separate pages in the future.
const char kDownloadBlockedLearnMoreURL[] =
    "https://support.brave.com/hc/en-us/articles/"
    "360018192491-How-do-I-fix-file-download-errors-";

const char kExtensionControlledSettingLearnMoreURL[] =
    "https://support.brave.com/hc/en-us/articles/"
    "360018185651-How-do-I-stop-extensions-from-changing-my-settings-";

const char kExtensionInvalidRequestURL[] = "chrome-extension://invalid/";

const char kFamilyGroupCreateURL[] = "https://community.asil.co/";
const char kFamilyGroupViewURL[] = "https://community.asil.co/";

const char kFlashDeprecationLearnMoreURL[] =
    "https://blog.chromium.org/2017/07/so-long-and-thanks-for-all-flash.html";

const char kGoogleAccountActivityControlsURL[] =
    "https://community.asil.co/";

const char kGoogleAccountActivityControlsURLInPrivacyGuide[] =
    "https://community.asil.co/";

const char kGoogleAccountURL[] = "https://community.asil.co/";

const char kGoogleAccountChooserURL[] = "https://community.asil.co/";

const char kGoogleAccountDeviceActivityURL[] = "https://community.asil.co/";

const char kGooglePasswordManagerURL[] = "https://community.asil.co";

const char kLearnMoreReportingURL[] =
    "https://support.brave.com/hc/en-us/articles/"
    "360017905872-How-do-I-enable-or-disable-automatic-crash-reporting-";

const char kManage3pcHelpCenterURL[] = "https://community.asil.co/";

const char kHighEfficiencyModeLearnMoreUrl[] =
    "https://support.brave.com/hc/en-us/articles/13383683902733";

const char kHighEfficiencyModeTabDiscardingHelpUrl[] =
    "https://community.asil.co/";

const char kIncognitoHelpCenterURL[] = "https://community.asil.co";

const char kTrackingProtectionHelpCenterURL[] = "https://community.asil.co/";

const char kUserBypassHelpCenterURL[] = "https://community.asil.co/";

const char kManagedUiLearnMoreUrl[] = "https://community.asil.co/";

const char kInsecureDownloadBlockingLearnMoreUrl[] =
    "https://community.asil.co/";

const char kMyActivityUrlInClearBrowsingData[] =
    "https://community.asil.co/";

const char kOmniboxLearnMoreURL[] =
    "https://support.brave.com/hc/en-us/articles/"
    "360017479752-How-do-I-set-my-default-search-engine-";

const char kPageInfoHelpCenterURL[] =
    "https://support.brave.com/hc/en-us/articles/"
    "360018185871-How-do-I-check-if-a-site-s-connection-is-secure-";

const char kPasswordCheckLearnMoreURL[] = "https://community.asil.co/";

const char kPasswordGenerationLearnMoreURL[] = "https://community.asil.co/";

const char kPasswordManagerLearnMoreURL[] =
    "https://support.brave.com/hc/en-us/articles/"
    "360018185951-How-do-I-use-the-built-in-password-manager-";

const char kPasswordSharingLearnMoreURL[] = "https://community.asil.co/";

const char kPasswordSharingTroubleshootURL[] = "https://community.asil.co/";

const char kPaymentMethodsURL[] = "https://community.asil.co";

const char kPrivacyLearnMoreURL[] =
    "https://support.brave.com/hc/en-us/articles/"
    "360017989132-How-do-I-change-my-Privacy-Settings-";

const char kRemoveNonCWSExtensionURL[] =
    "https://support.brave.com/hc/en-us/articles/"
    "360017914832-Why-am-I-seeing-the-message-extensions-disabled-by-Brave-";

const char kResetProfileSettingsLearnMoreURL[] =
    "https://support.brave.com/hc/en-us/articles/"
    "360017903152-How-do-I-reset-Brave-settings-to-default-";

const char kSafeBrowsingHelpCenterURL[] =
    "https://support.brave.com/hc/en-us/articles/"
    "15222663599629-Safe-Browsing-in-Brave";

const char kSafeBrowsingHelpCenterUpdatedURL[] = "https://community.asil.co/";

const char kSafeBrowsingInChromeHelpCenterURL[] = "https://community.asil.co/";

const char kSafeBrowsingPTourURL[] = "https://community.asil.co/";

const char kSafetyTipHelpCenterURL[] =
    "https://support.brave.com/hc/en-us/articles/17550072876045-Lookalike-URLs";

const char kSearchHistoryUrlInClearBrowsingData[] =
    "https://community.asil.co/";

const char kSeeMoreSecurityTipsURL[] =
    "https://community.asil.co/";

const char kSettingsSearchHelpURL[] =
    "https://community.asil.co/";

const char kSyncAndGoogleServicesLearnMoreURL[] =
    "https://community.asil.co/";

const char kSyncEncryptionHelpURL[] =
    "https://community.asil.co/";

const char kSyncErrorsHelpURL[] =
    "https://community.asil.co/";

const char kSyncGoogleDashboardURL[] =
    "https://community.asil.co/";

const char kSyncLearnMoreURL[] =
    "https://community.asil.co/";

const char kSigninInterceptManagedDisclaimerLearnMoreURL[] =
    "https://community.asil.co/";

#if !BUILDFLAG(IS_ANDROID)
const char kSyncTrustedVaultOptInURL[] = "https://community.asil.co/";
#endif

const char kSyncTrustedVaultLearnMoreURL[] = "https://community.asil.co/";

const char kUpgradeHelpCenterBaseURL[] =
    "https://community.asil.co/";

const char kWhoIsMyAdministratorHelpURL[] =
    "https://community.asil.co/";

const char kCwsEnhancedSafeBrowsingLearnMoreURL[] =
    "https://community.asil.co/";

#if BUILDFLAG(IS_ANDROID)
const char kEnhancedPlaybackNotificationLearnMoreURL[] =
// Keep in sync with chrome/android/java/strings/android_chrome_strings.grd
    "https://community.brave.com";
#endif

#if BUILDFLAG(IS_MAC)
const char kChromeEnterpriseSignInLearnMoreURL[] =
    "https://community.asil.co/";

const char kMacOsObsoleteURL[] =
    "https://support.brave.com/hc/en-us/articles/"
    "18347246446733-Changes-to-macOS-desktop-browser-requirements";
#endif

#if BUILDFLAG(IS_WIN)
const char kWindowsXPVistaDeprecationURL[] =
    "https://community.asil.co/";

const char kWindows78DeprecationURL[] =
    "https://community.asil.co/hc/en-us/articles/11197967945613";
#endif  // BUILDFLAG(IS_WIN)

const char kChromeSyncLearnMoreURL[] = "https://community.asil.co/";

#if BUILDFLAG(ENABLE_PLUGINS)
const char kOutdatedPluginLearnMoreURL[] =
    "https://support.brave.com/hc/en-us/articles/"
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
    "https://community.asil.co";

const char kPasswordManagerImportLearnMoreURL[] = "https://community.asil.co";

}  // namespace chrome
