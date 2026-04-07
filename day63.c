//Perform DFS starting from a given source vertex using recursion.
#include <stdio.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
void DFS(int vertex, int numVertices) {
    visited[vertex] = 1;
    printf("Visited vertex: %d\n", vertex);
    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i, numVertices);
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
    printf("DFS starting from vertex %d:\n", sourceVertex);
    DFS(sourceVertex, numVertices);
    return 0;
}
