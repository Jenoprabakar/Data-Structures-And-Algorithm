#include<stdio.h>
#include<stdlib.h>
int a[89][78];
int min(int i,int j,int k){
    int l=a[i][k]+a[k][j];
    if(a[i][j]<l){
        return a[i][j];
    }
    else{
        return l;    }
}
void main(){
    int n;
    printf("Enter the no of vertices");
    scanf("%d",&n);
     printf("Enter if there is a path exist between(If there is no path exist enter 999)\n");
    for(int i=1;i<=n;i++){      
        for(int j=1;j<=n;j++){
            printf("(%d,%d)",i,j);
            scanf("%d",&a[i][j]);
             } } 
             for (int k=1;k<=n;k++){
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++){
                     a[i][j]=min(i,j,k);
                    }
                }
             }
             for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    printf("%d\t",a[i][j]);
                }
                printf("\n");
             }
             }