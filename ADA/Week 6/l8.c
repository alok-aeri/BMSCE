#include <stdio.h>
#define INF 9999

void dijkstra(int cost[][10], int n, int source) {
    int dist[10], visited[10], i, j, min, u;
    
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    
    dist[source] = 0;

    for (i = 0; i < n - 1; i++) {
        min = INF;
        u = -1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }
        
        visited[u] = 1; 
        
        for (j = 0; j < n; j++) {
            if (!visited[j] && cost[u][j] != INF && dist[u] + cost[u][j] < dist[j]) {
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        printf("Distance from %d to %d is %d\n", source, i, dist[i]);
    }
}

int main() {
    int n, i, j, source;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    int cost[10][10];
    
    printf("Enter the adjacency matrix (use %d for no path between vertices):\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    
    dijkstra(cost, n, source);
    
    return 0;
}
