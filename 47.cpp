#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* mergeLists(struct Node* a, struct Node* b) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (a != NULL && b != NULL) {
        if (a->data < b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    tail->next = (a != NULL) ? a : b;

    return dummy.next;
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int main() {
    struct Node* a = newNode(5); a->next = newNode(10); a->next->next = newNode(15);
    struct Node* b = newNode(2); b->next = newNode(3); b->next->next = newNode(20);

    printf("Input 1:\nList a: "); printList(a);
    printf("List b: "); printList(b);

    struct Node* mergedList = mergeLists(a, b);

    printf("\nOutput 1:\nMerged List: "); printList(mergedList);

    // Free allocated memory
    while (mergedList != NULL) {
        struct Node* temp = mergedList;
        mergedList = mergedList->next;
        free(temp);
    }

    // Example 2
    struct Node* a2 = newNode(1); a2->next = newNode(1);
    struct Node* b2 = newNode(2); b2->next = newNode(4);

    printf("\nInput 2:\nList a: "); printList(a2);
    printf("List b: "); printList(b2);

    struct Node* mergedList2 = mergeLists(a2, b2);

    printf("\nOutput 2:\nMerged List: "); printList(mergedList2);

    // Free allocated memory
    while (mergedList2 != NULL) {
        struct Node* temp = mergedList2;
        mergedList2 = mergedList2->next;
        free(temp);
    }

    return 0;
}
