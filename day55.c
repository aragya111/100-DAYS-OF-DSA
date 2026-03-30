//Print the nodes visible when the binary tree is viewed from the right side.
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

void printRightView(struct Node* root, int level, int* maxLevel) {
    if (root == NULL) return;

    if (level > *maxLevel) {
        printf("%d ", root->data);
        *maxLevel = level;
    }

    printRightView(root->right, level + 1, maxLevel);
    printRightView(root->left, level + 1, maxLevel);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int maxLevel = -1;
    printf("Right view of the binary tree: ");
    printRightView(root, 0, &maxLevel);

    return 0;
}
            