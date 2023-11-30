#include <stdio.h>

#define MAX_ROW 100
#define MAX_COL 100

void findRowColSum(int mat[MAX_ROW][MAX_COL], int m, int n) {
    for (int i = 0; i < m; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += mat[i][j];
        }
        printf("Row sum %d: %d\n", i + 1, rowSum);
    }

    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < m; i++) {
            colSum += mat[i][j];
        }
        printf("Column sum %d: %d\n", j + 1, colSum);
    }
}

int findDiagonalSum(int mat[MAX_ROW][MAX_COL], int m, int n) {
    if (m != n) {
        printf("Matrix should be square for diagonal sum calculation.\n");
        return -1;
    }

    int diagonalSum = 0;
    for (int i = 0; i < m; i++) {
        diagonalSum += mat[i][i];
    }
    return diagonalSum;
}

void findMaxMin(int mat[MAX_ROW][MAX_COL], int m, int n) {
    int maxElement = mat[0][0];
    int minElement = mat[0][0];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] > maxElement) {
                maxElement = mat[i][j];
            }
            if (mat[i][j] < minElement) {
                minElement = mat[i][j];
            }
        }
    }

    printf("Maximum: %d, Minimum: %d\n", maxElement, minElement);
}

int main() {
    int mat[MAX_ROW][MAX_COL] = {{3, 4, 5},
                                 {7, 8, 9},
                                 {10, 11, 12}};
    int m = 3;
    int n = 3;

    findRowColSum(mat, m, n);
    
    int diagonalSum = findDiagonalSum(mat, m, n);
    if (diagonalSum != -1) {
        printf("Diagonal sum: %d\n", diagonalSum);
    }

    findMaxMin(mat, m, n);

    return 0;
}
