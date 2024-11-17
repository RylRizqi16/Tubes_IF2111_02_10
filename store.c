#include "queue_barang.h"
#include "barang.h"
#include <stdio.h>
#include <stdlib.h>


void StoreList(QueueBarang *q) {
    int i;
    int currentIdx;
    
    if (isEmpty(q)) {
        printf("Toko kosong\n");
        return;
    }

    printf("List barang yang ada di toko :\n");
    
    currentIdx = q->idxHead;
    for (i = 0; i < q->size; i++) {
        printf("- ");
        int j = 0;
        while (q->data[currentIdx].nama[j] != '\0') {
            printf("%c", q->data[currentIdx].nama[j]);
            j++;
        }
        printf("\n");
        
        currentIdx = (currentIdx + 1) % CAPACITY;
    }
}

int main() {
    QueueBarang q;
    CreateQueueBarang(&q);
    // Menambah beberapa barang
    Barang b1 = createBarang("Platypus Laser", 1000);
    Barang b2 = createBarang("Shrink Ray", 2000);
    enqueue(&q, b1);
    enqueue(&q, b2);
    // Menampilkan list
    StoreList(&q);
    printf("==================================\n");
    // Menampilkan list kosong
    CreateQueueBarang(&q);
    StoreList(&q);
    return 0;
}