//Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void zigzagLevelOrder(struct TreeNode* root) {
    if (!root) return;

    struct TreeNode** currentLevel = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    struct TreeNode** nextLevel = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    int currentLevelSize = 1;
    int nextLevelSize = 0;
    int level = 0;

    currentLevel[0] = root;

    while (currentLevelSize > 0) {
        printf("Level %d: ", level);
        for (int i = 0; i < currentLevelSize; i++) {
            struct TreeNode* node = currentLevel[i];
            printf("%d ", node->val);
            if (node->left) {
                nextLevel[nextLevelSize++] = node->left;
            }
            if (node->right) {
                nextLevel[nextLevelSize++] = node->right;
            }
        }
        printf("\n");
        struct TreeNode** temp = currentLevel;
        currentLevel = nextLevel;
        nextLevel = temp;
        currentLevelSize = nextLevelSize;
        nextLevelSize = 0;
        level++;
    }

    free(currentLevel);
    free(nextLevel);
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

    zigzagLevelOrder(root);
    return 0;
}