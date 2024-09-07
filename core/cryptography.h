#define CRYPTOGRAPHY_H


// Change me later. AES 256
void encrypt(char *plaintext, char *ciphertext, int len) {
    memcpy(ciphertext, plaintext, len);
}

void decrypt(char *ciphertext, char* plaintext, int len) {
    memcpy(plaintext, ciphertext, len);
}
