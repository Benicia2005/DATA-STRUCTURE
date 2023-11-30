#include <stdio.h>

// Function to calculate the frequency of the value at index k
	int frequencyAtK(int* nums, int numsSize, int k) {
    if (k < 0 || k >= numsSize) {
        printf("Invalid index\n");
        return -1;
    }

    int target = nums[k];
    int frequency = 0,i;
    for ( i = 0; i < numsSize; ++i) {
        if (nums[i] == target) {
            frequency++;
        }
    }

    return frequency;
}
int main() {
    // Example usage
    int nums[] = {1, 2, 3, 2, 4, 2, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 2;

    int result = frequencyAtK(nums, numsSize, k);

    // Print the result
    if (result != -1) {
        printf("Frequency of the value at index %d: %d\n", k, result);
    }
    return 0;
}
