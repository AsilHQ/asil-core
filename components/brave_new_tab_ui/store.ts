// Copyright (c) 2020 The Asil Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at https://mozilla.org/MPL/2.0/.

// Redux API
import { createStore, applyMiddleware } from 'redux'

// Feature core reducer
import { mainNewTabReducer } from './reducers'
import todayAsyncHandler from './async/today'

export default createStore(
  mainNewTabReducer,
  applyMiddleware(todayAsyncHandler)
)
