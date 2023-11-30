#include <stdio.h>
int main() {
	int i;
    char str[100];
    int count[256] = {0}; // Assuming ASCII characters
    printf("Enter a string: ");
    gets(str);

    // Traverse the given string and update frequency
    for (i = 0; str[i] != '\0'; i++) 
	{
        count[(int)str[i]]++;
    }

    // Display the frequency of each character
    printf("Character frequencies:\n");
    for (i = 0; i < 256; i++) {
        if (count[i] > 0) {
            printf("%c: %d\n", (char)i, count[i]);
        }
    }

    return 0;
}
