//Using DFS and parent tracking, detect if undirected graph has a cycle.
#include <stdio.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
int parent[MAX];
int hasCycle(int vertex, int parentVertex, int numVertices) {
    visited[vertex] = 1;
    parent[vertex] = parentVertex;
    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] == 1) {
            if (!visited[i]) {
                if (hasCycle(i, vertex, numVertices)) {
                    return 1; 
                }
            } else if (i != parentVertex) {
                return 1; 
            }
        }
    }
    return 0; 
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

    int cycleExists = hasCycle(0, -1, numVertices);
    if (cycleExists) {
        printf("The undirected graph has a cycle.\n");
    } else {
        printf("The undirected graph does not have a cycle.\n");
    }
    return 0;
}

            