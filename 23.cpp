#include <stdio.h>
#include <stdlib.h>

// Function to check if a linked list is a palindrome
int isPalindrome(char* str, int length) {
    int i = 0, j = length - 1;
    while (i < j) {
        if (str[i] != str[j]) {
            return 0; // Not a palindrome
        }
        i++;
        j--;
    }
    return 1; // Palindrome
}

int main() {
    char arr1[] = {1,2,2,1};
    int length1 = sizeof(arr1) / sizeof(arr1[0]);

    printf("Input: R->A->D->A->R\nOutput: %s\n", isPalindrome(arr1, length1) ? "Yes" : "No");
}
