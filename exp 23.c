#include <stdio.h>

int main() {
    int N,i;

    // Input the positive integer N
    printf("Enter a positive integer N: ");
    scanf("%d", &N);

    // Check if N is negative
    if (N < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;  // Exit with an error code
    }

    // Calculate factorial
    int factorial = 1;
    for ( i = 1; i <= N; ++i) {
        factorial *= i;
    }

    // Print the factorial
    printf("Factorial of %d: %d\n", N, factorial);

    return 0;
}
