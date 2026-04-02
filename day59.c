//Construct a binary tree from given inorder and postorder traversal arrays.
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

struct TreeNode* buildTreeUtil(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    struct TreeNode* node = newNode(postorder[*postIndex]);
    (*postIndex)--;

    if (inStart == inEnd) {
        return node;
    }

    int inIndex = search(inorder, inStart, inEnd, node->val);

    node->right = buildTreeUtil(inorder, postorder, inIndex + 1, inEnd, postIndex);
    node->left = buildTreeUtil(inorder, postorder, inStart, inIndex - 1, postIndex);

    return node;
}

struct TreeNode* buildTree(int inorder[], int postorder[], int n) {
    int postIndex = n - 1;
    return buildTreeUtil(inorder, postorder, 0, n - 1, &postIndex);
}

void printInorder(struct TreeNode* root) {
    if (root != NULL) {
        printInorder(root->left);
        printf("%d ", root->val);
        printInorder(root->right);
    }
}
int main() {
    int inorder[] = {4, 2, 5, 1, 3};
    int postorder[] = {4, 5, 2, 3, 1};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    struct TreeNode* root = buildTree(inorder, postorder, n);

    printf("Inorder traversal of the constructed tree: ");
    printInorder(root);
    printf("\n");

    return 0;
}