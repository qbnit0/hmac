#include "impl/sha1.h"
#include "hash.h"

HashFunction sha1 = {
  (void (*)(void *))&SHA1Init,
  (void (*)(void *, char *, size_t))&SHA1Update,
  (void (*)(char *, void *)) &SHA1Final,
  20, 64, sizeof(SHA1_CTX)
};
