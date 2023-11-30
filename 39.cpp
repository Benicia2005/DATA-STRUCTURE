#include <stdio.h>

// Function to check if there are duplicates in the array
int containsDuplicate(int* nums, int numsSize) {
    // Check each element against all following elements
    for (int i = 0; i < numsSize - 1; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            // If a duplicate is found, return true
            if (nums[i] == nums[j]) {
                return 1; // true
            }
        }
    }
    // If no duplicates are found, return false
    return 0; // false
}

int main() {
    // Example usage
    int nums1[] = {1, 2, 3, 1};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Output 1: %s\n", containsDuplicate(nums1, size1) ? "true" : "false");

    int nums2[] = {1, 2, 3};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Output 2: %s\n", containsDuplicate(nums2, size2) ? "true" : "false");

    int nums3[] = {1, 2, 3, 4};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Output 3: %s\n", containsDuplicate(nums3, size3) ? "true" : "false");

    int nums4[] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    int size4 = sizeof(nums4) / sizeof(nums4[0]);
    printf("Output 4: %s\n", containsDuplicate(nums4, size4) ? "true" : "false");

    return 0;
}
