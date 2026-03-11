#include<stdio.h>

int arr[10]={5,10,15,20,25,30,35,40,45,50};
int n=10;
void preorder(int index){
 if(index>=n)
    return;

 printf("%d ", arr[index]);
 preorder(2*index+1);
 preorder(2*index+2);
}
void inorder(int index){
 if(index>=n)
    return;
 preorder(2*index+1);
 printf("%d ", arr[index]);
 preorder(2*index+2);
}
void postorder(int index){
 if(index>=n)
    return;
 preorder(2*index+1);
 preorder(2*index+2);
 printf("%d ", arr[index]);

}

int main()
{
    printf("Preorder Traversal :\n");
    preorder(0);
      printf("\nInorder Traversal :\n");
    inorder(0);
      printf("\nPostorder Traversal :\n");
    postorder(0);
    return 0;
}
