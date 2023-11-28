#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int kthSmallest(struct Node* root, int* k) {
    if (root == NULL) {
        return -1;
    }

    int left = kthSmallest(root->left, k);

    if (*k == 0) {
        return left; // Kth smallest found in the left subtree
    }

    (*k)--;

    if (*k == 0) {
        return root->data; // Kth smallest found at the current node
    }

    int right = kthSmallest(root->right, k);

    return (right != -1) ? right : -1; // If Kth smallest is not found in the right subtree
}

int main() {
    struct Node* root = malloc(sizeof(struct Node));
    root->data = 4;
    root->left = malloc(sizeof(struct Node));
    root->left->data = 2;
    root->left->left = malloc(sizeof(struct Node));
    root->left->left->data = 1;
    root->left->left->left = root->left->left->right = NULL;
    root->left->right = malloc(sizeof(struct Node));
    root->left->right->data = 3;
    root->left->right->left = root->left->right->right = NULL;

    root->right = malloc(sizeof(struct Node));
    root->right->data = 5;
    root->right->left = root->right->right = NULL;

    int k;
    printf("Enter the value of K: ");
    scanf("%d", &k);

    int result = kthSmallest(root, &k);

    if (result != -1) {
        printf("The %dth smallest element in the BST is: %d\n", k + 1, result);
    } else {
        printf("Invalid value of K\n");
    }

    return 0;
}
