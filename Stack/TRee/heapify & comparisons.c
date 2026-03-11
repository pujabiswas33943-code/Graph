#include<stdio.h>
int cmp=0;
void heapify(int a[],int n,int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n)
     {
        cmp++;
    if(a[l]>a[largest]){
        largest=l;
    }
     }
      if(r<n)
     {
        cmp++;
    if(a[r]>a[largest]){
        largest=r;
    }
     }

     if(largest!=i)
     {
         int temp=a[i];
         a[i]=a[largest];
         a[largest]=temp;
         heapify(a,n,largest);
     }
}

int main()
{
    int a[]={45,12,89,34,78,56,23,90,11};
  int n = sizeof(a) / sizeof(a[0]);
  int i;
    for(i=n/2 - 1;i>=0;i--)
        heapify(a,n,i);

    printf("After heap creation:\n");
    for(i=0;i<n;i++)
        printf("%d ", a[i]);

    for(i=n-1;i>0;i--)
    {

        int temp = a[0];
        a[0] = a[i];
        a[i]  =temp;

        heapify(a,i,0);

    }

    printf("\n\nSorted data:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\nTotal comparisions=%d\n",cmp);
    return 0;
}
