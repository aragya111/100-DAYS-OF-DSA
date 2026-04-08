//Perform BFS from a given source using queue.
#include <stdio.h>
#define MAX 100 
int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue(int vertex) {
    if (rear >= MAX - 1) {
        printf("Queue overflow! Cannot enqueue vertex %d\n", vertex);
        return;
    }
    if (front == -1) {
        front = 0; 
    }
    queue[++rear] = vertex;
}
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow! Cannot dequeue from an empty queue.\n");
        return -1; 
    }
    return queue[front++];
}
void BFS(int sourceVertex, int numVertices) {
    visited[sourceVertex] = 1;
    enqueue(sourceVertex);
    while (front <= rear) {
        int currentVertex = dequeue();
        printf("Visited vertex: %d\n", currentVertex);
        for (int i = 0; i < numVertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}
int main() {
    int numVertices = 5;
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][0] = 1;
    graph[1][3] = 1;
    graph[2][0] = 1;
    graph[2][4] = 1;
    graph[3][1] = 1;
    graph[4][2] = 1;

    int sourceVertex = 0;
    printf("BFS starting from vertex %d:\n", sourceVertex);
    BFS(sourceVertex, numVertices);
    return 0;
}
