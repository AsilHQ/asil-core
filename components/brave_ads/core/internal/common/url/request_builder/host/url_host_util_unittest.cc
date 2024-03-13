/* Copyright (c) 2022 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "brave/components/brave_ads/core/internal/common/url/request_builder/host/url_host_util.h"

#include "brave/components/brave_ads/core/internal/common/unittest/unittest_base.h"
#include "brave/components/brave_ads/core/internal/global_state/global_state.h"
#include "brave/components/brave_ads/core/mojom/brave_ads.mojom.h"

// npm run test -- brave_unit_tests --filter=BraveAds*

namespace brave_ads {

class BraveAdsUrlHostUtilTest : public UnitTestBase {};

TEST_F(BraveAdsUrlHostUtilTest, GetStaticUrlHost) {
  // Arrange
  GlobalState::GetInstance()->Flags().environment_type =
      mojom::EnvironmentType::kProduction;

  // Act & Assert
  EXPECT_EQ("https://static.ads.kahf.co", GetStaticUrlHost());
}

TEST_F(BraveAdsUrlHostUtilTest, GetGeoUrlHost) {
  // Arrange
  GlobalState::GetInstance()->Flags().environment_type =
      mojom::EnvironmentType::kProduction;

  // Act & Assert
  EXPECT_EQ("https://geo.ads.kahf.co", GetGeoUrlHost());
}

TEST_F(BraveAdsUrlHostUtilTest, GetNonAnonymousUrlHost) {
  // Arrange
  GlobalState::GetInstance()->Flags().environment_type =
      mojom::EnvironmentType::kProduction;

  // Act & Assert
  EXPECT_EQ("https://mywallet.ads.kahf.co", GetNonAnonymousUrlHost());
}

TEST_F(BraveAdsUrlHostUtilTest, GetAnonymousUrlHost) {
  // Arrange
  GlobalState::GetInstance()->Flags().environment_type =
      mojom::EnvironmentType::kProduction;

  // Act & Assert
  EXPECT_EQ("https://anonymous.ads.kahf.co", GetAnonymousUrlHost());
}

TEST_F(BraveAdsUrlHostUtilTest, GetAnonymousSearchUrlHost) {
  // Arrange
  GlobalState::GetInstance()->Flags().environment_type =
      mojom::EnvironmentType::kProduction;

  // Act & Assert
  EXPECT_EQ("https://search.anonymous.ads.kahf.co",
            GetAnonymousSearchUrlHost());
}

}  // namespace brave_ads
