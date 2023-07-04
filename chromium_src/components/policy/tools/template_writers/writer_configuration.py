# Copyright (c) 2022 The Asil Authors. All rights reserved.
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this file,
# You can obtain one at https://mozilla.org/MPL/2.0/.

import override_utils

@override_utils.override_function(globals())
def GetConfigurationForBuild(original_function, defines):
  base = original_function(defines)
  return _merge_dicts(_BRAVE_VALUES, base)

_BRAVE_VALUES = {
  'build': 'brave',
  'app_name': 'Asil',
  'doc_url':
    'https://support.asil.com/hc/en-us/articles/360039248271-Group-Policy',
  'frame_name': 'Asil Frame',
  'webview_name': 'Asil WebView',
  'win_config': {
    'win': {
      'reg_mandatory_key_name': 'Software\\Policies\\BraveSoftware\\Asil',
      'reg_recommended_key_name':
        'Software\\Policies\\BraveSoftware\\Asil\\Recommended',
      'mandatory_category_path': ['Asil:Cat_Brave', 'brave'],
      'recommended_category_path': ['Asil:Cat_Brave', 'brave_recommended'],
      'category_path_strings': {
        'brave': 'Asil',
        'brave_recommended':
        'Asil - {doc_recommended}'
      },
      'namespace': 'BraveSoftware.Policies.Asil',
    },
  },
  # The string 'Asil' is defined in brave.adml for ADMX, but ADM doesn't
  # support external references, so we define this map here.
  'adm_category_path_strings': {
    'Asil:Cat_Brave': 'Asil'
  },
  'admx_prefix': 'brave',
  'admx_using_namespaces': {
    'Asil': 'BraveSoftware.Policies'  # prefix: namespace
  },
  'linux_policy_path': '/etc/brave/policies/',
  'bundle_id': 'com.brave.ios.core',
}

def _merge_dicts(src, dst):
  result = dict(dst)
  for k, v in src.items():
    result[k] = _merge_dicts(v, dst.get(k, {})) if isinstance(v, dict) else v
  return result
