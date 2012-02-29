/**
 * This file is part of the CernVM File System.
 */

#ifndef CVMFS_SIGNATURE_H_
#define CVMFS_SIGNATURE_H_

#include <string>
#include <cstdio>
#include "hash.h"

namespace signature {

void Init();
void Fini();
std::string GetCryptoError();

bool LoadPrivateKeyPath(const std::string &file_pem,
                        const std::string &password);
void UnloadPrivateKey();

bool LoadCertificatePath(const std::string &file_pem);
bool LoadCertificateMem(const unsigned char *buffer,
                        const unsigned buffer_size);
bool WriteCertificateMem(unsigned char **buffer, unsigned *buffer_size);
bool KeysMatch();
std::string Whois();
std::string FingerprintCertificate();

bool LoadPublicRsaKeys(const std::string &file_list);

bool Sign(const unsigned char *buffer, const unsigned buffer_size,
          unsigned char **signature, unsigned *signature_size);
bool Verify(const unsigned char *buffer, const unsigned buffer_size,
            const unsigned char *signature, unsigned signature_size);
bool VerifyRsa(const unsigned char *buffer, const unsigned buffer_size,
               const unsigned char *signature, unsigned signature_size);

}  // namespace signature

#endif  // CVMFS_SIGNATURE_H_
