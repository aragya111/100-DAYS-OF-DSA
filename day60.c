//Check whether a given binary tree satisfies the Min-Heap property.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int isMinHeap(struct Node* root) {
    if (root == NULL) return 1;
    if (root->left && root->left->data < root->data) return 0;
    if (root->right && root->right->data < root->data) return 0;
    return isMinHeap(root->left) && isMinHeap(root->right);
}
int main() {
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 1;
    root->left = (struct Node*)malloc(sizeof(struct Node));
    root->left->data = 2;
    root->right = (struct Node*)malloc(sizeof(struct Node));
    root->right->data = 3;

    if (isMinHeap(root)) {
        printf("The binary tree satisfies the Min-Heap property.\n");
    } else {
        printf("The binary tree does not satisfy the Min-Heap property.\n");
    }
    return 0;
}