//Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 100

int minKey(int key[], bool mstSet[], int n) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int primMST(int graph[V][V], int n) {
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;  
    int totalWeight = 0;

    for (int count = 0; count < n; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = true;

        totalWeight += key[u];

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}





















