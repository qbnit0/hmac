#include <stdlib.h>
#include <string.h>

#include "hashfn.h"
#include "util.h"
#include "hmac.h"

#define OUTER_PAD 0x5c
#define INNER_PAD 0x36

/// Resizes `key` in-place to have a length equal to `block_size`.
static void blocksize_key(
  HashFunction hash_fn,
  char *key, size_t key_size
) {
  if (key_size > hash_fn.block_size) {
    void *state = alloca(hash_fn.state_size);
    hash_fn.init(state);

    hash_fn.update(state, key, key_size);
    hash_fn.digest(key, state);

    key_size = hash_fn.digest_size;
  }
  memset(key + key_size, 0, hash_fn.block_size - key_size);
}


char *hmac(
  HashFunction hash_fn,
  char *key, size_t key_size,
  char *message, size_t message_size
) {
  {
    char *k = key;
    key = alloca(max(key_size, hash_fn.block_size));
    memcpy(key, k, key_size);
  }
  blocksize_key(hash_fn, key, key_size);
  key_size = hash_fn.block_size; // Key now fits in block_size

  // Padding
  char *key_opad = alloca(key_size); memcpy(key_opad, key, key_size);
  char *key_ipad = alloca(key_size); memcpy(key_ipad, key, key_size);
  for (int i = 0; i < key_size; i++) {
    key_opad[i] ^= OUTER_PAD;
    key_ipad[i] ^= INNER_PAD;
  }

  // Inner fragment
  char *inner_fragment = alloca(hash_fn.digest_size);

  void *state = alloca(hash_fn.state_size);
  hash_fn.init(state);

  hash_fn.update(state, key_ipad, key_size);
  hash_fn.update(state, message, message_size);

  hash_fn.digest(inner_fragment, state);

  // Result
  char *result = malloc(hash_fn.digest_size);

  state = alloca(hash_fn.state_size);
  hash_fn.init(state);

  hash_fn.update(state, key_opad, key_size);
  hash_fn.update(state, inner_fragment, hash_fn.digest_size);

  hash_fn.digest(result, state);

  return result;
}
