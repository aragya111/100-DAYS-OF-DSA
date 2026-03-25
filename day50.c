//BST Search
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}
int search(struct TreeNode* root, int val) {
    if (root == NULL) {
        return 0; 
    }
    if (root->val == val) {
        return 1; 
    }
    if (val < root->val) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}
int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    int valToSearch = 4;
    if (search(root, valToSearch)) {
        printf("Value %d found in the BST.\n", valToSearch);
    } else {
        printf("Value %d not found in the BST.\n", valToSearch);
    }
    return 0;
}
