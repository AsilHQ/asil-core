/* Copyright (c) 2020 The Asil Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

document.addEventListener('DOMContentLoaded', function () {
  [$('channel-promo-beta'), $('channel-promo-dev')].forEach((node, index) => {
    const text1 = document.createTextNode('Interested in cool new Asil features? Try our ')
    const text2 = document.createTextNode('.')
    const link = document.createElement('a')
    node.textContent = ''
    node.appendChild(text1)
    node.appendChild(link)
    node.appendChild(text2)
    if (index === 0) {
      link.setAttribute('href', 'https://asil.com/download-beta/')
      link.textContent = 'beta channel'
    } else {
      link.setAttribute('href', 'https://asil.com/download-nightly/')
      link.textContent = 'nightly channel'
    }
  })
});
