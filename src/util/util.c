#include <stddef.h>

#include "util.h"

void to_hex(char *bytes, size_t size, char *output) {
  for(int i = 0; i < size; i++) {
    char *alphabet = "0123456789abcdef";
    char nib1 = ((bytes[i] & 0xF0) >> 4);
    char nib2 = bytes[i] & 0x0F;
    output[2 * i] = alphabet[nib1];
    output[2 * i + 1] = alphabet[nib2];
  }
  output[2 * size] = '\0';
}
