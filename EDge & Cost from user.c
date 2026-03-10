#include<stdio.h>
int main(){
int v,e;
printf("Enter number of vertices:");
scanf("%d" ,&v);
int adj[v][v];
for(int i=0;i<v;i++)
{
    for(int j=0;j<v;j++)
    {
        adj[i][j]=0;
    }
}
printf("Enter number of edges: ");
scanf("%d", &e);
int x,y,cost;
for(int i=0;i<e;i++){
    printf("\nEnter edge(u v cost):");
    scanf("%d %d %d" ,&x,&y,&cost);
    adj[x][y]=cost;
    adj[y][x]=cost;

}

printf("Adjacency Matrix\n");
for(int i=0;i<v;i++)
{
    for(int j=0;j<v;j++)
    {
        printf("%3d ", adj[i][j]);
    }
printf("\n");
}
return 0;
}
