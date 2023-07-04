/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_COMMON_TIME_TIME_FORMATTING_UTIL_H_
#define BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_COMMON_TIME_TIME_FORMATTING_UTIL_H_

#include <string>

namespace base {
class Time;
}  // namespace base

namespace ads {

std::string LongFriendlyDateAndTime(base::Time time,
                                    bool use_sentence_style = true);

std::string FriendlyDateAndTime(base::Time time,
                                bool use_sentence_style = true);

std::string TimeAsTimestampString(base::Time time);

}  // namespace ads

#endif  // BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_COMMON_TIME_TIME_FORMATTING_UTIL_H_
