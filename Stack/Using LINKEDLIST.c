#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;

};
  struct node *top=NULL;
      void push(int data)
      {
            struct node *newnode=(  struct node *)malloc(sizeof(  struct node));
            newnode->data=data;
            newnode->link=NULL;
                if(newnode==NULL)
                {
                    printf("Stack Overflow.\n");
                    exit(1);
                }
                newnode->link=top;
                top=newnode;
      }

      int pop()
      {
           struct node *temp=top;
          int val;
          val=temp->data;
          top=top->link;
          free(temp);
          return val;
      }

      void print(){
       struct node *temp=top;
        if(temp==NULL)
                {
                    printf("Stack Underflow.\n");
                    exit(1);
                }
      printf("The stack elements are:");
      while(temp!=NULL)
      {
          printf("%d ",temp->data);
          temp=temp->link;
      }
      printf("\n");

      }
      int main()
      {
           int value;
           int data;
          int choice;
          while(1){
          printf("1.push   2.pop  3.print  4.exit\n");
          scanf("%d",&choice);

          switch(choice){
      case 1:

        printf("enter the value:");
        scanf("%d",&value);
        push(value);
        break;
      case 2:

        data=pop();
        printf("Deleted element:%d",data);
        break;
      case 3:
        print();
        break;
      case 4:
        exit(1);
      default:
        printf("Wrong Choice.\n");
          }

}          return 0;
      }
