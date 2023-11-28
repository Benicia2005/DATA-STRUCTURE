#include <stdio.h>

int main() {
    int n,i;

    // Input the number of terms in the Fibonacci series
    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);

    // Initialize variables to store Fibonacci series terms and sum
    int first = 0, second = 1, next, sum = 0;

    // Print Fibonacci series and calculate the sum
    printf("Fibonacci Series: ");
    for ( i = 0; i < n; ++i) {
        printf("%d ", first);

        // Add current term to the sum
        sum += first;

        // Update terms for the next iteration
        next = first + second;
        first = second;
        second = next;
    }

    // Print the sum of the Fibonacci series
    printf("\nSum of the Fibonacci series: %d\n", sum);

    return 0;
}
