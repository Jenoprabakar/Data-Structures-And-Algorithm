#include<stdio.h> 
#include<stdlib.h> 
int a[89][78]; 
int pnf[100]; 
int pf[100]={999}; 
int visited[100]={0}; 
int min(int n){ 
    int mini=-1; 
    for(int i=1;i<=n;i++){ 
      if(visited[i]==0&&(mini==-1||pnf[i]<pnf[mini])){ 
        mini=i; 
      } 
    } 
    return mini; 
} 
void main(){ 
    int n,src,ver,count; 
    printf("Enter the no of vertices"); 
    scanf("%d",&n); 
     printf("Enter if there is a path exist between(If there is no path exist enter 999)\n"); 
    for(int i=1;i<=n;i++){       
        for(int j=1;j<=n;j++){ 
            printf("(%d,%d):",i,j); 
            scanf("%d",&a[i][j]); 
             } 
              } 
    printf("Enter the source vertex"); 
    scanf("%d",&src); 
    pf[src]=0; 
    visited[src]=1; 
    for(int i=1;i<=n;i++){ 
       pnf[i]=a[src][i]; 
    } 
    do{ 
     count=0; 
    ver=min(n); 
    if (ver==-1){ 
        break;   } 
    visited[ver]=1; 
    pf[ver]=pnf[ver]; 
    for(int i=1;i<=n;i++){ 
        if(visited[i]==0&&(pf[ver]+a[ver][i]<pnf[i])){ 
            pnf[i]=pf[ver]+a[ver][i]; 
        }   } 
    }while(ver!=-1); 
    for(int i=1;i<=n;i++){ 
        if(pf[i]==999){ 
           printf("vetex %d :Path Not found\n",i); 
        } 
        else{ 
        printf("vertex %d: %d\n",i,pf[i]); 
        } 
    } }
