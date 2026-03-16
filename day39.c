
#include <stdio.h>
#define MAX 100
int minHeap[MAX];
int size = 0;
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyUp(int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (minHeap[index] < minHeap[parentIndex]) {
            swap(&minHeap[index], &minHeap[parentIndex]);
            index = parentIndex;
        } else {
            break;
        }
    }
}
void insert(int data) {
    if (size >= MAX) {
        printf("Min Heap overflow! Cannot insert %d\n", data);
        return;
    }
    minHeap[size] = data;
    heapifyUp(size);
    size++;
    printf("Inserted %d into the min heap.\n", data);
}
void display() {
    if (size == 0) {
        printf("Min Heap is empty.\n");
        return;
    }
    printf("Min Heap elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", minHeap[i]);
    }
    printf("\n");
}
int main() {
    insert(5);
    insert(3);
    insert(8);
    insert(1);
    display();
    return 0;
}
