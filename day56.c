//Check whether a given binary tree is symmetric around its center.

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
int isSymmetric(struct Node* left, struct Node* right) {
    if (left == NULL && right == NULL) return 1;
    if (left == NULL || right == NULL) return 0;
    if (left->data != right->data) return 0;
    return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
}
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    if (isSymmetric(root->left, root->right)) {
        printf("The binary tree is symmetric.\n");
    } else {
        printf("The binary tree is not symmetric.\n");
    }
    return 0;
}
