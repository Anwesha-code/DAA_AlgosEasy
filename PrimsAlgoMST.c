#include <stdio.h>
#include <limits.h>
#define V 5

int MinKey(int key[], int MSTset[]) {
    int min = INT_MAX, MinIndex;

    for(int v = 0; v< V; v++) {
        if(MSTset[v] == 0 && key[v] < min) {
            min = key[v];
            MinIndex = v;
        }
    }

    return MinIndex;
}

void print(int parent[], int graph[V][V]) {
    printf("Edge\tWeight\n");
    for(int i = 1; i< V; i++)
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
}

void prims(int graph[V][V]) {
    int parent[V];
    int key[V];
    int MSTset[V];

    for(int i = 0; i< V; i++) {
        key[i] = INT_MAX;
        MSTset[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int count = 0; count< V - 1; count++) {
        int u = MinKey(key, MSTset);
        MSTset[u] = 1;

        for(int v = 0; v< V; v++) {
            if(graph[u][v] && MSTset[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    print(parent, graph);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    prims(graph);

    return 0;
}
