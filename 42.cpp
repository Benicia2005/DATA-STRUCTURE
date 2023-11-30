#include <stdio.h>
#include <limits.h>

int reverse(int x) {
    long long result = 0;  // Use long long to handle potential overflow

    while (x != 0) {
        result = result * 10 + x % 10;
        x /= 10;

        // Check for overflow
        if (result > INT_MAX || result < INT_MIN) {
            return 0;
        }
    }

    return (int)result;
}

int main() {
    // Example usage
    int x1 = 123;
    printf("Input 1: %d\nOutput 1: %d\n", x1, reverse(x1));

    int x2 = -123;
    printf("Input 2: %d\nOutput 2: %d\n", x2, reverse(x2));

    int x3 = 120;
    printf("Input 3: %d\nOutput 3: %d\n", x3, reverse(x3));

    return 0;
}
