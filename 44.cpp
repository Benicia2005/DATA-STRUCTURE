#include <stdio.h>

int main() {
    int size1, size2;

    // Get the size of the first array from the user
    printf("Enter the size of the first array: ");
    scanf("%d", &size1);

    // Get the elements of the first array from the user
    int arr1[size1],i;
    printf("Enter %d elements for the first array:\n", size1);
    for (i = 0; i < size1; ++i) {
        scanf("%d", &arr1[i]);
    }

    // Get the size of the second array from the user
    printf("Enter the size of the second array: ");
    scanf("%d", &size2);

    // Get the elements of the second array from the user
    int arr2[size2];
    printf("Enter %d elements for the second array:\n", size2);
    for (i = 0; i < size2; ++i) {
        scanf("%d", &arr2[i]);
    }

    // Merge the arrays
    int mergedArray[size1 + size2];

    // Copy elements from the first array to the merged array
    for (i = 0; i < size1; ++i) {
        mergedArray[i] = arr1[i];
    }

    // Copy elements from the second array to the merged array
    for (i = 0; i < size2; ++i) {
        mergedArray[size1 + i] = arr2[i];
    }

    // Display the merged array
    printf("Merged Array:\n");
    for (i = 0; i < size1 + size2; ++i) {
        printf("%d ", mergedArray[i]);
    }

    return 0;
}
