#pragma once

#include "hash/hash.h"

char *hmac(
  HashFunction hash_fn,
  char *key, size_t key_size,
  char *message, size_t message_size
);
