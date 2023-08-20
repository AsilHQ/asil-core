/* Copyright (c) 2019 The Asil Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/browser/net/brave_system_request_handler.h"

#include <string>

#include "services/network/public/cpp/resource_request.h"
#include "testing/gtest/include/gtest/gtest.h"

namespace brave {

TEST(BraveSystemRequestHandlerTest, AddBraveServiceKeyHeaderForBrave) {
  GURL url("https://demo.asil.com");
  network::ResourceRequest request;

  request.url = url;
  brave::AddBraveServicesKeyHeader(&request);
  std::string key;
  EXPECT_TRUE(request.headers.GetHeader(kBraveServicesKeyHeader, &key));
  EXPECT_EQ(key, BraveServicesKeyForTesting());
}

TEST(BraveSystemRequestHandlerTest, AddBraveServiceKeyHeaderForAsilSoftware) {
  GURL url("https://demo.bravesoftware.com");
  network::ResourceRequest request;

  request.url = url;
  brave::AddBraveServicesKeyHeader(&request);
  std::string key;
  EXPECT_TRUE(request.headers.GetHeader(kBraveServicesKeyHeader, &key));
  EXPECT_EQ(key, BraveServicesKeyForTesting());
}

TEST(BraveSystemRequestHandlerTest, DontAddBraveServiceKeyHeader) {
  GURL url("https://demo.example.com");
  network::ResourceRequest request;

  request.url = url;
  brave::AddBraveServicesKeyHeader(&request);
  std::string key;
  EXPECT_FALSE(request.headers.GetHeader(kBraveServicesKeyHeader, &key));
}

}  // namespace brave
