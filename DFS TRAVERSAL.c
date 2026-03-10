#include <stdio.h>

#define N 5
int adj[N+1][N+1];
int visited[N+1];
int parent[N+1];
int cycleFound = 0;


void DFS(int u)
{
    visited[u] = 1;

    for(int v = 1; v <= N; v++)
    {
        if(adj[u][v] != 0)
        {
            if(!visited[v])
            {
                parent[v] = u;
                DFS(v);
            }
            else if(parent[u] != v)
            {
                cycleFound = 1;
            }
        }
    }
}

int main()
{
    int i, j;


    for(i = 1; i <= N; i++)
        for(j = 1; j <= N; j++)
            adj[i][j] = 0;


    adj[1][2] = adj[2][1] = 7;   // A-B
    adj[1][4] = adj[4][1] = 4;   // A-D
    adj[4][5] = adj[5][4] = 6;   // D-E
    adj[5][3] = adj[3][5] = 6;   // E-C
    adj[2][3] = adj[3][2] = 3;   // B-C
    adj[1][3] = adj[3][1] = 8;   // A-C


    printf("Adjacency Matrix:\n");
    for(i = 1; i <= N; i++)
    {
        for(j = 1; j <= N; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }


    for(i = 1; i <= N; i++)
    {
        visited[i] = 0;
        parent[i] = -1;
    }


    for(i = 1; i <= N; i++)
    {
        if(!visited[i])
            DFS(i);
    }

    if(cycleFound)
        printf("\nCycle detected in the graph\n");
    else
        printf("\nNo cycle in the graph\n");

    return 0;
}
