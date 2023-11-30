#include <stdio.h>

int main() {
	int i;
    int arr1[] = {1, 2, 3, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]) + 1;

    // Calculate the sum of first N natural numbers
    int expectedSum1 = (n1 * (n1 + 1)) / 2;

    // Calculate the sum of array elements
    int actualSum1 = 0;
    for ( i = 0; i < n1 - 1; i++) {
        actualSum1 += arr1[i];
    }

    // The missing element is the difference between the expected and actual sums
    int missingElement1 = expectedSum1 - actualSum1;
    printf("Output 1: %d\n", missingElement1);

    int arr2[] = {6, 1, 2, 8, 3, 4, 7, 10, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]) + 1;

    // Calculate the sum of first N natural numbers
    int expectedSum2 = (n2 * (n2 + 1)) / 2;

    // Calculate the sum of array elements
    int actualSum2 = 0;
    for (i = 0; i < n2 - 1; i++) {
        actualSum2 += arr2[i];
    }

    // The missing element is the difference between the expected and actual sums
    int missingElement2 = expectedSum2 - actualSum2;
    printf("Output 2: %d\n", missingElement2);

    return 0;
}
