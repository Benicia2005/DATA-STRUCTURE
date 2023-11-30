#include <stdio.h>

int main() {
    int n;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Get the array elements from the user
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        int j = i;

        while (1) {
            int largest = j;
            int left = 2 * j + 1;
            int right = 2 * j + 2;

            // If left child is larger than root
            if (left < n && arr[left] > arr[largest]) {
                largest = left;
            }

            // If right child is larger than largest so far
            if (right < n && arr[right] > arr[largest]) {
                largest = right;
            }

            // If largest is not the root
            if (largest != j) {
                // Swap arr[j] and arr[largest]
                int temp = arr[j];
                arr[j] = arr[largest];
                arr[largest] = temp;

                // Update j to continue heapify
                j = largest;
            } else {
                break;
            }
        }
    }

    // One by one extract an element from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to the end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call max heapify on the reduced heap
        int j = 0;
        while (1) {
            int largest = j;
            int left = 2 * j + 1;
            int right = 2 * j + 2;

            // If left child is larger than root
            if (left < i && arr[left] > arr[largest]) {
                largest = left;
            }

            // If right child is larger than largest so far
            if (right < i && arr[right] > arr[largest]) {
                largest = right;
            }

            // If largest is not the root
            if (largest != j) {
                // Swap arr[j] and arr[largest]
                int temp = arr[j];
                arr[j] = arr[largest];
                arr[largest] = temp;

                // Update j to continue heapify
                j = largest;
            } else {
                break;
            }
        }
    }

    // Print the sorted array in ascending order
    printf("Sorted Array (Ascending Order): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
