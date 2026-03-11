#include<stdio.h>
#define MAX 5
 int stack[MAX];
 int top=-1;

 void push(int value){
 if(top==MAX-1){
    printf("Stack Overflow.");
    return ;
 }
 stack[++top]=value;

 }
 int pop()
 {
     if(top==-1)
     {
         printf("Stack Underflow\n.");
         return;
     }
     return stack[top--];
 }
int main(){
int n,i,value;
printf("Enter number of value:");
scanf("%d", &n);

printf("Enter elements in ascending order:");
for(i=0;i<n;i++){

    scanf("%d", &value);
    push(value);
}
printf("Descending order:");
for(i=0;i<n;i++){

    printf("%d ",pop());
}
return 0;
}
