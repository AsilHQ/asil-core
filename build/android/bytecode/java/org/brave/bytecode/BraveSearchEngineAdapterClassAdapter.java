/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

package org.brave.bytecode;

import org.objectweb.asm.ClassVisitor;

public class BraveSearchEngineAdapterClassAdapter extends BraveClassVisitor {
    static String sSearchEngineAdapterClassName =
            "org/chromium/chrome/browser/search_engines/settings/SearchEngineAdapter";

    static String sBraveSearchEngineAdapterBaseClassName =
            "org/chromium/chrome/browser/search_engines/settings/BraveBaseSearchEngineAdapter";

    static String sMethodGetPermissionsLinkMessage =
            "getPermissionsLinkMessage";

    public BraveSearchEngineAdapterClassAdapter(ClassVisitor visitor) {
        super(visitor);

        changeSuperName(sSearchEngineAdapterClassName,
                sBraveSearchEngineAdapterBaseClassName);
        changeMethodOwner(sSearchEngineAdapterClassName, sMethodGetPermissionsLinkMessage,
                sBraveSearchEngineAdapterBaseClassName);
    }
}
