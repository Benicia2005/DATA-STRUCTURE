#include <stdio.h>

int findMissingPositive(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
            // Swap the elements to their correct positions
            int temp = arr[i];
            arr[i] = arr[temp - 1];
            arr[temp - 1] = temp;
        }
    }
    
    // Find the first position where the element is not in its correct position
    for ( i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }

    // If all elements are in their correct positions, return the next positive integer
    return n + 1;
}

int main() {
    int n,i;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Get array elements from the user
    int arr[n];
    printf("Enter the elements of the array:\n");
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the smallest positive number missing
    int missing = findMissingPositive(arr, n);

    printf("The smallest positive number missing is: %d\n", missing);

    return 0;
}
