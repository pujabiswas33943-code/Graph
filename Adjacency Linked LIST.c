#include<stdio.h>
#include<stdlib.h>

struct node{
  int vertex;
  int cost;
  struct node *next;
};
void addEdge(struct node **head,int v,int cost)
{

    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->vertex=v;
    newnode->cost=cost;
    newnode->next=*head;
    *head=newnode;
}

int main()
{
         int v,e;
         printf("Enter number of vertex:");
         scanf("%d", &v);
         struct node *adj[v+1];
         for(int i=1;i<=v;i++)
         adj[i]=NULL;
       printf("Enter number of edges:");
       scanf("%d", &e);
       int x ,y,cost;
       for(int i=1;i<=e;i++){
            printf("Enter edge(x y & cost):");
       scanf("%d %d %d",&x,&y,&cost);
       addEdge(&adj[x],y,cost);
       addEdge(&adj[y],x,cost);
       }

printf("\nAdjacency List:\n");
for(int i=1;i<=v;i++){
    printf("%d ",i);
struct node *temp=adj[i];
while(temp){
    printf("%d(%d) ",temp->vertex,temp->cost);
    temp=temp->next;

}
printf("\n");
}
return 0;
                  }
