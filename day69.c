//Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;
typedef struct {
    Node* head;
} AdjList;
Node* createNode(int vertex, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}
void addEdge(AdjList adjList[], int src, int dest, int weight) {
    Node* newNode = createNode(dest, weight);
    newNode->next = adjList[src].head;
    adjList[src].head = newNode;
}
void dijkstra(AdjList adjList[], int vertices, int source) {
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};
    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;
    for (int count = 0; count < vertices - 1; count++) {
        int minDist = INT_MAX, minIndex;
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && dist[v] <= minDist) {
                minDist = dist[v];
                minIndex = v;
            }
        }
        visited[minIndex] = 1;
        Node* temp = adjList[minIndex].head;
        while (temp != NULL) {
            int vertex = temp->vertex;
            int weight = temp->weight;
            if (!visited[vertex] && dist[minIndex] != INT_MAX && dist[minIndex] + weight < dist[vertex]) {
                dist[vertex] = dist[minIndex] + weight;
            }
            temp = temp->next;
        }
    }
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}
int main() {
    AdjList adjList[MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++) {
        adjList[i].head = NULL;
    }
    addEdge(adjList, 0, 1, 4);
    addEdge(adjList, 0, 2, 1);
    addEdge(adjList, 1, 2, 2);
    addEdge(adjList, 1, 3, 5);
    addEdge(adjList, 2, 3, 8);
    int source = 0;
    dijkstra(adjList, 4, source);
    return 0;
}

