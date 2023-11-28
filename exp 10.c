#include <stdio.h>

void findFrequency(const char* s) {
    int frequency[256] = {0};  // Assuming ASCII characters
    int i;
    // Count the frequency of each character
    for ( i = 0; s[i] != '\0'; ++i) {
        frequency[(int)s[i]]++;
    }

    // Print the frequencies
    printf("Character frequencies:\n");
    for ( i = 0; i < 256; ++i) {
        if (frequency[i] > 0) {
            printf("%c -> %d\n", (char)i, frequency[i]);
        }
    }
}

int main() {
    const char* inputString = "tree";

    // Find and print character frequencies
    findFrequency(inputString);

    return 0;
}

