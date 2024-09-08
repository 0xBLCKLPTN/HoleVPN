#include <stdio.h>
#include <stdlib.h>
#include "../cryptography/cryptography.h"

#define BUFFER_SIZE 1024

int main(void)
{
  unsigned char ciphertext[128];
  unsigned char plaintext[] = "Hello World!";
  
  unsigned char result[128];

  int plaintext_len = simple_aes_encode(&plaintext, &ciphertext);
  // Print the ciphertext
  simple_aes_encoded_print(&ciphertext, plaintext_len);
  simple_aes_decode(&ciphertext, &result);
  printf("Plaintext: %s\n", plaintext);
}
