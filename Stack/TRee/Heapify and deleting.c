#include<stdio.h>
void heapify(int heap[ ],int n,int i)
{
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && heap[left]>heap[largest])
        largest=left;
        if(right<=n && heap[right]>heap[largest])
        largest=right;
    if(largest!=i)
    {
        int temp=heap[i];
        heap[i]=heap[largest];
        heap[largest]=temp;

        heapify(heap,n,largest);
    }
}

int main()
{
    int heap[10]={0,40,90,30,80,70,60};
    int n=6;
    for(int i=n/2;i>=1;i--)
        heapify(heap,n,i);
    heap[1]=heap[n];
    n--;
    heapify(heap,n,1);

    printf("index\n");
    for(int i=1;i<=n;i++)
        printf("%d ",i);
    printf("\ndata\n:");
      for(int i=1;i<=n;i++)
        printf("%d ",heap[i]);
      return 0;
}
