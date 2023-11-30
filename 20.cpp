#include <stdio.h>

int main() {
    // Assuming a 3x3 matrix for demonstration
    int matrix[3][3] = {
        {10, 9, 6},
        {7, 6, 3},
        {3, 2, 1}
    };

    // Number of rows and columns in the matrix
    int n = 3;

    // Value of k for the kth largest element
    int k = 5,i,j;

    int count = 0;
    int result;

    // Iterate through the matrix in descending order
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            // Count the elements encountered so far
            count++;

            // If count reaches k, store the current element as the result
            if (count == k) {
                result = matrix[i][j];
                break;
            }
        }
    }

    // Print the kth largest element
    printf("The %dth largest element is: %d\n", k, result);

    return 0;
}
