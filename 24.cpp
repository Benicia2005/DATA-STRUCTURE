#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new binary tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the maximum depth of a binary tree
int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    // Recursively calculate the depth of the left and right subtrees
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    // Return the maximum depth of the left and right subtrees, plus 1 for the current level
    return 1 + max(leftDepth, rightDepth);
}

int main() {
    // Example usage
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Calculate and print the maximum depth of the binary tree
    printf("Maximum Depth of the Binary Tree: %d\n", maxDepth(root));

    // Free allocated memory (not necessary for the example)
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
