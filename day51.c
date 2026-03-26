//Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }
    if (n1 < root->data && n2 < root->data) {
        return findLCA(root->left, n1, n2);
    }
    if (n1 > root->data && n2 > root->data) {
        return findLCA(root->right, n1, n2);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);

    struct Node* lca = findLCA(root, 5, 15);
    if (lca != NULL) {
        printf("LCA of 5 and 15 is %d\n", lca->data);
    }

    return 0;
}
