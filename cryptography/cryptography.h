#define CRYPTOGRAPHY_H

#include <string.h>

#define KEY "superkey"

void encrypt(char *data, int len, const char *key);
