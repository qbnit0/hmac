#pragma once

#include "hash/hash.h"

void hmac(
  HashFunction hash_fn,
  char *key, size_t key_size,
  char *message, size_t message_size,
  char *result
);
