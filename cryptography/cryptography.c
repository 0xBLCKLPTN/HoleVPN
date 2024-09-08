#include "./cryptography.h"
#include <openssl/aes.h>

#define KEY_SIZE 32
#define IV_SIZE 16

void dp_aes_decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *plaintext, unsigned char *iv, unsigned char *key) {
    AES_KEY dec_key;
    AES_set_decrypt_key(key, 256, &dec_key);
    AES_cbc_encrypt(ciphertext, plaintext, ciphertext_len, &dec_key, iv, AES_DECRYPT);
}

void dp_aes_encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *ciphertext, unsigned char *iv, unsigned char *key) {
    AES_KEY enc_key;
    AES_set_encrypt_key(key, 256, &enc_key);
    AES_cbc_encrypt(plaintext, ciphertext, plaintext_len, &enc_key, iv, AES_ENCRYPT);
}

int simple_aes_encode(unsigned char *plaintext, unsigned char *ciphertext)
{
  const unsigned char key[KEY_SIZE] = "01234567890123456789012345678901";
  const unsigned char iv[IV_SIZE] = "0123456789012345";

  int plaintext_len = strlen((char *)plaintext);
  dp_aes_encrypt(plaintext, plaintext_len, ciphertext, key, iv);
  return plaintext_len;
}

void simple_aes_decode(unsigned char *ciphertext, unsigned char *plaintext)
{
  const unsigned char key[KEY_SIZE] = "01234567890123456789012345678901";
  const unsigned char iv[IV_SIZE] = "0123456789012345";

  int ciphertext_len = sizeof(ciphertext);
  dp_aes_decrypt(ciphertext, ciphertext_len, plaintext, key, iv);
}

void simple_aes_encoded_print(unsigned char *ciphertext, int plaintext_len)
{
  printf("Ciphertext: ");
  for (int i = 0; i < plaintext_len; i++) {
    printf("%02x", ciphertext[i]);
  }
  printf("\n");
}

void encrypt(char *data, int len, const char *key) {
  for (int i = 0; i < len; i++)
    data[i] ^= key[i % strlen(key)];
}

