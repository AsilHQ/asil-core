/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_IOS_BROWSER_API_CERTIFICATE_UTILS_BRAVE_CERTIFICATE_X509_UTILS_H_
#define BRAVE_IOS_BROWSER_API_CERTIFICATE_UTILS_BRAVE_CERTIFICATE_X509_UTILS_H_

#include <string>
#include <vector>

#include "base/memory/ref_counted.h"
#include "base/time/time.h"
#include "net/cert/signed_certificate_timestamp.h"
#include "third_party/boringssl/src/include/openssl/base.h"
#include "third_party/boringssl/src/pki/input.h"
#include "third_party/boringssl/src/pki/parse_values.h"
#include "third_party/boringssl/src/pki/signature_algorithm.h"

namespace certificate {
namespace x509_utils {
std::vector<bssl::der::Input> SupportedExtensionOIDs();

bool ExtractEmbeddedSCT(
    const CRYPTO_BUFFER* cert,
    std::vector<scoped_refptr<net::ct::SignedCertificateTimestamp>>* scts);

bool ParseAlgorithmIdentifier(const bssl::der::Input& input,
                              bssl::der::Input* algorithm_oid,
                              bssl::der::Input* parameters);

bool ParseAlgorithmSequence(const bssl::der::Input& input,
                            bssl::der::Input* algorithm_oid,
                            bssl::der::Input* parameters);

bool ParseSubjectPublicKeyInfo(const bssl::der::Input& input,
                               bssl::der::Input* algorithm_sequence,
                               bssl::der::Input* spk);

bool ParseRSAPublicKeyInfo(const bssl::der::Input& input,
                           bssl::der::Input* modulus,
                           bssl::der::Input* public_exponent);

bool IsNull(const bssl::der::Input& input);

bool OIDToNID(const bssl::der::Input& input, std::int32_t* out);

std::string NIDToAbsoluteOID(const bssl::der::Input& input);

std::string SignatureAlgorithmDigestToName(
    const bssl::SignatureAlgorithm& signature_algorithm);

std::string SignatureAlgorithmIdToName(
    const bssl::SignatureAlgorithm& signature_algorithm);

base::Time GeneralizedTimeToTime(
    const bssl::der::GeneralizedTime& generalized_time);
}  // namespace x509_utils
}  // namespace certificate

#endif  // BRAVE_IOS_BROWSER_API_CERTIFICATE_UTILS_BRAVE_CERTIFICATE_X509_UTILS_H_
