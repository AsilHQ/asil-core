// Copyright (c) 2021 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at https://mozilla.org/MPL/2.0/.

import * as React from 'react'
import { useHistory } from 'react-router'
import { useDispatch } from 'react-redux'

import Button from '@brave/leo/react/button'

// Constants
import {
  LOCAL_STORAGE_KEYS //
} from '../../../common/constants/local-storage-keys'
import { WalletRoutes } from '../../../constants/types'

// Utils
import { getLocale } from '../../../../common/locale'
import { openWalletRouteTab } from '../../../utils/routes-utils'
import { UISelectors, WalletSelectors } from '../../../common/selectors'
import { WalletActions } from '../../../common/actions'
import {
  useSafeUISelector,
  useSafeWalletSelector
} from '../../../common/hooks/use-safe-selector'

// Components
import { PasswordInput } from '../../shared/password-input/password-input-v2'

// Styled Components
import {
  StyledWrapper,
  Title,
  Description,
  PageIcon,
  InputColumn,
  UnlockButton,
  InputLabel
} from './style'
import { VerticalSpace, Row } from '../../shared/style'

export const LockScreen = () => {
  // redux
  const dispatch = useDispatch()
  const isPanel = useSafeUISelector(UISelectors.isPanel)
  const hasIncorrectPassword = useSafeWalletSelector(
    WalletSelectors.hasIncorrectPassword
  )

  // routing
  const history = useHistory()

  // state
  const [password, setPassword] = React.useState('')

  // computed
  const disabled = password === ''

  // methods
  const unlockWallet = React.useCallback(() => {
    dispatch(WalletActions.unlockWallet({ password: password }))
    setPassword('')
    const sessionRoute = window.localStorage.getItem(
      LOCAL_STORAGE_KEYS.SESSION_ROUTE
    )
    history.push(sessionRoute || WalletRoutes.PortfolioAssets)
  }, [password])

  const handleKeyDown = React.useCallback(
    (event: React.KeyboardEvent<HTMLInputElement>) => {
      if (event.key === 'Enter' && !disabled) {
        unlockWallet()
      }
    },
    [unlockWallet, disabled]
  )

  const handlePasswordChanged = React.useCallback(
    (value: string) => {
      setPassword(value)

      // clear error
      if (hasIncorrectPassword) {
        dispatch(WalletActions.hasIncorrectPassword(false))
      }
    },
    [hasIncorrectPassword]
  )

  const onShowRestore = React.useCallback(() => {
    if (isPanel) {
      openWalletRouteTab(WalletRoutes.Restore)
    } else {
      history.push(WalletRoutes.Restore)
    }
  }, [isPanel])

  // render
  return (
    <StyledWrapper>
      <PageIcon />
      <Title>{getLocale('braveWalletUnlockWallet')}</Title>
      <Description textSize='16px'>
        {getLocale('braveWalletLockScreenTitle')}
      </Description>
      <InputColumn fullWidth={true}>
        <Row
          justifyContent='flex-start'
          padding='0px 4px'
          marginBottom={4}
        >
          <InputLabel
            textSize='12px'
            isBold={true}
          >
            {getLocale('braveWalletInputLabelPassword')}
          </InputLabel>
        </Row>
        <PasswordInput
          placeholder={getLocale('braveWalletEnterYourPassword')}
          onChange={handlePasswordChanged}
          onKeyDown={handleKeyDown}
          error={getLocale('braveWalletLockScreenError')}
          hasError={hasIncorrectPassword}
          autoFocus={true}
          value={password}
        />
        <VerticalSpace space='24px' />
        <UnlockButton
          onClick={unlockWallet}
          isDisabled={disabled}
          kind='filled'
          size='large'
        >
          {getLocale('braveWalletLockScreenButton')}
        </UnlockButton>
        <Button
          onClick={onShowRestore}
          kind='plain'
        >
          {getLocale('braveWalletWelcomeRestoreButton')}
        </Button>
      </InputColumn>
    </StyledWrapper>
  )
}
