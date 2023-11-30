#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct TreeNode {
    int val;
    struct TreeNode* children[MAX_NODES];
} TreeNode;

TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = value;
    for (int i = 0; i < MAX_NODES; ++i) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

int findLowestCommonAncestor(TreeNode* root, int node1, int node2) {
    if (!root || root->val == node1 || root->val == node2) {
        return root ? root->val : -1;
    }

    int count = 0;
    int childrenLCA[MAX_NODES] = {0};

    for (int i = 0; i < MAX_NODES && root->children[i]; ++i) {
        int childLCA = findLowestCommonAncestor(root->children[i], node1, node2);
        if (childLCA != -1) {
            childrenLCA[count++] = childLCA;
        }
    }

    return (count == 2) ? root->val : ((count == 1) ? childrenLCA[0] : -1);
}

int findDistanceToNode(TreeNode* root, int target) {
    if (!root) {
        return -1;
    }

    if (root->val == target) {
        return 0;
    }

    for (int i = 0; i < MAX_NODES && root->children[i]; ++i) {
        int distance = findDistanceToNode(root->children[i], target);
        if (distance >= 0) {
            return distance + 1;
        }
    }

    return -1;
}

void closestNodes(TreeNode* root, int queries[][3], int queriesSize, int* result) {
    for (int i = 0; i < queriesSize; ++i) {
        int start = queries[i][0];
        int end = queries[i][1];
        int node = queries[i][2];

        int lcaNode = findLowestCommonAncestor(root, start, end);
        int distanceToLca = findDistanceToNode(createNode(lcaNode), node);
        int distanceToStart = findDistanceToNode(root, start);
        int distanceToEnd = findDistanceToNode(root, end);

        int minDistance = (distanceToLca < distanceToStart) ? distanceToLca : distanceToStart;
        minDistance = (minDistance < distanceToEnd) ? minDistance : distanceToEnd;

        result[i] = (minDistance == distanceToLca) ? lcaNode : ((minDistance == distanceToStart) ? start : end);
    }
}

int main() {
    int n1 = 7;
    int edges1[][2] = {{0,1},{0,2},{0,3},{1,4},{2,5},{2,6}};
    int query1[][3] = {{5,3,4},{5,3,6}};
    int result1[2];

    TreeNode* root1 = createNode(0);
    root1->children[0] = createNode(1);
    root1->children[1] = createNode(2);
    root1->children[2] = createNode(3);
    root1->children[0]->children[0] = createNode(4);
    root1->children[1]->children[0] = createNode(5);
    root1->children[1]->children[1] = createNode(6);

    closestNodes(root1, query1, 2, result1);

    printf("Output 1: [%d, %d]\n", result1[0], result1[1]);

    int n2 = 3;
    int edges2[][2] = {{0,1},{1,2}};
    int query2[][3] = {{0,1,2}};
    int result2[1];

    TreeNode* root2 = createNode(0);
    root2->children[0] = createNode(1);
    root2->children[0]->children[0] = createNode(2);

    closestNodes(root2, query2, 1, result2);

    printf("Output 2: [%d]\n", result2[0]);

    int n3 = 3;
    int edges3[][2] = {{0,1},{1,2}};
    int query3[][3] = {{0,0,0}};
    int result3[1];

    TreeNode* root3 = createNode(0);
    root3->children[0] = createNode(1);
    root3->children[0]->children[0] = createNode(2);

    closestNodes(root3, query3, 1, result3);

    printf("Output 3: [%d]\n", result3[0]);

    // Free allocated memory
    free(root1);
    free(root2);
    free(root3);

    return 0;
}
