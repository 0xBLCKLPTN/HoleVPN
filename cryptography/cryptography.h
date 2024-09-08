#define CRYPTOGRAPHY_H
#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

#define KEY "superkey"
#define KEY_SIZE 32
#define IV_SIZE 16

void dp_aes_decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *plaintext, unsigned char *iv, unsigned char *key);
void dp_aes_encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *ciphertext, unsigned char *iv, unsigned char *key);
int simple_aes_encode(unsigned char *plaintext, unsigned char *ciphertext);
void simple_aes_decode(unsigned char *ciphertext, unsigned char *plaintext);
void simple_aes_encoded_print(unsigned char *ciphertext, int plaintext_len);
void encrypt(char *data, int len, const char *key);
