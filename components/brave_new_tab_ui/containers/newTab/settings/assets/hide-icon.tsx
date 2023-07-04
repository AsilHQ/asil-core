/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

import * as React from 'react'

export default class HideIcon extends React.PureComponent {
  render () {
    return (
      <svg width={'100%'} height={'100%'} viewBox={'0 0 19 17'} xmlns={'http://www.w3.org/2000/svg'}>
        <path d={'M2.538 16.53a.746.746 0 01-1.06 0 .749.749 0 010-1.06l2.31-2.311C1.338 11.584.5 9.405.5 8.499c0-1.958 3.154-6.75 9-6.75 2.252 0 3.671.684 4.457 1.242L16.477.47a.75.75 0 111.06 1.06l-15 15zm4.946-7.067l2.984-2.984A2.243 2.243 0 009.5 6.25c-1.24 0-2.25 1.01-2.25 2.25 0 .338.09.662.234.963zM9.5 3.25C4.412 3.25 2 7.461 2 8.5c0 .334.535 2.198 2.882 3.564l1.529-1.527c-.053-.05-.114-.086-.152-.15A3.754 3.754 0 019.5 4.75c.74 0 1.454.226 2.064.632l1.306-1.307c-.619-.382-1.689-.826-3.371-.826zm0 8.999a.75.75 0 01-.049-1.498 2.473 2.473 0 002.3-2.3.75.75 0 111.497.098 3.979 3.979 0 01-3.7 3.7H9.5zm-2.07 1.252c.655.164 1.351.248 2.07.248 5.088 0 7.5-4.21 7.5-5.25 0-.313-.325-1.332-1.329-2.479a.75.75 0 111.129-.988c1.032 1.18 1.7 2.541 1.7 3.468 0 1.958-3.154 6.75-9 6.75a9.98 9.98 0 01-2.436-.295.75.75 0 11.367-1.454z'} fill={'#FFFFFF'} fillRule={'evenodd'}/>
      </svg>
    )
  }
}
