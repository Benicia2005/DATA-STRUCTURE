#include <stdio.h>

int main() {
    int n;

    // Get the number of terms from the user
    printf("Enter the number of Fibonacci terms: ");
    scanf("%d", &n);

    // First two terms of the series
    int firstTerm = 0, secondTerm = 1,i;

    // Display the first two terms
    printf("Fibonacci Series: %d %d ", firstTerm, secondTerm);

    // Generate and display the next terms in the series
    for (i = 2; i < n; ++i) {
        int nextTerm = firstTerm + secondTerm;

        // Display the next term
        printf("%d ", nextTerm);

        // Update the values for the next iteration
        firstTerm = secondTerm;
        secondTerm = nextTerm;
    }

    return 0;
}
