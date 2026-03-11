#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *link;
};


        int isEmpty(struct node **top){
            if(*top==NULL)
                return 1;
            else
                return 0;
        }
        void push(int data ,struct node **top){
            struct node *newnode=(struct node *)malloc(sizeof(struct node ));
            if(newnode==NULL){

                printf("Stack Underflow.");
                exit(1);
            }
            newnode->data=data;
            newnode->link=NULL;
            newnode->link=*top;
            *top=newnode;


        }

        int pop(struct node **top){
        struct node *temp;
        int val;
        temp=*top;
        if(isEmpty(top)){
              printf("Stack Underflow.");
                exit(1);
        }
        val=temp->data;
        *top=(*top)->link;
        free(temp);
        temp=NULL;
            return val;

        }

        void reverse_stack(struct node **top) {
    struct node *top1 = NULL;
    struct node *top2 = NULL;

    while (*top != NULL) {
        push(pop(top), &top1);
    }
    while (top1 != NULL) {
        push(pop(&top1), &top2); // top1-er address dite hobe
    }
    while (top2 != NULL) {
        push(pop(&top2), top); // top nijei double pointer, tai & lagbe na
    }
}
        void print(struct node **top)
        {
            struct node *temp;
            temp=*top;
              if(isEmpty(top)){
              printf("Stack Underflow.");
                exit(1);
        }
        printf("Stack elements are:");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->link;
        }
        printf("\n");
        }

        int main(){
        int choice;
        int value;
        struct node *top=NULL;
            while(1){
              printf("1.PUSH  2.print  3.Reverse Stack 4.Exit\n");
              printf("Enter your choice:");
              scanf("%d" ,&choice);
              switch(choice){
          case 1:
            printf("Enter the value:");
            scanf("%d" ,&value);
            push(value,&top);
            break;
          case 2:
            print(&top);
            break;
          case 3:
            reverse_stack(&top);
            printf("Reversed Stack is:\n");
            print(&top);
            break;
          case 4:
            exit(1);
          default:
            printf("Wrong Choice.");

              }

            }
        return 0;
        }
