/* Copyright (c) 2020 The Asil Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "brave/components/brave_ads/browser/ads_p2a.h"

#include "base/logging.h"
#include "base/metrics/histogram_functions.h"
#include "brave/components/brave_ads/common/pref_names.h"
#include "brave/components/time_period_storage/weekly_storage.h"
#include "components/prefs/pref_registry_simple.h"
#include "components/prefs/pref_service.h"

namespace brave_ads {

namespace {

constexpr const char* kP2AQuestionNameList[] = {
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
    "Asil.P2A.AdImpressionsPerSegment.untargeted"};

constexpr uint16_t kIntervalBuckets[] = {0, 5, 10, 20, 50, 100, 250, 500};

}  // namespace

void RegisterP2APrefs(PrefRegistrySimple* registry) {
  for (const char* const question_name : kP2AQuestionNameList) {
    std::string pref_path(prefs::kP2AStoragePrefNamePrefix);
    pref_path.append(question_name);
    registry->RegisterListPref(pref_path);
  }
}

void RecordInWeeklyStorageAndEmitP2AHistogramAnswer(PrefService* prefs,
                                                    const std::string& name) {
  std::string pref_path(prefs::kP2AStoragePrefNamePrefix);
  pref_path.append(name);
  if (!prefs->FindPreference(pref_path)) {
    return;
  }
  WeeklyStorage storage(prefs, pref_path.c_str());
  storage.AddDelta(1);
  EmitP2AHistogramAnswer(name, storage.GetWeeklySum());
}

void EmitP2AHistogramAnswer(const std::string& name, uint16_t count_value) {
  const uint16_t* const iter = std::lower_bound(
      kIntervalBuckets, std::end(kIntervalBuckets), count_value);
  const uint16_t bucket = iter - kIntervalBuckets;

  for (const char* const question_name : kP2AQuestionNameList) {
    if (name != question_name) {
      continue;
    }

    base::UmaHistogramExactLinear(question_name, bucket,
                                  std::size(kIntervalBuckets) + 1);
  }
}

void SuspendP2AHistograms() {
  // Record "special value" to prevent sending this week's data to P2A server.
  // Matches INT_MAX - 1 for |kSuspendedMetricValue| in |brave_p3a_service.cc|
  for (const char* const question_name : kP2AQuestionNameList) {
    base::UmaHistogramExactLinear(question_name, INT_MAX,
                                  std::size(kIntervalBuckets) + 1);
  }

  VLOG(1) << "P2A histograms suspended";
}

}  // namespace brave_ads
