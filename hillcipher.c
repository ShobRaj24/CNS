#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <math.h> 

#define MAX_SIZE 10

// Function to calculate the determinant of a 2x2 matrix 
int determinant(int a, int b, int c, int d) { 
    return (a * d - b * c); 
} 

// Function to calculate the modulo inverse of a number 
int moduloInverse(int a, int m) { 
    for (int i = 1; i < m; i++) { 
        if ((a * i) % m == 1) { 
            return i; 
        } 
    } 
    return -1; // No modular inverse exists 
} 

// Function to encrypt the message using the Hill Cipher algorithm 
void encrypt(char message[], int keyMatrix[][MAX_SIZE], int keySize) { 
    int messageLength = strlen(message); 
    int paddedLength = (int) ceil(messageLength / (float) keySize) * keySize; 
    int paddedMessage[paddedLength]; 
    int encrypted[paddedLength]; 
    
    // Pad the message with 'X' to make its length a multiple of keySize 
    for (int i = 0; i < messageLength; i++) { 
        paddedMessage[i] = message[i] - 'A'; 
    } 
    for (int i = messageLength; i < paddedLength; i++) { 
        paddedMessage[i] = 23; // 'X' - 'A' = 23 
    } 
    
    // Encrypt the message 
    for (int i = 0; i < paddedLength; i += keySize) { 
        for (int j = 0; j < keySize; j++) { 
            int sum = 0; 
            for (int k = 0; k < keySize; k++) { 
                sum += keyMatrix[j][k] * paddedMessage[i + k]; 
            } 
            encrypted[i + j] = sum % 26; 
        } 
    } 
    
    // Print the encrypted message 
    printf("Encrypted message: "); 
    for (int i = 0; i < paddedLength; i++) {
        printf("%c", (char) (encrypted[i] + 'A')); 
    } 
    printf("\n"); 
} 

int main() { 
    int keySize, keyMatrix[MAX_SIZE][MAX_SIZE]; 
    char message[1000]; 
    
    // Input the size of the key matrix 
    printf("Enter the size of the key matrix (max 10): "); 
    scanf("%d", &keySize); 
    
    // Input the key matrix elements 
    printf("Enter the elements of the key matrix:\n"); 
    for (int i = 0; i < keySize; i++) { 
        for (int j = 0; j < keySize; j++) { 
            scanf("%d", &keyMatrix[i][j]); 
        } 
    } 
    
    // Check if the key matrix is invertible for 2x2 matrix only 
    if (keySize == 2 && determinant(keyMatrix[0][0], keyMatrix[0][1], keyMatrix[1][0], keyMatrix[1][1]) == 0) { 
        printf("The key matrix is not invertible. Please enter a valid key matrix.\n"); 
        return 1; 
    } 
    
    // Input the message to be encrypted 
    printf("Enter the message to be encrypted (uppercase letters only): "); 
    scanf("%s", message); 
    
    // Encrypt the message using the Hill Cipher algorithm 
    encrypt(message, keyMatrix, keySize); 
    
    return 0; 
}
