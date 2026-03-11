#include<stdio.h>
#include<string.h>
#define MAX 100
 char stack[MAX];
 int top=-1;

 void push(char ch){
 if(top==MAX-1){
    printf("Stack Overflow.");
    return ;
 }
 stack[++top]=ch;

 }
 char pop()
 {
     if(top==-1)
     {
         printf("Stack Underflow\n.");
         return;
     }
     return stack[top--];
 }

int main(){
char str[MAX];
int i,len;
fgets(str,MAX,stdin);
str[strcspn(str,"\n")]='\0';

len=strlen(str);
for(i=0;i<len;i++)
{
    push(str[i]);

}
while(top!=-1){

    printf("%c",pop());
}
return 0;
}
