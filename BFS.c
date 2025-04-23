#include <stdio.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear){
      return -1;
    }
    return queue[front++];
}

void bfs(int graph[MAX][MAX], int n, int start) {
    for (int i = 0; i < n; i++) visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int graph[MAX][MAX], n, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("BFS traversal: ");
    bfs(graph, n, start);

    return 0;
}
