#include <stdio.h>
#define MAX 100
int deque[MAX];
int front = -1;
int rear = -1;
void insertFront(int data) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque overflow! Cannot insert %d at the front\n", data);
        return;
    }
    if (front == -1) {
        front = rear = 0; 
    } else if (front == 0) {
        front = MAX - 1; 
    } else {
        front--;
    }
    deque[front] = data;
    printf("Inserted %d at the front of the deque.\n", data);
}
void insertRear(int data) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque overflow! Cannot insert %d at the rear\n", data);
        return;
    }
    if (front == -1) {
        front = rear = 0; 
    } else if (rear == MAX - 1) {
        rear = 0; 
    } else {
        rear++;
    }
    deque[rear] = data;
    printf("Inserted %d at the rear of the deque.\n", data);
}

void deleteFront() {
    if (front == -1) {
        printf("Deque underflow! Cannot delete from the front\n");
        return;
    }
    int deletedData = deque[front];
    if (front == rear) {
        front = rear = -1; 
    } else if (front == MAX - 1) {
        front = 0; 
    } else {
        front++;
    }
    printf("Deleted %d from the front of the deque.\n", deletedData);
}
void deleteRear() {
    if (rear == -1) {
        printf("Deque underflow! Cannot delete from the rear\n");
        return;
    }
    int deletedData = deque[rear];
    if (front == rear) {
        front = rear = -1; 
    } else if (rear == 0) {
        rear = MAX - 1; 
    } else {
        rear--;
    }
    printf("Deleted %d from the rear of the deque.\n", deletedData);
}
void display() {
    if (front == -1) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertFront(1);
    display();
    deleteFront();
    display();
    deleteRear();
    display();
    deleteFront();
    deleteRear();
    deleteFront(); 
    return 0;
}
