#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate (base^exponent) % modulus
int power(int base, int exponent, int modulus) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }
    return result;
}

// Function to perform Diffie-Hellman key exchange
void diffieHellman() {
    int p, g, a, b; // Publicly known values: prime 'p', generator 'g'
    printf("Enter the value of prime (p) and generator (g): ");
    scanf("%d %d", &p, &g);

    printf("Enter the private key for Alice (a): ");
    scanf("%d", &a);
    printf("Enter the private key for Bob (b): ");
    scanf("%d", &b);

    // Calculate public keys
    int A = power(g, a, p);
    int B = power(g, b, p);

    // Calculate shared secret
    int secretKey_Alice = power(B, a, p);
    int secretKey_Bob = power(A, b, p);

    printf("Public Key for Alice: %d\n", A);
    printf("Public Key for Bob: %d\n", B);
    printf("Shared Secret Key for Alice: %d\n", secretKey_Alice);
    printf("Shared Secret Key for Bob: %d\n", secretKey_Bob);
}

int main() {
    diffieHellman();
    return 0;
}
