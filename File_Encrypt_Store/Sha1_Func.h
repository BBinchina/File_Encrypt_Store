#ifndef SHA1_FUNC_H
#define SHA1_FUNC_H
#include <openssl/sha.h>
int shaFile(const char*,char*);

//enum {File_Buffer_Size = 1024};
//unsigned char buffIn[File_Buffer_Size];
//unsigned char hash[SHA_DIGEST_LENGTH];

#endif //SHA1__FUNC_H