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

    // Temporary array for merging
    int temp[n];

    // Perform merge sort
    for (int curr_size = 1; curr_size <= n - 1; curr_size *= 2) {
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = left_start + curr_size - 1;
            int right_end = (left_start + 2 * curr_size - 1 < n - 1) ? left_start + 2 * curr_size - 1 : n - 1;

            // Merge the two halves
            int i = left_start;
            int j = mid + 1;
            int k = left_start;

            while (i <= mid && j <= right_end) {
                if (arr[i] <= arr[j]) {
                    temp[k++] = arr[i++];
                } else {
                    temp[k++] = arr[j++];
                }
            }

            // Copy the remaining elements of the left half
            while (i <= mid) {
                temp[k++] = arr[i++];
            }

            // Copy the remaining elements of the right half
            while (j <= right_end) {
                temp[k++] = arr[j++];
            }

            // Copy the merged elements back to the original array
            for (int p = left_start; p <= right_end; p++) {
                arr[p] = temp[p];
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
