#include<stdio.h> 
#include<stdlib.h> 
struct node { 
   int data; 
   struct node*lchild; 
   struct node*rchild; 
}; 
struct node*root=NULL; 
struct node * getnode(int key){ 
    struct node *newnode=(struct node*)malloc(sizeof(struct node)); 
    newnode->lchild=NULL; 
    newnode->rchild=NULL; 
    newnode->data=key; 
    return newnode;} 
void insert(int key){ 
    struct node *temp=root; 
    struct node *parent=NULL; 
    if(root==NULL){ 
       root=getnode(key); } 
    else{ 
      while(temp!=NULL){ 
      parent=temp; 
      if(temp->data>key){ 
        temp=temp->lchild; } 
      else if(temp->data<key){ 
        temp=temp->rchild; }} 
      if(parent->data>key){ 
        parent->lchild=getnode(key);} 
      else{ 
        parent->rchild=getnode(key); 
      }}} 
void inorder(struct node*root){ 
    if(root!=NULL){ 
      inorder(root->lchild); 
      printf("%d\t",root->data); 
      inorder(root->rchild); 
    }} 
struct node* search(int key){ 
  struct node*temp,*parent; 
  if(root==NULL){ 
    return root; 
  } 

 
  else{ 
    temp=root; 
    parent=NULL; 
  while(temp!=NULL){ 
     if(temp->data==key){ 
      return parent;   } 
    parent=temp; 
    if(temp->data>key){ 
      temp=temp->lchild;  } 
    else{ 
      temp=temp->rchild; } }}} 
void delete(struct node*parent,struct node*p){ 
  struct node*q,*q_old; 
  if(p->lchild!=NULL){ 
      q=p->lchild; 
    if(q->rchild==NULL){ 
      p->data=q->data; 
      p->lchild=q->lchild;  
    } 
    else{ 
      q_old=q; 
      q=q->rchild; 
      while(q->rchild!=NULL){ 
        q_old=q; 
        q=q->rchild;    } 
      p->data=q->data; 
      q_old->rchild=q->lchild;}} 
  else if(p->rchild!=NULL){ 
    q=p->rchild; 
    if(q->lchild==NULL){ 
      p->data=q->data; 
      p->rchild=q->rchild; } 
    else{ 
       q_old=q; 
      q=q->lchild; 
      while(q->lchild!=NULL){ 
        q_old=q; 
        q=q->lchild; 
      } 
      p->data=q->data; 
      q_old->lchild=q->rchild; 
    }} 
    else{ 
      if(parent->lchild==p){ 
        free(parent->lchild); 
      } 

 
      else if (parent->rchild==p){ 
        free(parent->rchild=NULL); 
      } }} 
void main(){ 
    printf("1.insert\n2.display\n3.Search\n4.delete\n"); 
    int n,key; 
    printf("Enter your choice"); 
    scanf("%d",&n); 
    do{ 
    switch(n){ 
    case 1: 
    printf("Enter the data you want to insert"); 
    scanf("%d",&key); 
    insert(key); 
    break; 
    case 2: 
    inorder(root); 
    printf("\n"); 
    break; 
    case 3: 
    printf("Enter the key you want to search:"); 
    scanf("%d",&key); 
     struct node*p=search(key); 
      if (p == NULL && root != NULL && root->data == key) { 
        printf("The key is found at the root: %d\n", root->data);}  
     else if(p==NULL){ 
      printf("The key not found");} 
     else if(p->lchild!=NULL&&p->lchild->data==key){ 
      printf("the key is %d found",p->lchild->data);} 
     else if(p->rchild!=NULL&&p->rchild->data==key){ 
      printf("The key %d is found ",p->lchild->data);} 
    break; 
    case 4: 
    printf("Enter the key you want to delete"); 
    scanf("%d",&key); 
    struct node* parent =search(key); 
    if (parent== NULL && root != NULL && root->data == key) { 
        free(root);}  
    else if(parent->lchild->data==key){ 
      delete(parent,parent->lchild);} 
    else if(parent->rchild->data==key){ 
      delete(parent,parent->rchild);} 
    break; 
    default: 
    printf("invalid choice"); 
    } 
    printf("enter your choice:"); 
    scanf("%d",&n); 
    }while(n!=0);   
} 
