#ifndef ENCRYPT_FUNC_H
#define ENCRYPT_FUNC_H

#include <openssl/sha.h>

void OpenSSL_add_all_algorithms();

int Encrypt_File(const char *,char *,char []);

#endif //ENRYPT_H