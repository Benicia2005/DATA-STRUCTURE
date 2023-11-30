#include<stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to count the number of nodes in a linked list
int countNodes(struct ListNode* head) {
    int count = 0;
    struct ListNode* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

// Example usage
int main() {
    // Create a linked list: 1->2->3->5->8
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 5;
    head->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 8;
    head->next->next->next->next->next = NULL;

    // Count the number of nodes
    int result = countNodes(head);

    // Print the result
    printf("Number of nodes: %d\n", result);

    // Free allocated memory
    struct ListNode* current = head;
    struct ListNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
