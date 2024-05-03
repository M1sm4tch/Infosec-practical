#include <stdio.h>
#include <string.h>

// Function to encrypt the message using Rail Fence Cipher
void encryptRailFence(char *message, int rails, char *encryptedMessage) {
    int messageLen = strlen(message);
    char railFence[rails][messageLen];
    int i, j;

    // Initialize railFence to empty spaces
    for (i = 0; i < rails; i++) {
        for (j = 0; j < messageLen; j++) {
            railFence[i][j] = ' ';
        }
    }

    // Fill in the railFence matrix
    int row = 0;
    int dir_down = 0;
    for (i = 0; i < messageLen; i++) {
        railFence[row][i] = message[i];
        if (row == 0 || row == rails - 1)
            dir_down = !dir_down;
        row += dir_down ? 1 : -1;
    }

    // Read railFence matrix in encryptedMessage
    int k = 0;
    for (i = 0; i < rails; i++) {
        for (j = 0; j < messageLen; j++) {
            if (railFence[i][j] != ' ') {
                encryptedMessage[k++] = railFence[i][j];
            }
        }
    }
    encryptedMessage[k] = '\0';
}

// Function to decrypt the message using Rail Fence Cipher
void decryptRailFence(char *encryptedMessage, int rails, char *decryptedMessage) {
    int messageLen = strlen(encryptedMessage);
    char railFence[rails][messageLen];
    int i, j;

    // Initialize railFence to empty spaces
    for (i = 0; i < rails; i++) {
        for (j = 0; j < messageLen; j++) {
            railFence[i][j] = ' ';
        }
    }

    // Fill in the railFence matrix with 'x' to mark the positions
    int row = 0;
    int dir_down;
    for (i = 0; i < messageLen; i++) {
        railFence[row][i] = 'x';
        if (row == 0 || row == rails - 1)
            dir_down = !dir_down;
        row += dir_down ? 1 : -1;
    }

    // Fill in the railFence matrix with the characters from the encrypted message
    int k = 0;
    for (i = 0; i < rails; i++) {
        for (j = 0; j < messageLen; j++) {
            if (railFence[i][j] == 'x') {
                railFence[i][j] = encryptedMessage[k++];
            }
        }
    }

    // Read railFence matrix in decryptedMessage
    row = 0;
    dir_down = 0;
    k = 0;
    for (i = 0; i < messageLen; i++) {
        decryptedMessage[i] = railFence[row][i];
        if (row == 0 || row == rails - 1)
            dir_down = !dir_down;
        row += dir_down ? 1 : -1;
    }
    decryptedMessage[messageLen] = '\0';
}

int main() {
    char message[] = "HELLO WORLD";
    int rails = 3;
    char encryptedMessage[100];
    char decryptedMessage[100];

    printf("Original Message: %s\n", message);

    encryptRailFence(message, rails, encryptedMessage);
    printf("Encrypted Message: %s\n", encryptedMessage);

    decryptRailFence(encryptedMessage, rails, decryptedMessage);
    printf("Decrypted Message: %s\n", decryptedMessage);

    return 0;
}
