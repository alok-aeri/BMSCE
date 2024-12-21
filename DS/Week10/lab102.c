#include <stdio.h>

#define MAX 10

int a[MAX][MAX], vis[MAX], n;

void dfsConnected(int v) {
    vis[v] = 1;  

    for (int i = 0; i < n; i++) {
        if (a[v][i] == 1 && !vis[i]) {
            dfsConnected(i);  
        }
    }
}

int isConnected() {
    for (int i = 0; i < n; i++) {
        vis[i] = 0;
    }

    dfsConnected(0);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            return 0;  
        }
    }
    return 1;  
}

void dfs(int v) {
    printf("%d ", v + 1);
    vis[v] = 1;

    for (int i = 0; i < n; i++) {
        if (a[v][i] == 1 && vis[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        vis[i] = 0;
    }

    printf("DFS Traversal: ");
    for (i = 0; i < n; i++) {
        if (vis[i] == 0) {
            dfs(i);
        }
    }

    printf("\n");

    if (isConnected()) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}
