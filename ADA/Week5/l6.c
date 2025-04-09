#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

typedef struct {
    int adj[MAX_NODES][MAX_NODES];
    int n;
} Graph;

void initGraph(Graph *g, int n) {
    g->n = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void primMST(Graph *g) {
    int parent[MAX_NODES];
    int key[MAX_NODES];
    int visited[MAX_NODES];
    int n = g->n;

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[0] = 0; 
    parent[0] = -1; 

    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (g->adj[u][v] && !visited[v] && g->adj[u][v] < key[v]) {
                key[v] = g->adj[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t%d\n", parent[i], i, g->adj[i][parent[i]]);
    }
}

int main() {
    Graph g;
    initGraph(&g, 5);

    g.adj[0][1] = 2; g.adj[1][0] = 2;
    g.adj[0][3] = 6; g.adj[3][0] = 6;
    g.adj[1][2] = 3; g.adj[2][1] = 3;
    g.adj[1][3] = 8; g.adj[3][1] = 8;
    g.adj[2][3] = 5; g.adj[3][2] = 5;

    primMST(&g);

    return 0;
}
