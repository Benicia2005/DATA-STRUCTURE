#include <stdio.h>
#include<string.h>
// Function to search for the target in the sorted array
int searchInsert(const char** nums, int numsSize, const char* target) {
    int low = 0;
    int high = numsSize - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int compareResult = strcmp(nums[mid], target);

        if (compareResult == 0) {
            return mid; // Target found
        } else if (compareResult < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // If the target is not found, return the index where it would be inserted
    return low;
}

int main() {
    // Example usage with strings
    const char* nums[] = {"C++", "Java", "Python", "Xcode"};
    int size = sizeof(nums) / sizeof(nums[0]);
    const char* target = "Python";
    printf("Output: %d\n", searchInsert(nums, size, target));

    return 0;
}
