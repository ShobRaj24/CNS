#include <stdio.h>
#include <string.h>

// Function to calculate (base^exp) % modulus
long long int power(long long int base, long long int exp, long long int modulus) {
    long long int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exp /= 2;
    }
    return result;
}

// Function to calculate gcd using the Euclidean algorithm
long long int gcd(long long int a, long long int b) {
    while (b != 0) {
        long long int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find a suitable public exponent e
long long int find_e(long long int phi) {
    long long int e = 3;
    while (gcd(e, phi) != 1) {
        e += 2;  // Try next odd number
    }
    return e;
}

// Function to perform RSA encryption on a single character
long long int encrypt_char(char ch, long long int e, long long int n) {
    return power((long long int)ch, e, n);
}

// Function to perform RSA decryption on a single character
char decrypt_char(long long int ch, long long int d, long long int n) {
    return (char)power(ch, d, n);
}

int main() {
    // User input for prime numbers p and q
    long long int p, q;
    printf("Enter prime number p: ");
    scanf("%lld", &p);
    printf("Enter prime number q: ");
    scanf("%lld", &q);
    
    // Public and private keys
    long long int n = p * q;
    long long int phi = (p - 1) * (q - 1);
    
    // Automatically find public exponent e
    long long int e = find_e(phi);
    printf("Calculated public exponent e: %lld\n", e);
    
    // Private exponent calculation
    long long int d = 1;
    while (((d * e) % phi) != 1) {
        d++;
    }
    
    // Message to be encrypted
    char plaintext[256];
    printf("Enter plaintext message: ");
    getchar(); // to consume the newline character left by the previous scanf
    fgets(plaintext, 256, stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // remove the newline character from the input
    
    // Encryption
    long long int ciphertext[256];
    int length = strlen(plaintext);
    printf("Encrypted message: ");
    for (int i = 0; i < length; i++) {
        ciphertext[i] = encrypt_char(plaintext[i], e, n);
        printf("%lld ", ciphertext[i]);
    }
    printf("\n");
    
    // Decryption
    char decryptedtext[256];
    printf("Decrypted message: ");
    for (int i = 0; i < length; i++) {
        decryptedtext[i] = decrypt_char(ciphertext[i], d, n);
    }
    decryptedtext[length] = '\0'; // null-terminate the decrypted string
    printf("%s\n", decryptedtext);
    
    return 0;
}
