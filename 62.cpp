#include <stdio.h>

// Function to generate the series using recursion
void generateSeries(int a, int b, int n) {
    if (n <= 0) {
        return;
    }

    printf("%d ", a);

    // Generate the next term in the series
    int nextTerm = a + b;

    // Update the values for the next recursion
    a = b;
    b = nextTerm;

    // Call the function recursively for the next term
    generateSeries(a, b, n - 1);
}

int main() {
    // Starting values for the series
    int firstTerm = 1;
    int secondTerm = 2;

    // Number of terms in the series
    int n = 8;

    // Generate the series using recursion
    generateSeries(firstTerm, secondTerm, n);

    return 0;
}
