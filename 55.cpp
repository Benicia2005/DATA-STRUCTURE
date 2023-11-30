#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPERATIONS 1000

// Function to perform stack operations to match target
char** buildArray(int* target, int targetSize, int n, int* returnSize) {
    char** operations = (char*)malloc(MAX_OPERATIONS * sizeof(char));
    *returnSize = 0;

    int targetIndex = 0;
    int streamValue = 1,i;

    for (i = 0; i < targetSize; ++i) {
        // Push operation
        operations[returnSize] = (char)malloc(5 * sizeof(char));
        strcpy(operations[*returnSize], "Push");
        (*returnSize)++;

        // Pop operations until the current target is reached
        while (streamValue <= n && (targetIndex >= targetSize || streamValue != target[targetIndex])) {
            operations[returnSize] = (char)malloc(4 * sizeof(char));
            strcpy(operations[*returnSize], "Pop");
            (*returnSize)++;
            streamValue++;
        }

        // Increment targetIndex if a match is found
        if (targetIndex < targetSize && streamValue == target[targetIndex]) {
            targetIndex++;
        }
    }

    return operations;
}

int main() {
    // Example usage
    int target[] = {1, 3};
    int targetSize = sizeof(target) / sizeof(target[0]);
    int n = 3,i;

    int returnSize;
    char** operations = buildArray(target, targetSize, n, &returnSize);

    // Print the result
    printf("Output: [");
    for (i = 0; i < returnSize; ++i) {
        printf("\"%s\"", operations[i]);
        if (i < returnSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    // Free allocated memory
    for (i = 0; i < returnSize; ++i) {
        free(operations[i]);
    }
    free(operations);

    return 0;
}
