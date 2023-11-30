#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to check if a binary tree is a BST
bool isBST(struct TreeNode* root, struct TreeNode* min, struct TreeNode* max) {
    if (root == NULL) {
        return true;
    }

    // Check if the current node's value is within the valid range
    if ((min != NULL && root->value <= min->value) || (max != NULL && root->value >= max->value)) {
        return false;
    }

    // Recursively check the left and right subtrees
    return isBST(root->left, min, root) && isBST(root->right, root, max);
}

// Helper function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // Example 1
    struct TreeNode* root1 = createNode(2);
    root1->left = createNode(1);
    root1->right = createNode(3);
    
    // Example 2
    struct TreeNode* root2 = createNode(2);
    root2->right = createNode(7);
    root2->right->right = createNode(6);
    root2->right->right->right = createNode(5);
    root2->right->right->right->right = createNode(9);
    root2->right->right->right->right->right = createNode(2);
    root2->right->right->right->right->right->right = createNode(6);

    // Check if the trees are BSTs
    if (isBST(root1, NULL, NULL)) {
        printf("Example 1 is a BST.\n");
    } else {
        printf("Example 1 is not a BST.\n");
    }

    if (isBST(root2, NULL, NULL)) {
        printf("Example 2 is a BST.\n");
    } else {
        printf("Example 2 is not a BST.\n");
    }

    // Free memory
    free(root1);
    free(root2);

    return 0;
}
