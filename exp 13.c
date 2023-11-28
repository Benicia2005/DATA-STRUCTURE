#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode* next;
};

int main() {
    // Create linked list nodes: 6, 7, 8, 9
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 6;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 7;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 8;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 9;
    head->next->next->next->next = NULL;

    // Display linked list: 6->7->8->9
    printf("Nodes: ");
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d", current->val);

        if (current->next != NULL) {
            printf("->");
        }

        current = current->next;
    }

    printf("\n");

    // Free allocated memory
    current = head;
    struct ListNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}

