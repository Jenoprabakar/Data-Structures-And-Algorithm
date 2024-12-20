#include<stdio.h> 
#include<stdlib.h> 
int a[89][78]; 
int visited[100]={0}; 
int q[100]; 
int front=-1,rear=-1; 
void add(int i){ 
     if(front==-1 && rear==-1){ 
      front+=1,rear+=1; 
      q[front]=i;} 
      else{ 
        rear=rear+1; 
        q[rear]=i;     
   }    
} 
int isempty() { 
    return front == -1 || front > rear; 
} 
int dequeue(){ 
  if(isempty()){ 
    return -1; 
  } 
  int c=q[front]; 
  front=front+1; 
  return c; 
} 
void dfs(int vertex,int n){ 
    if(visited[vertex]==0){ 
      printf("%d\t",vertex); 
      visited[vertex]=1; 
    }   
   for(int i=1;i<=n;i++){ 
       if(a[vertex][i]!=0 &&visited[i]==0){ 
           dfs(i,n); 
         } 
}} 
void bfs(int vertex,int n){ 
  int v; 
  if(visited[vertex]==0){ 
    printf("%d\t",vertex); 
    visited[vertex]=1; 
    add(vertex); 
  } 
  while(!isempty()){ 
    v=dequeue(); 
    if(v==-1){ 
     return; 
    } 
  for(int i=1;i<=n;i++){ 
    if(a[v][i]!=0&&visited[i]==0){ 
      printf("%d\t",i); 
   visited[i]=1; 
   add(i); 
    } 
  } 
} 
} 
void main(){ 
    int n; 
    printf("Enter the no of vertices"); 
    scanf("%d",&n); 
     printf("Enter if there is a path exist between(If there is no path exist enter 0)\n"); 
    for(int i=1;i<=n;i++){ 
        for(int j=1;j<=n;j++){ 
            printf("(%d,%d)",i,j); 
            scanf("%d",&a[i][j]); 
             } }  
             printf("DFS traversal:"); 
             dfs(1,n); 
             printf("\n"); 
             
            for(int i=1;i<=n;i++){ 
              visited[i]=0; 
            } 
             printf("BFS traversal:"); 
             bfs(1,n); 
             }
