//Detect cycle in directed graph using DFS and recursion stack.
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


bool isCyclicUtil(Graph* graph, int v, bool visited[], bool recStack[]) {
    if (!visited[v]) {
        
        visited[v] = true;
        recStack[v] = true;

        
        Node* temp = graph->array[v].head;
        while (temp != NULL) {
            int neighbour = temp->vertex;
            if (!visited[neighbour] && isCyclicUtil(graph, neighbour, visited, recStack))
                return true;
            else if (recStack[neighbour])
                return true;
            temp = temp->next;
        }
    }
    recStack[v] = false; 
    return false;
}


bool isCyclic(Graph* graph) {
    bool* visited = (bool*)calloc(graph->V, sizeof(bool));
    bool* recStack = (bool*)calloc(graph->V, sizeof(bool));

    for (int i = 0; i < graph->V; i++) {
        if (isCyclicUtil(graph, i, visited, recStack))
            return true;
    }
    return false;
}


int main() {
    int V = 4;
    Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0); 
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3); 

    if (isCyclic(graph))
        printf("Graph contains cycle\n");
    else
        printf("Graph does not contain cycle\n");

    return 0;
}

