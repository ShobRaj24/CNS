#include <stdio.h>
#include <string.h>

// Function to encrypt plaintext using monoalphabetic cipher
void encrypt(char plaintext[], char key[]) {
    int i;
    char ciphertext[strlen(plaintext) + 1];
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = key[plaintext[i] - 'A'];
        } else if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = key[plaintext[i] - 'a'] + ('a' - 'A');
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';
    printf("Ciphertext: %s\n", ciphertext);
}

// Function to decrypt ciphertext using monoalphabetic cipher
void decrypt(char ciphertext[], char key[]) {
    int i, j;
    char plaintext[strlen(ciphertext) + 1];
    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            for (j = 0; key[j] != '\0'; j++) {
                if (ciphertext[i] == key[j]) {
                    plaintext[i] = 'A' + j;
                    break;
                }
            }
        } else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            for (j = 0; key[j] != '\0'; j++) {
                if (ciphertext[i] == key[j] + ('a' - 'A')) {
                    plaintext[i] = 'a' + j;
                    break;
                }
            }
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[i] = '\0';
    printf("Decrypted plaintext: %s\n", plaintext);
}

int main() {
    char plaintext[] = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    printf("Plaintext: %s\n", plaintext);
    encrypt(plaintext, key);
    char ciphertext[] = "ZIT JXOEA WKGVF YGB PXDHL GCTK ZIT SQMN RGU";
    decrypt(ciphertext, key);
    return 0;
}
