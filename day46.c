//Level Order Traversal
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct QueueNode {
    struct TreeNode* tree_node;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, struct TreeNode* tree_node) {
    struct QueueNode* new_node = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    new_node->tree_node = tree_node;
    new_node->next = NULL;

    if (queue->rear == NULL) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

struct TreeNode* dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        return NULL;
    }

    struct QueueNode* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    struct TreeNode* tree_node = temp->tree_node;
    free(temp);
    return tree_node;
}

int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    struct Queue* queue = createQueue();
    enqueue(queue, root);

    int** result = (int**)malloc(sizeof(int*) * 1000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000);
    *returnSize = 0;

    while (!isEmpty(queue)) {
        int level_size = 0;
        struct TreeNode* current = dequeue(queue);
        level_size++;

        if (current->left != NULL) {
            enqueue(queue, current->left);
        }
        if (current->right != NULL) {
            enqueue(queue, current->right);
        }

        (*returnColumnSizes)[(*returnSize)] = level_size;
        result[(*returnSize)] = (int*)malloc(sizeof(int) * level_size);
        
        for (int i = 0; i < level_size; i++) {
            current = dequeue(queue);
            result[(*returnSize)][i] = current->val;

            if (current->left != NULL) {
                enqueue(queue, current->left);
            }
            if (current->right != NULL) {
                enqueue(queue, current->right);
            }
        }
        
        (*returnSize)++;
    }
    return result;
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

    int returnSize;
    int* returnColumnSizes;
    int** result = levelOrder(root, &returnSize, &returnColumnSizes);

    printf("Level Order Traversal:\n");
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);
    
    return 0;
}   