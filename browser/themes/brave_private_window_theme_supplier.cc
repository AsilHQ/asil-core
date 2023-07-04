/* Copyright (c) 2022 The Asil Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/browser/themes/brave_private_window_theme_supplier.h"

#include "brave/browser/ui/color/brave_color_mixer.h"
#include "ui/color/color_provider_manager.h"

BravePrivateWindowThemeSupplier::BravePrivateWindowThemeSupplier(
    bool private_window)
    : CustomThemeSupplier(ThemeType::kAutogenerated),
      for_private_window_(private_window) {}

BravePrivateWindowThemeSupplier::~BravePrivateWindowThemeSupplier() = default;

void BravePrivateWindowThemeSupplier::AddColorMixers(
    ui::ColorProvider* provider,
    const ui::ColorProviderManager::Key& key) const {
  for_private_window_ ? AddPrivateThemeColorMixer(provider, key)
                      : AddTorThemeColorMixer(provider, key);
  // Private/Tor uses same omnibox colors.
  AddBraveOmniboxPrivateThemeColorMixer(provider, key);
}
