#include <stdio.h>
#include <string.h>

#include "hash/sha1.h"
#include "hmac/hmac.h"
#include "util/util.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <key> <message>\n", argv[0]);
    return 1;
  }

  char output[sha1.digest_size], output_hex[2 * sha1.digest_size];
  hmac(sha1, argv[1], strlen(argv[1]), argv[2], strlen(argv[2]), output);
  to_hex(output, sha1.digest_size, output_hex);

  printf("%s\n", output_hex);
}
