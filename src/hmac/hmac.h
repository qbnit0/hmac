#pragma once

#include "hash/hash.h"

/// Compute the HMAC of `message` with `key`, using the provided hash
/// function. Writes into `result`, which must be at least
/// `hash_fn.digest_size` large.
void hmac(
  HashFunction hash_fn,
  char *key, size_t key_size,
  char *message, size_t message_size,
  char *result
);
