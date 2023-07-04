/* Copyright (c) 2020 The Asil Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * you can obtain one at http://mozilla.org/MPL/2.0/. */

#include "components/invalidation/impl/fcm_network_handler.h"

#define StartListening StartListening_ChromiumImpl
#include "src/components/invalidation/impl/fcm_network_handler.cc"
#undef StartListening

namespace invalidation {

void FCMNetworkHandler::StartListening() {
  return;
}

}  // namespace invalidation
