//Implement a Queue using a linked list supporting enqueue and dequeue operations.
#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Queue {
    struct Node *front, *rear;
};


struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}


void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

   
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    
    q->rear->next = newNode;
    q->rear = newNode;
}


int dequeue(struct Queue* q) {
   
    if (q->front == NULL) {
        printf("Queue Underflow\n");
        return -1;
    }

    struct Node* temp = q->front;
    int value = temp->data;

    
    q->front = q->front->next;

    
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return value;
}


void display(struct Queue* q) {
    struct Node* temp = q->front;
    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    struct Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    display(q);

    printf("Dequeued: %d\n", dequeue(q));
    display(q);

    return 0;
}