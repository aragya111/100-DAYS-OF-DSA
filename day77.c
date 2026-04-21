//Using BFS or DFS, check if the entire graph is connected.
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100


void BFS(int graph[MAX_VERTICES][MAX_VERTICES], int start, int visited[MAX_VERTICES], int numVertices) {
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int current = queue[front++];
        for (int i = 0; i < numVertices; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}


int isGraphConnected(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int visited[MAX_VERTICES] = {0};
    BFS(graph, 0, visited, numVertices);

    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &numVertices, &numEdges);

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("Enter the edges (u v): ");
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; 
    }

    if (isGraphConnected(graph, numVertices)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}