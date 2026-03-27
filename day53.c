//Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct VerticalNode {
    int val;
    int hd; 
    struct VerticalNode* next;
};
struct VerticalNode* verticalHead = NULL;
void insertVerticalNode(int val, int hd) {
    struct VerticalNode* newNode = (struct VerticalNode*)malloc(sizeof(struct VerticalNode));
    newNode->val = val;
    newNode->hd = hd;
    newNode->next = NULL;
    if (verticalHead == NULL) {
        verticalHead = newNode;
        return;
    }
    struct VerticalNode* temp = verticalHead;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void verticalOrderTraversal(struct TreeNode* root, int hd) {
    if (root == NULL) {
        return;
    }
    insertVerticalNode(root->val, hd);
    verticalOrderTraversal(root->left, hd - 1);
    verticalOrderTraversal(root->right, hd + 1);
}
void printVerticalOrder() {
    struct VerticalNode* temp = verticalHead;
    while (temp != NULL) {
        printf("Vertical Line %d: %d\n", temp->hd, temp->val);
        temp = temp->next;
    }
}
int main() {
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 2;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 3;
    root->left->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->left->val = 4;
    root->left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->right->val = 5;

    verticalOrderTraversal(root, 0);
    printVerticalOrder();
    return 0;
}
