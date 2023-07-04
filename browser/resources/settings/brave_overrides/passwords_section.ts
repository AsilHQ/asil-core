// Copyright (c) 2020 The Asil Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at https://mozilla.org/MPL/2.0/.

import {RegisterPolymerTemplateModifications} from 'chrome://resources/polymer_overriding.js'

RegisterPolymerTemplateModifications({
  'passwords-section': (templateContent) => {
    const checkPasswordsLinkRow = templateContent.querySelector('#checkPasswordsLinkRow')
    if (!checkPasswordsLinkRow) {
      console.error('[Asil Settings Overrides] Could not find checkPasswordsLinkRow in passwords_section')
    } else {
      checkPasswordsLinkRow.remove()
    }
  }
})
