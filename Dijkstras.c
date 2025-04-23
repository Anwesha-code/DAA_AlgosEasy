#include <stdio.h>
#include <limits.h>
#define V 5

int MinDistance(int dist[], int visited[]) {
    int min = INT_MAX, MinIndex;

    for (int i = 0; i< V; i++) {
        if (visited[i] == 0 && dist[i] <= min) {
            min = dist[i];
            MinIndex = i;
        }
    }
    return MinIndex;
}

void dijkstra(int graph[V][V], int source) {
    int dist[V];
    int visited[V];

    for (int i = 0; i< V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (int count = 0; count< V - 1; count++) {
        int u = MinDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 0, 5},
        {0, 0, 1, 0, 2},
        {0, 0, 0, 4, 0},
        {7, 0, 6, 0, 0},
        {0, 3, 9, 2, 0}
    };
    dijkstra(graph, 0);
    return 0;
}
