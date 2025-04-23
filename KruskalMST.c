#include <stdio.h>
#include <stdlib.h>
#define V 5
#define E 7

struct Edge {
    int src, dest, weight;
};

struct Graph {
    struct Edge edges[E];
};

int parent[V];

int find(int i) {
    while(i != parent[i])
        i = parent[i];
    return i;
}

void unionSets(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    parent[rootA] = rootB;
}

int compareEdges(const void *a, const void *b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void kruskal(struct Graph* graph) {
    for(int i = 0; i < V; i++)
        parent[i] = i;

    qsort(graph->edges, E, sizeof(graph->edges[0]), compareEdges);

    printf("Edge \tWeight\n");

    int count = 0;
    for(int i = 0; i < E && count < V - 1; i++) {
        int u = graph->edges[i].src;
        int v = graph->edges[i].dest;
        int setU = find(u);
        int setV = find(v);

        if(setU != setV) {
            printf("%d - %d \t%d\n", u, v, graph->edges[i].weight);
            unionSets(setU, setV);
            count++;
        }
    }
}

int main() {
    struct Graph graph;

    graph.edges[0] = (struct Edge){0, 1, 10};
    graph.edges[1] = (struct Edge){0, 2, 6};
    graph.edges[2] = (struct Edge){0, 3, 5};
    graph.edges[3] = (struct Edge){1, 3, 15};
    graph.edges[4] = (struct Edge){2, 3, 4};
    graph.edges[5] = (struct Edge){1, 2, 25};
    graph.edges[6] = (struct Edge){3, 4, 2};

    kruskal(&graph);

    return 0;
}
