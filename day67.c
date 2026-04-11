// Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;
typedef struct {
    Node* head;
} AdjList;
typedef struct {
    int V;
    AdjList* array;
} Graph;
Node* newNode(int vertex) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = vertex;
    node->next = NULL;
    return node;
}
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));
    for (int i = 0; i < V; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}
void addEdge(Graph* graph, int src, int dest) {
    Node* node = newNode(dest);
    node->next = graph->array[src].head;
    graph->array[src].head = node;
}
void topologicalSortUtil(Graph* graph, int v, bool visited[], int* stack, int* top) {
    visited[v] = true;
    Node* temp = graph->array[v].head;
    while (temp != NULL) {
        int neighbour = temp->vertex;
        if (!visited[neighbour]) {
            topologicalSortUtil(graph, neighbour, visited, stack, top);
        }
        temp = temp->next;
    }
    stack[(*top)++] = v; 
}
void topologicalSort(Graph* graph) {
    bool* visited = (bool*)malloc(graph->V * sizeof(bool));
    for (int i = 0; i < graph->V; i++) {
        visited[i] = false;
    }
    int* stack = (int*)malloc(graph->V * sizeof(int));
    int top = 0;
    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(graph, i, visited, stack, &top);
        }
    }
    printf("Topological Sort: ");
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
int main() {
    Graph* graph = createGraph(6);
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);
    topologicalSort(graph);
    return 0;
}
        