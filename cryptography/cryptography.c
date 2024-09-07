#include "./cryptography.h"

void encrypt(char *data, int len, const char *key) {
  for (int i = 0; i < len; i++)
    data[i] ^= key[i % strlen(key)];
}
