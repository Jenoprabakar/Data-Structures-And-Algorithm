#include<stdio.h>
#define V 6
#define INF 99999  
int selectMinVertex(int value[], int setMST[])
{
    int minimum = INF;
    int vertex;
    for(int i = 0; i < V; ++i)
    {
        if(setMST[i] == 0 && value[i] < minimum)
        {
            vertex = i;
            minimum = value[i];
        }
    }
    return vertex;
}

void findMST(int graph[V][V])
{
    int parent[V];
    int value[V];
    int setMST[V];
    for(int i = 0; i < V; ++i)
    {
        value[i] = INF;
        setMST[i] = 0;
    }
    parent[0] = -1;
    value[0] = 0;
    for(int i = 0; i < V-1; ++i)
    {
        int U = selectMinVertex(value, setMST);
        setMST[U] = 1;
		for(int j = 0; j < V; ++j)
        {
            if(graph[U][j] != 0 && setMST[j] == 0 && graph[U][j] < value[j])
            {
                value[j] = graph[U][j];
                parent[j] = U;
            }
        }
    }
    for(int i = 1; i < V; ++i)
        printf("U->V: %d->%d  wt = %d\n", parent[i], i, graph[parent[i]][i]);
}
int main()
{
    int graph[V][V] = { {0, 4, 6, 0, 0, 0},
                        {4, 0, 6, 3, 4, 0},
                        {6, 6, 0, 1, 8, 0},
                        {0, 3, 1, 0, 2, 3},
                        {0, 4, 8, 2, 0, 7},
                        {0, 0, 0, 3, 7, 0} };

    findMST(graph);    
    return 0;
}