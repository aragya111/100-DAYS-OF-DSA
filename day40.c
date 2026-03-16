//Implement Heap Sort using a Max Heap to sort an array in ascending order. First build a max heap, then repeatedly extract the maximum element and place it at the end of the array.
#include <stdio.h>
#define MAX 100
int maxHeap[MAX];
int size = 0;
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyDown(int index) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < size && maxHeap[leftChild] > maxHeap[largest]) {
        largest = leftChild;
    }
    if (rightChild < size && maxHeap[rightChild] > maxHeap[largest]) {
        largest = rightChild;
    }
    if (largest != index) {
        swap(&maxHeap[index], &maxHeap[largest]);
        heapifyDown(largest);
    }
}
void buildMaxHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        maxHeap[size++] = arr[i];
    }
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapifyDown(i);
    }
}

void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n);
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = maxHeap[0]; 
        maxHeap[0] = maxHeap[--size]; 
        heapifyDown(0); 
    }
}
int main() {
    int arr[MAX], n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    heapSort(arr, n);
    printf("Sorted array in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
    