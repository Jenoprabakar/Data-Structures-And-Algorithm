#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    int i;
    int j;
    struct node *next;
};
struct node *root = NULL;
struct node* getnode(int data, int i, int j) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->i = i;
    newnode->j = j;
    newnode->next = NULL;
    return newnode;
}
void insert(int data, int i, int j) {
    struct node *newnode = getnode(data, i, j);
    if (root == NULL || root->data >= data) {
        newnode->next = root;
        root = newnode;
        return;
    }
    struct node *temp = root;
    while (temp->next != NULL && temp->next->data < data) {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
int find(int parent[], int i) {
    if (parent[i] == i) return i;
    return find(parent, parent[i]);
}
void union_sets(int parent[], int rank[], int u, int v) {
    int root_u = find(parent, u);
    int root_v = find(parent, v);
    if (rank[root_u] < rank[root_v]) {
        parent[root_u] = root_v;
    } else if (rank[root_u] > rank[root_v]) {
        parent[root_v] = root_u;
    } else {
        parent[root_v] = root_u;
        rank[root_u]++;
    }
}
void kruskal(int n) {
    int parent[n + 1];
    int rank[n + 1];

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    struct node *temp = root;
    int mst_weight = 0;
    printf("Edges in the Minimum Spanning Tree:\n");
    while (temp != NULL) {
        int u = temp->i;
        int v = temp->j;
        int weight = temp->data;
        if (find(parent, u) != find(parent, v)) {
            printf("Edge (%d, %d) with weight %d\n", u, v, weight);
            mst_weight += weight;
            union_sets(parent, rank, u, v);
        }
        temp = temp->next;
    }
    printf("Total weight of MST: %d\n", mst_weight);
}
int a[50][50];
int main() {
    int n = 4;
    int matrix[4][4] = {
        {0, 10, 6, 5},
        {10, 0, 0, 15},
        {6, 0, 0, 4},
        {5, 15, 4, 0}
    };
for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = matrix[i - 1][j - 1];
            if (a[i][j] != 0 && i < j) {
                insert(a[i][j], i, j);
            }
        }
    }
kruskal(n);
    return 0;
}