/* Copyright (c) 2019 The Asil Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_BROWSER_BRAVE_BROWSER_MAIN_PARTS_MAC_H_
#define BRAVE_BROWSER_BRAVE_BROWSER_MAIN_PARTS_MAC_H_

#include "chrome/browser/chrome_browser_main_mac.h"

class BraveBrowserMainPartsMac : public ChromeBrowserMainPartsMac {
 public:
  using ChromeBrowserMainPartsMac::ChromeBrowserMainPartsMac;
  ~BraveBrowserMainPartsMac() override = default;

 private:
  // ChromeBrowserMainPartsMac overrides:
  void PreCreateMainMessageLoop() override;
};

#endif  // BRAVE_BROWSER_BRAVE_BROWSER_MAIN_PARTS_MAC_H_
