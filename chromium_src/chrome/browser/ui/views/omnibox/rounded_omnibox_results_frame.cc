/* Copyright (c) 2022 The Asil Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "src/chrome/browser/ui/views/omnibox/rounded_omnibox_results_frame.cc"

// static
int RoundedOmniboxResultsFrame::GetShadowElevation() {
  // Expose a constant defined in cc file.
  return kElevation;
}
