#include <stdio.h>
#define INF 9999  // Anggap sebagai nilai tak terjangkau

// Fungsi untuk menemukan rute terdekat menggunakan algoritma greedy
void TSPGreedy(int n, int graph[n][n]) {
    int visited[n];  // Menandai lokasi yang sudah dikunjungi
    int totalDistance = 0;
    int currentNode = 0;  // Mulai dari node 0
    int nextNode;

    // Inisialisasi
    for (int i = 0; i < n; i++) {
        visited[i] = 0;  // Belum ada lokasi yang dikunjungi
    }
    visited[currentNode] = 1;  // Lokasi awal sudah dikunjungi

    printf("A-ha! Rute paling efektif adalah ");
    printf("%d", currentNode);  // Print lokasi awal

    // Cari rute terdekat untuk setiap lokasi
    for (int i = 1; i < n; i++) {
        int minDistance = INF;

        // Cari node terdekat yang belum dikunjungi
        for (int j = 0; j < n; j++) {
            if (visited[j] == 0 && graph[currentNode][j] < minDistance) {
                minDistance = graph[currentNode][j];
                nextNode = j;
            }
        }

        // Tandai node yang sudah dikunjungi dan perbarui total jarak
        visited[nextNode] = 1;
        totalDistance += minDistance;
        currentNode = nextNode;

        // Tampilkan node yang dikunjungi
        printf("-%d", currentNode);
    }

    // Kembali ke node awal
    totalDistance += graph[currentNode][0];
    printf("-0.\n");
    printf("Total jarak: %d\n", totalDistance);
}

int main() {
    int n, m;
    
    // Input jumlah lokasi dan rute
    printf("Masukkan jumlah lokasi pengiriman (node): ");
    scanf("%d", &n);
    printf("Masukkan jumlah rute (edge): ");
    scanf("%d", &m);

    // Matriks ketetanggaan untuk graf
    int graph[n][n];

    // Inisialisasi jarak antar lokasi (0 untuk lokasi yang sama, INF untuk tak terjangkau)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INF;
            }
        }
    }

    // Input jarak antar lokasi
    printf("Masukkan jarak antarlokasi (weight):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;  // Graf tak terarah
    }

    // Panggil fungsi TSPGreedy untuk mencari rute terbaik
    TSPGreedy(n, graph);

    return 0;
}
