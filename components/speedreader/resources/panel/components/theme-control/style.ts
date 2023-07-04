// Copyright (c) 2022 The Asil Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at https://mozilla.org/MPL/2.0/.
import styled from 'styled-components'

export const Box = styled.div`
  display: grid;
  grid-template-columns: 1fr 1fr 1fr;
  grid-gap: 6px;

  .chip {
    --border-color: transparent;

    margin: 0 auto;
    width: auto;
    height: 48px;
    background: transparent;
    border-radius: 8px;
    border: 1px solid var(--border-color);
    position: relative;
    padding: 0;
    cursor: pointer;
  }

  i {
    position: absolute;
    right: 6px;
    bottom: 4px;
  }

  .chip.is-active {
    --border-color: rgba(255, 255, 255, 0.1);
  }

  .icon-box {
    width: 100%;
    height: 100%;
    background: transparent;
    border-radius: 8px;
    overflow: hidden;
  }

  .is-light { background: #F6F6F9; }
  .is-dark { background: #17171F; }
  .is-sepia { background: #E9E0CA; }
`
