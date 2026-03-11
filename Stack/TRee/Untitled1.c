
#include<stdio.h>
int main()
{

    int arr[10]={5,10,15,20,25,30,35,40,45,50};
    int n=10;
    int i;

    printf("Array element:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    printf("\n\n");
    i=4;
    printf("Data at index %d: %d\n",i,arr[i]);
    if(2*i+1<n)
        printf("Left Child: %d",arr[2*i+1]);
    else
        printf("Left child: not exist\n");
         printf("\n");
        if(2*i+2<n)
        printf("Right Child: %d\n",arr[2*i+2]);
    else
        printf("Right child: not exist\n");
        printf("\n");
        if(i!=0)
            printf("Parent of index %d: %d\n",i,arr[(i-1)/2]);
        else
            printf("Root node has no parent\n");
        return 0;

}
