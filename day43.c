//Construct a Binary Tree from the given level-order traversal.
#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
TreeNode* constructBinaryTree(int* levelOrder, int size) {
    if (size == 0) return NULL;
    TreeNode* root = createNode(levelOrder[0]);
    Queue *q = queue_create(size);
    queue_enqueue(q, (int)(intptr_t)root);
    int index = 1;
    while (index < size) {
        TreeNode* current;
        queue_dequeue(q, (int*)&current);
        if (index < size) {
            current->left = createNode(levelOrder[index++]);
            queue_enqueue(q, (int)(intptr_t)current->left);
        }
        if (index < size) {
            current->right = createNode(levelOrder[index++]);
            queue_enqueue(q, (int)(intptr_t)current->right);
        }
    }
    queue_destroy(q);
    return root;
}
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right
);
}
int main() {
    int levelOrder[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(levelOrder) / sizeof(levelOrder[0]);
    TreeNode* root = constructBinaryTree(levelOrder, size);
    printf("Inorder Traversal of the constructed binary tree: ");
    inorderTraversal(root);
    printf("\n");
    return 0;
}
