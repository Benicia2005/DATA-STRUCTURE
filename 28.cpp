#include <stdio.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *ptrA = headA;
    struct ListNode *ptrB = headB;

    while (ptrA != ptrB) {
        // Move pointers to the next node
        ptrA = (ptrA == NULL) ? headB : ptrA->next;
        ptrB = (ptrB == NULL) ? headA : ptrB->next;
    }

    return ptrA; // Intersection point or NULL if no intersection
}

// Example usage
int main() {
    // Create linked lists
    // A: 1 -> 2 -> 3 \
    //                  6 -> 7 -> 8
    // B: 4 -> 5 /
    struct ListNode node1 = {1, NULL};
    struct ListNode node2 = {2, NULL};
    struct ListNode node3 = {3, NULL};
    struct ListNode node4 = {4, NULL};
    struct ListNode node5 = {5, NULL};
    struct ListNode node6 = {6, NULL};
    struct ListNode node7 = {7, NULL};
    struct ListNode node8 = {8, NULL};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node6;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;
    node7.next = &node8;

    struct ListNode *result = getIntersectionNode(&node1, &node4);
    if (result != NULL) {
        printf("Intersection node value: %d\n", result->val);
    } else {
        printf("No intersection\n");
    }

    return 0;
}
