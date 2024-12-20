#include<stdio.h> 
#include<stdlib.h> 
struct node{ 
    int data; 
    struct node*lchild; 
    struct node*rchild; 
}; 
struct node*root=NULL; 
struct node*create(){ 
    int x; 
    struct node*newnode=(struct node *)malloc(sizeof(struct node)); 
     printf("Enter data(-1 for no node)"); 
     scanf("%d",&x); 
    if(x==-1) 
    return 0; 
    newnode->data=x; 
    printf("Enter left child of %d\n",x); 
    newnode->lchild=create(); 
    printf("Enter the right child of %d\n",x); 
    newnode->rchild=create(); 
    return newnode;     
} 
void inorder(struct node * temp){ 
    if(temp!=NULL){ 
        inorder(temp->lchild); 
        printf("%d\t",temp->data); 
        inorder(temp->rchild); 
        
 
    } 
    
} 
void preorder(struct node * temp){ 
    if(temp!=NULL){ 
        printf("%d\t",temp->data); 
        preorder(temp->lchild); 
        preorder(temp->rchild); 
    } 
} 
void postorder(struct node * temp){ 
    if(temp!=NULL){ 
        postorder(temp->lchild); 
        postorder(temp->rchild); 
        printf("%d\t",temp->data); 
    } 
} 
int main(){ 
  root=create(); 
  printf("preorder traversal:\t"); 
  preorder(root); 
  printf("\n"); 
  printf("postorder traversal:\t"); 
  postorder(root); 
  printf("\n"); 
  printf("inorder traversal:\t"); 
  inorder(root); 
  printf("\n"); 
}
