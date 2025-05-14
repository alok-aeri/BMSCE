#include <stdio.h>
#include <limits.h>

#define MAX 10
#define INF INT_MAX

void floydWarshall(int graph[MAX][MAX], int V) {
    int dist[MAX][MAX];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = (i == j) ? 0 : (graph[i][j] == -1 ? INF : graph[i][j]);

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    printf("Shortest distance matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V, graph[MAX][MAX];
    printf("Enter the number of vertices (max %d): ", MAX);
    scanf("%d", &V);

    printf("Enter the adjacency matrix (-1 for no edge):\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    floydWarshall(graph, V);
    return 0;
}
