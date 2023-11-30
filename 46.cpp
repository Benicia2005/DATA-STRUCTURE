#include <stdio.h>

// Function to find the second maximum in an array
int findSecondMax(const int arr[], int size) {
    if (size < 2) {
        printf("Array should have at least two elements.\n");
        return -1;  // Assuming -1 represents an error or invalid value
    }

    int max = arr[0];
    int secondMax = arr[1];

    for (int i = 2; i < size; i++) {
        if (arr[i] > max) {
            secondMax = max;
            max = arr[i];
        } else if (arr[i] > secondMax && arr[i] < max) {
            secondMax = arr[i];
        }
    }

    return secondMax;
}

// Overloaded function to find the second maximum in a character array
char findSecondMax(const char arr[], int size) {
    if (size < 2) {
        printf("Array should have at least two elements.\n");
        return '\0';  // Assuming '\0' represents an error or invalid value
    }

    char max = arr[0];
    char secondMax = arr[1];

    for (int i = 2; i < size; i++) {
        if (arr[i] > max) {
            secondMax = max;
            max = arr[i];
        } else if (arr[i] > secondMax && arr[i] < max) {
            secondMax = arr[i];
        }
    }

    return secondMax;
}

int main() {
    // Example 1: Integer array
    int intArr[] = {23, 6, 78, 90, 123};
    int intSize = sizeof(intArr) / sizeof(int);
    printf("Second Maximum (Integer): %d\n", findSecondMax(intArr, intSize));

    // Example 2: Character array
    char charArr[] = {'e', 'I', 'o', 'p'};
    int charSize = sizeof(charArr) / sizeof(char);
    printf("Second Maximum (Character): %c\n", findSecondMax(charArr, charSize));

    return 0;
}
