#include <stdio.h>

void sort(int arr[], int n) {
	int i,j;
    // Simple selection sort algorithm
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                // Swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int findKthSmallest(int matrix[10][10], int rows, int cols, int k) {
    // Extract all elements from the matrix and store in a 1D array
    int elements[100];
    int index = 0,i,j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            elements[index++] = matrix[i][j];
        }
    }

    // Sort the 1D array
    sort(elements, rows * cols);

    // Return the kth smallest element
    return elements[k - 1];
}

int main() {
    int rows, cols, k,i,j;

    // Get the dimensions of the matrix
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    // Get the matrix elements from the user
    int matrix[10][10];
    printf("Enter the elements of the matrix:\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Get the value of k
    printf("Enter the value of k: ");
    scanf("%d", &k);

    // Find and display the kth smallest element
    int kthSmallest = findKthSmallest(matrix, rows, cols, k);
    printf("The %dth smallest element in the matrix is: %d\n", k, kthSmallest);

    return 0;
}
