//Build a graph with n vertices and m edges using adjacency matrix representation.
#include <stdio.h>
#define MAX 100
int graph[MAX][MAX];
void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1; 
}
void displayGraph(int n) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    displayGraph(n);
    return 0;
}
