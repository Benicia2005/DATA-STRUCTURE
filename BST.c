#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node with the given data into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Function to search for a key in the BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    
    return search(root->right, key);
}

// Function to find the minimum element in the BST
struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to find the maximum element in the BST
struct Node* findMax(struct Node* root) {
    while (root->right != NULL)
        root = root->right;
    return root;
}

// Function to in-order traverse the BST
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Main function to test the BST operations
int main() {
    struct Node* root = NULL;

    // Inserting elements into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // In-order traversal to display the elements
    printf("In-order traversal of the BST: ");
    inOrderTraversal(root);
    printf("\n");

    // Search for an element in the BST
    int searchKey = 40;
    struct Node* searchResult = search(root, searchKey);
    if (searchResult != NULL)
        printf("%d found in the BST.\n", searchKey);
    else
        printf("%d not found in the BST.\n", searchKey);

    // Find the minimum element in the BST
    struct Node* minNode = findMin(root);
    printf("Minimum element in the BST: %d\n", minNode->data);

    // Find the maximum element in the BST
    struct Node* maxNode = findMax(root);
    printf("Maximum element in the BST: %d\n", maxNode->data);

    return 0;
}

