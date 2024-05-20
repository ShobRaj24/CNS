#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char pt[MAX_LEN] = {'\0'}, ct[MAX_LEN] = {'\0'}, key[MAX_LEN] = {'\0'}, rt[MAX_LEN] = {'\0'};
    int i, j;

    // Clear screen (for Windows)
    system("cls");

    printf("\nEnter the plain text: ");
    fgets(pt, MAX_LEN, stdin);  // Safer input handling

    printf("Enter the key: ");
    fgets(key, MAX_LEN, stdin);

    // Remove newline characters from inputs
    pt[strcspn(pt, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    // Ensure key is not empty
    if (strlen(key) == 0) {
        printf("Key cannot be empty.\n");
        return 1;
    }

    // Extend key to match the length of plaintext if necessary
    j = 0;
    for (i = strlen(key); i < strlen(pt); i++) {
        key[i] = key[j % strlen(key)];  // Cycling through the key characters
        j++;
    }
    key[strlen(pt)] = '\0';  // Null-terminate the extended key
    printf("\nNew key is: %s\n", key);

    // Encrypt plaintext
    for (i = 0; i < strlen(pt); i++) {
        ct[i] = (((pt[i] - 'a') + (key[i] - 'a')) % 26) + 'a';  // Ensure modulo operation works correctly
    }
    ct[strlen(pt)] = '\0';  // Null-terminate the cipher text
    printf("\nCipher text is: %s\n", ct);

    // Decrypt ciphertext
    for (i = 0; i < strlen(ct); i++) {
        rt[i] = (((ct[i] - 'a') - (key[i] - 'a') + 26) % 26) + 'a';  // Simplified decryption logic
    }
    rt[strlen(ct)] = '\0';  // Null-terminate the decrypted text
    printf("\nPlaintext is: %s\n", rt);

    return 0;
}
