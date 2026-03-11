#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;

};

struct Node* createnode(int value){
   struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
   newnode->data=value;
   newnode->left=NULL;
   newnode->right=NULL;
   return newnode;

}

struct Node* insertBst(struct Node* root,int value){
 if(root==NULL)
    return createnode(value);
 if(value<root->data)
    root->left=insertBst(root->left,value);

 else
    root->right=insertBst(root->right,value);
  return root;
}

void inorder(struct Node* root)
{
    if(root!=NULL){

        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
struct Node* findmin(struct Node* root){
while(root->left != NULL)
    root=root->left;
return root;

}
struct Node* deleteNode(struct Node* root,int key){
 if(root==NULL)
    return root;
 if(key<root->data)
    root->left=deleteNode(root->left,key);
     else if(key>root->data)
    root->right=deleteNode(root->right,key);
 else{
    if(root->left != NULL && root->right != NULL)
    {
        struct Node* temp=findmin(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    else{
        struct Node* temp=root;
        if(root->left!=NULL)
            root=root->left;
        else
            root=root->right;
        free(temp);
    }
 }
 return root;
}
int main()
{

    struct Node* root=NULL;
    int values[10]={50,30,40,20,60,70,80,90,10,5};
    for(int i=0;i<10;i++){
        root=insertBst(root,values[i]);

        root=insertBst(root,55);
         root=insertBst(root,65);
         root=deleteNode(root,50);


    printf("Inorder Traversal:");
    inorder(root);
return 0;
}
;
