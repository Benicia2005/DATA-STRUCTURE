#include <stdio.h>
#include <string.h>

int main() {
    char word1[50], word2[50];

    // Get the first word from the user
    printf("Enter the first word: ");
    scanf("%s", word1);

    // Get the second word from the user
    printf("Enter the second word: ");
    scanf("%s", word2);

    // Concatenate the two words
    strcat(word1, word2);

    // Display the concatenated word
    printf("Concatenated word: %s\n", word1);

    return 0;
}
