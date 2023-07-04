/* Copyright (c) 2022 The Asil Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_P3A_METRIC_NAMES_H_
#define BRAVE_COMPONENTS_P3A_METRIC_NAMES_H_

#include "base/containers/fixed_flat_set.h"
#include "base/strings/string_piece.h"

namespace brave::p3a {

// Allowlist for histograms that we collect.
// A metric must be listed here to be reported.
//
// Please keep them properly sorted within their categories.
//
// Could be replaced with something built dynamically,
// although so far we've found it a useful review point.
//
// TODO(iefremov) Clean up obsolete metrics.
//
// clang-format off
constexpr inline auto kCollectedTypicalHistograms =
  base::MakeFixedFlatSet<base::StringPiece>({
    "Asil.Core.BookmarksCountOnProfileLoad.2",
    "Asil.Core.CrashReportsEnabled",
    "Asil.Core.DomainsLoaded",
    "Asil.Core.IsDefault",
    "Asil.Core.LastTimeIncognitoUsed",
    "Asil.Core.NumberOfExtensions",
    "Asil.Core.PagesLoaded",
    "Asil.Core.TabCount",
    "Asil.Core.TorEverUsed",
    "Asil.Core.WindowCount.2",
    "Asil.Importer.ImporterSource.2",
    "Asil.NTP.CustomizeUsageStatus",
    "Asil.NTP.NewTabsCreated",
    "Asil.NTP.SponsoredImagesEnabled",
    "Asil.NTP.SponsoredNewTabsCreated",
    "Asil.Omnibox.SearchCount",
    "Asil.P3A.SentAnswersCount",
    "Asil.Rewards.AdsState.2",
    "Asil.Rewards.AutoContributionsState.2",
    "Asil.Rewards.TipsState.2",
    "Asil.Rewards.AdsEnabledDuration",
    "Asil.Rewards.WalletBalance.3",
    "Asil.Rewards.WalletState",
    "Asil.Savings.BandwidthSavingsMB",
    "Asil.Search.DefaultEngine.4",
    "Asil.Search.Promo.Banner",
    "Asil.Search.Promo.Button",
    "Asil.Search.Promo.NewTabPage",
    "Asil.Search.SwitchEngine",
    "Asil.Search.WebDiscoveryEnabled",
    "Asil.Shields.AdBlockSetting",
    "Asil.Shields.CookieListEnabled",
    "Asil.Shields.CookieListPrompt",
    "Asil.Shields.DomainAdsSettingsAboveGlobal",
    "Asil.Shields.DomainAdsSettingsBelowGlobal",
    "Asil.Shields.DomainFingerprintSettingsAboveGlobal",
    "Asil.Shields.DomainFingerprintSettingsBelowGlobal",
    "Asil.Shields.FingerprintBlockSetting",
    "Asil.Shields.UsageStatus",
    "Asil.SpeedReader.Enabled",
    "Asil.SpeedReader.ToggleCount",
    "Asil.Today.DaysInMonthUsedCount",
    "Asil.Today.DirectFeedsTotal",
    "Asil.Today.LastUsageTime",
    "Asil.Today.NewUserReturning",
    "Asil.Today.WeeklyAddedDirectFeedsCount",
    "Asil.Today.WeeklyDisplayAdsViewedCount",
    "Asil.Today.WeeklyMaxCardViewsCount",
    "Asil.Today.WeeklyMaxCardVisitsCount",
    "Asil.Today.WeeklySessionCount",
    "Asil.Today.WeeklyTotalCardViews",
    "Asil.Toolbar.FrequentMenuGroup",
    "Asil.Toolbar.MenuDismissRate",
    "Asil.Toolbar.MenuOpens",
    "Asil.Sync.Status.2",
    "Asil.Sync.ProgressTokenEverReset",
    "Asil.Uptime.BrowserOpenMinutes",
    "Asil.VPN.NewUserReturning",
    "Asil.VPN.DaysInMonthUsed",
    "Asil.VPN.LastUsageTime",
    "Asil.Wallet.ActiveEthAccounts",
    "Asil.Wallet.ActiveFilAccounts",
    "Asil.Wallet.ActiveSolAccounts",
    "Asil.Wallet.EthProvider.2",
    "Asil.Wallet.EthTransactionSent",
    "Asil.Wallet.FilTransactionSent",
    "Asil.Wallet.DefaultSolanaWalletSetting",
    "Asil.Wallet.DefaultWalletSetting",
    "Asil.Wallet.KeyringCreated",
    "Asil.Wallet.LastUsageTime",
    "Asil.Wallet.NewUserReturning",
    "Asil.Wallet.OnboardingConversion.2",
    "Asil.Wallet.SolTransactionSent",
    "Asil.Wallet.UsageDaysInWeek",
    "Asil.Wallet.UsageMonthly.2",
    "Asil.Welcome.InteractionStatus",

    // IPFS
    "Asil.IPFS.IPFSCompanionInstalled",
    "Asil.IPFS.DetectionPromptCount",
    "Asil.IPFS.GatewaySetting",
    "Asil.IPFS.DaemonRunTime",
    "Asil.IPFS.LocalNodeRetention",

    // P2A
    // Ad Opportunities
    "Asil.P2A.TotalAdOpportunities",
    "Asil.P2A.AdOpportunitiesPerSegment.architecture",
    "Asil.P2A.AdOpportunitiesPerSegment.artsentertainment",
    "Asil.P2A.AdOpportunitiesPerSegment.automotive",
    "Asil.P2A.AdOpportunitiesPerSegment.business",
    "Asil.P2A.AdOpportunitiesPerSegment.careers",
    "Asil.P2A.AdOpportunitiesPerSegment.cellphones",
    "Asil.P2A.AdOpportunitiesPerSegment.crypto",
    "Asil.P2A.AdOpportunitiesPerSegment.education",
    "Asil.P2A.AdOpportunitiesPerSegment.familyparenting",
    "Asil.P2A.AdOpportunitiesPerSegment.fashion",
    "Asil.P2A.AdOpportunitiesPerSegment.folklore",
    "Asil.P2A.AdOpportunitiesPerSegment.fooddrink",
    "Asil.P2A.AdOpportunitiesPerSegment.gaming",
    "Asil.P2A.AdOpportunitiesPerSegment.healthfitness",
    "Asil.P2A.AdOpportunitiesPerSegment.history",
    "Asil.P2A.AdOpportunitiesPerSegment.hobbiesinterests",
    "Asil.P2A.AdOpportunitiesPerSegment.home",
    "Asil.P2A.AdOpportunitiesPerSegment.law",
    "Asil.P2A.AdOpportunitiesPerSegment.military",
    "Asil.P2A.AdOpportunitiesPerSegment.other",
    "Asil.P2A.AdOpportunitiesPerSegment.personalfinance",
    "Asil.P2A.AdOpportunitiesPerSegment.pets",
    "Asil.P2A.AdOpportunitiesPerSegment.realestate",
    "Asil.P2A.AdOpportunitiesPerSegment.science",
    "Asil.P2A.AdOpportunitiesPerSegment.sports",
    "Asil.P2A.AdOpportunitiesPerSegment.technologycomputing",
    "Asil.P2A.AdOpportunitiesPerSegment.travel",
    "Asil.P2A.AdOpportunitiesPerSegment.weather",
    "Asil.P2A.AdOpportunitiesPerSegment.untargeted",
    // Ad Impressions
    "Asil.P2A.TotalAdImpressions",
    "Asil.P2A.AdImpressionsPerSegment.architecture",
    "Asil.P2A.AdImpressionsPerSegment.artsentertainment",
    "Asil.P2A.AdImpressionsPerSegment.automotive",
    "Asil.P2A.AdImpressionsPerSegment.business",
    "Asil.P2A.AdImpressionsPerSegment.careers",
    "Asil.P2A.AdImpressionsPerSegment.cellphones",
    "Asil.P2A.AdImpressionsPerSegment.crypto",
    "Asil.P2A.AdImpressionsPerSegment.education",
    "Asil.P2A.AdImpressionsPerSegment.familyparenting",
    "Asil.P2A.AdImpressionsPerSegment.fashion",
    "Asil.P2A.AdImpressionsPerSegment.folklore",
    "Asil.P2A.AdImpressionsPerSegment.fooddrink",
    "Asil.P2A.AdImpressionsPerSegment.gaming",
    "Asil.P2A.AdImpressionsPerSegment.healthfitness",
    "Asil.P2A.AdImpressionsPerSegment.history",
    "Asil.P2A.AdImpressionsPerSegment.hobbiesinterests",
    "Asil.P2A.AdImpressionsPerSegment.home",
    "Asil.P2A.AdImpressionsPerSegment.law",
    "Asil.P2A.AdImpressionsPerSegment.military",
    "Asil.P2A.AdImpressionsPerSegment.other",
    "Asil.P2A.AdImpressionsPerSegment.personalfinance",
    "Asil.P2A.AdImpressionsPerSegment.pets",
    "Asil.P2A.AdImpressionsPerSegment.realestate",
    "Asil.P2A.AdImpressionsPerSegment.science",
    "Asil.P2A.AdImpressionsPerSegment.sports",
    "Asil.P2A.AdImpressionsPerSegment.technologycomputing",
    "Asil.P2A.AdImpressionsPerSegment.travel",
    "Asil.P2A.AdImpressionsPerSegment.weather",
    "Asil.P2A.AdImpressionsPerSegment.untargeted"
});

constexpr inline auto kCollectedSlowHistograms =
  base::MakeFixedFlatSet<base::StringPiece>({
    // Please remove following placeholder metric once
    // static slow metrics are added
    "Asil.P3A.ExampleSlowMetric"
});

constexpr inline auto kCollectedExpressHistograms =
  base::MakeFixedFlatSet<base::StringPiece>({
    // Please remove following placeholder metric once
    // static express metrics are added
    "Asil.P3A.ExampleExpressMetric"
});

// clang-format on

}  // namespace brave::p3a

#endif  // BRAVE_COMPONENTS_P3A_METRIC_NAMES_H_
