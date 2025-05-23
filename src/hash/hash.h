#pragma once

/// A cryptographic hash function.
typedef struct {
  // Initialize the function.
  void (*init)(void *state);

  // Feed data into the function.
  void (*update)(void *state, char *message, size_t message_size);

  // Return digest of previous data.
  void (*digest)(char *digest, void *state);

  // Length of the resulting digest.
  const size_t digest_size;

  // Length of a block.
  const size_t block_size;

  // Size of the state object.
  const size_t state_size;
} HashFunction;
