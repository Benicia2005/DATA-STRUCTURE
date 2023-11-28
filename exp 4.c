#include<stdio.h>

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to print Fibonacci series and calculate its sum
void fibonacciSeriesAndSum(int n) {
    int i, sum = 0;

    printf("Fibonacci Series:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
        sum += fibonacci(i);
    }

    printf("\nSum of the Fibonacci Series: %d\n", sum);
}

int main() {
    int n;

    // Input
    printf("Enter the number of terms in Fibonacci series: ");
    scanf("%d", &n);

    // Print Fibonacci series and its sum
    fibonacciSeriesAndSum(n);

    return 0;
}#include <stdio.h>

int main() {
    int arr[] = {1, 5, 6, 7, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int x;
    printf("Enter the element to search: ");
    scanf("%d", &x);

    int low = 0, high = n - 1, mid, location = -1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == x) {
            location = mid + 1;
            break;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (location != -1) {
        printf("Element found at location %d\n", location);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
