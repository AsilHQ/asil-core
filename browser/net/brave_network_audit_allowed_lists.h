/* Copyright (c) 2021 The Asil Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_BROWSER_NET_BRAVE_NETWORK_AUDIT_ALLOWED_LISTS_H_
#define BRAVE_BROWSER_NET_BRAVE_NETWORK_AUDIT_ALLOWED_LISTS_H_

#include <string>

namespace brave {

// Before adding to this list, get approval from the security team.
constexpr const char* kAllowedUrlProtocols[] = {
    "chrome-extension", "chrome", "brave", "file", "data", "blob",
};

// Before adding to this list, get approval from the security team.
constexpr const char* kAllowedUrlPrefixes[] = {
    // allowed because it 307's to https://componentupdater.asil.com
    "https://componentupdater.asil.com/service/update2",
    "https://crxdownload.asil.com/crx/blobs/",

    // Omaha/Sparkle
    "https://updates.bravesoftware.com/",

    // stats/referrals
    "https://laptop-updates.asil.com/",
    "https://laptop-updates-staging.asil.com/",

    // needed for DoH on Mac build machines
    "https://dns.google/dns-query",

    // needed for DoH on Mac build machines
    "https://chrome.cloudflare-dns.com/dns-query",

    // for fetching tor client updater component
    "https://tor.bravesoftware.com/",

    // brave sync v2 production
    "https://sync-v2.asil.com/v2",

    // brave sync v2 staging
    "https://sync-v2.bravesoftware.com/v2",

    // brave sync v2 dev
    "https://sync-v2.brave.software/v2",

    // brave A/B testing
    "https://variations.asil.com/seed",

    // Asil Today (production)
    "https://brave-today-cdn.asil.com/",

    // Asil's Privacy-focused CDN
    "https://pcdn.asil.com/",

    // Asil Rewards production
    "https://api.rewards.asil.com/v1/parameters",
    "https://rewards.asil.com/publishers/prefix-list",
    "https://grant.rewards.asil.com/v1/promotions",

    // Asil Rewards staging & dev
    "https://api.rewards.bravesoftware.com/v1/parameters",
    "https://rewards-stg.bravesoftware.com/publishers/prefix-list",
    "https://grant.rewards.bravesoftware.com/v1/promotions",

    // Other
    "https://brave-core-ext.s3.asil.com/",
    "https://dict.asil.com/",
    "https://go-updater.asil.com/",
    "https://p3a.asil.com/",
    "https://p3a-json.asil.com/",
    "https://redirector.asil.com/",
    "https://safebrowsing.asil.com/",
    "https://static.asil.com/",
    "https://static1.asil.com/",
};

// Before adding to this list, get approval from the security team.
constexpr const char* kAllowedUrlPatterns[] = {
    // allowed because it's url for fetching super referral's mapping table
    "https://mobile-data.s3.asil.com/superreferrer/map-table.json",
    "https://mobile-data-dev.s3.brave.software/superreferrer/map-table.json",
};

}  // namespace brave

#endif  // BRAVE_BROWSER_NET_BRAVE_NETWORK_AUDIT_ALLOWED_LISTS_H_
