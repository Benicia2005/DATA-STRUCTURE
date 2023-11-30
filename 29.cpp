#include <stdio.h>
#include <stdlib.h>

// Definition for a person
struct Person {
    int height;
    int k;
};

// Custom comparison function for sorting
int compare(const void *a, const void *b) {
    const struct Person *p1 = (const struct Person *)a;
    const struct Person *p2 = (const struct Person *)b;

    // Sort by height in descending order
    // If height is the same, sort by k in ascending order
    if (p1->height != p2->height) {
        return p2->height - p1->height;
    } else {
        return p1->k - p2->k;
    }
}

// Function to reconstruct the queue
struct Person* reconstructQueue(struct Person* people, int peopleSize, int* returnSize) {
    // Sort people array
    qsort(people, peopleSize, sizeof(struct Person), compare);

    // Reconstruct the queue
    struct Person *result = (struct Person *)malloc(peopleSize * sizeof(struct Person));
    for (int i = 0; i < peopleSize; i++) {
        // Insert the person at their k position
        for (int j = i; j > people[i].k; j--) {
            result[j] = result[j - 1];
        }
        result[people[i].k] = people[i];
    }

    *returnSize = peopleSize;
    return result;
}

// Function to print the reconstructed queue
void printQueue(struct Person* queue, int size) {
    for (int i = 0; i < size; i++) {
        printf("(%d, %d) ", queue[i].height, queue[i].k);
    }
    printf("\n");
}

int main() {
    // Example usage
    struct Person people[] = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    int peopleSize = sizeof(people) / sizeof(people[0]);

    int returnSize;
    struct Person *result = reconstructQueue(people, peopleSize, &returnSize);

    printf("Reconstructed Queue: ");
    printQueue(result, returnSize);

    // Free allocated memory
    free(result);

    return 0;
}
