#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100
#define INF 999999

void primsAlgorithm(int graph[MAX][MAX], int n) {
int parent[MAX];
int key[MAX];
bool inMST[MAX];

for (int i = 0; i < n; i++) {
key[i] = INF;
inMST[i] = false;
parent[i] = -1;
}

key[0] = 0;

for (int count = 0; count < n - 1; count++) {
int min = INF, u = -1;
for (int v = 0; v < n; v++) {
if (!inMST[v] && key[v] < min) {
min = key[v];
u = v;
}
}

inMST[u] = true;

for (int v = 0; v < n; v++) {
if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
key[v] = graph[u][v];
parent[v] = u;
}
}
}

int totalCost = 0;
printf("\nMinimum Spanning Tree (using Prim's Algorithm):\n");
printf("Edge\tWeight\n");
for (int i = 1; i < n; i++) {
printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
totalCost += graph[i][parent[i]];
}
printf("Total weight of MST: %d\n", totalCost);
}

int main() {
int n;
int graph[MAX][MAX];

printf("Enter the number of vertices: ");
scanf("%d", &n);

printf("Enter the adjacency matrix (0 if no edge):\n");
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
scanf("%d", &graph[i][j]);
}
}

primsAlgorithm(graph, n);

return 0;
}
