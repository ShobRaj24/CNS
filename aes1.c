#include<stdio.h>
#include<stdlib.h>
#include<openssl/aes.h>
#include<string.h>

unsigned char aes_key[] = "0123456789abcdef";


void aes_encrypt(unsigned char *plaintext, unsigned char *ciphertext) {
AES_KEY key;
AES_set_encrypt_key(aes_key, 128, &key);
AES_encrypt(plaintext, ciphertext, &key);
}


void aes_decrypt(unsigned char *ciphertext, unsigned char *decryptedtext) {
AES_KEY key;
AES_set_decrypt_key(aes_key, 128, &key);
AES_decrypt(ciphertext, decryptedtext, &key);
}

int main() {
unsigned char plaintext[100];
unsigned char ciphertext[AES_BLOCK_SIZE];
unsigned char decryptedtext[AES_BLOCK_SIZE];


printf("Enter the plaintext: ");
fgets(plaintext, sizeof(plaintext), stdin);

plaintext[strcspn(plaintext, "\n")] = '\0';

aes_encrypt(plaintext, ciphertext);

aes_decrypt(ciphertext, decryptedtext);

printf("Original message: %s\n", plaintext);
printf("Encrypted message: ");
for (int i = 0; i < AES_BLOCK_SIZE; i++) {
printf("%02x", ciphertext[i]);
}
printf("\n");
printf("Decrypted message: %s\n", decryptedtext);

return 0;
}