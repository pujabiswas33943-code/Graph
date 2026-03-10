#include <stdio.h>
#include <stdlib.h>

#define N 5  // Node sonkhya

int adj[N+1][N+1]; // Adjacency Matrix
int visited[N+1];
int queue[N+1];
int front = 0, rear = -1;

// Queue-te element add kora
void enqueue(int v) {
    queue[++rear] = v;
}

// Queue theke element ber kora
int dequeue() {
    return queue[front++];
}

// Check kora queue khali kina
int isQueueEmpty() {
    return front > rear;
}

void BFS(int startNode) {
    visited[startNode] = 1;
    enqueue(startNode);

    printf("BFS Traversal: ");

    while (!isQueueEmpty()) {
        int u = dequeue();
        printf("%d ", u);

        for (int v = 1; v <= N; v++) {
            // Jodi edge thake ebong node-ti age visit na hoye thake
            if (adj[u][v] != 0 && !visited[v]) {
                visited[v] = 1;
                enqueue(v);
            }
        }
    }
    printf("\n");
}

int main() {
    // Adjacency Matrix initialize kora
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            adj[i][j] = 0;
            visited[i] = 0;
        }
    }

    // Graph-er Edges (Ager example onujayi)
    adj[1][2] = adj[2][1] = 1; // A-B
    adj[1][4] = adj[4][1] = 1; // A-D
    adj[4][5] = adj[5][4] = 1; // D-E
    adj[5][3] = adj[3][5] = 1; // E-C
    adj[2][3] = adj[3][2] = 1; // B-C

    // BFS shuru hobe node 1 (A) theke
    BFS(1);

    return 0;
}
