#include <stdio.h>
#define INF 9999

void Greedy(int n, int graph[n][n]) {
    int visited[n];
    int totalDistance = 0;
    int currentNode = 0;
    int nextNode;

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    visited[currentNode] = 1;

    printf("A-ha! Rute paling efektif adalah ");
    printf("%d", currentNode);

    for (int i = 1; i < n; i++) {
        int minDistance = INF;

        for (int j = 0; j < n; j++) {
            if (visited[j] == 0 && graph[currentNode][j] < minDistance) {
                minDistance = graph[currentNode][j];
                nextNode = j;
            }
        }

        visited[nextNode] = 1;
        totalDistance += minDistance;
        currentNode = nextNode;

        printf("-%d", currentNode);
    }

    totalDistance += graph[currentNode][0];
    printf("-0.\n");
    printf("Total jarak: %d\n", totalDistance);
}

int optimasi_rute() {
    int n, m;
    
    printf("Masukkan jumlah lokasi pengiriman (node): ");
    scanf("%d", &n);
    printf("Masukkan jumlah rute (edge): ");
    scanf("%d", &m);

    int graph[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INF;
            }
        }
    }

    printf("Masukkan jarak antarlokasi (weight):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    Greedy(n, graph);

    return 0;
}