#include <stdio.h>

int main() {
    // Size of the arrays
    int m, n,i,j;

    // Input the size of the first array (nums1)
    printf("Enter the size of nums1: ");
    scanf("%d", &m);

    // Input the size of the second array (nums2)
    printf("Enter the size of nums2: ");
    scanf("%d", &n);

    // Declare arrays nums1 and nums2
    int nums1[m], nums2[n];

    // Input elements for nums1
    printf("Enter elements for nums1 in ascending order:\n");
    for ( i = 0; i < m; ++i) {
        scanf("%d", &nums1[i]);
    }

    // Input elements for nums2
    printf("Enter elements for nums2 in ascending order:\n");
    for (i = 0; i < n; ++i) {
        scanf("%d", &nums2[i]);
    }

    // Merge and print the sum of the two sorted arrays
    printf("Sum of the two sorted arrays: ");
    
    i = 0, j = 0;
    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            printf("%d ", nums1[i]);
            i++;
        } else {
            printf("%d ", nums2[j]);
            j++;
        }
    }

    // Print remaining elements of nums1
    while (i < m) {
        printf("%d ", nums1[i]);
        i++;
    }

    // Print remaining elements of nums2
    while (j < n) {
        printf("%d ", nums2[j]);
        j++;
    }

    printf("\n");

    return 0;
}
