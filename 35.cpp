#include <stdio.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    static int result[2] = {-1, -1};

    // Search for the leftmost occurrence of the target
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            result[0] = i;
            break;
        }
    }

    // Search for the rightmost occurrence of the target
    for (int i = numsSize - 1; i >= 0; i--) {
        if (nums[i] == target) {
            result[1] = i;
            break;
        }
    }

    *returnSize = 2;
    return result;
}

int main() {
    int nums1[] = {5, 7, 7, 8, 8, 10};
    int target1 = 6;
    int size1;

    int* result1 = searchRange(nums1, sizeof(nums1) / sizeof(nums1[0]), target1, &size1);

    printf("Output 1: [%d, %d]\n", result1[0], result1[1]);

    int nums2[] = {5, 7, 7, 8, 8, 10};
    int target2 = 8;
    int size2;

    int* result2 = searchRange(nums2, sizeof(nums2) / sizeof(nums2[0]), target2, &size2);

    printf("Output 2: [%d, %d]\n", result2[0], result2[1]);

    int nums3[] = {5, 7, 7, 8, 8, 10};
    int target3 = 6;
    int size3;

    int* result3 = searchRange(nums3, sizeof(nums3) / sizeof(nums3[0]), target3, &size3);

    printf("Output 3: [%d, %d]\n", result3[0], result3[1]);

    int nums4[] = {};
    int target4 = 0;
    int size4;

    int* result4 = searchRange(nums4, sizeof(nums4) / sizeof(nums4[0]), target4, &size4);

    printf("Output 4: [%d, %d]\n", result4[0], result4[1]);

    return 0;
}
