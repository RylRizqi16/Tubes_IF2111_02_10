#include "store.c"

StoreList(QueueBarang *q) {
    int i;
    int currentIdx;
    
    if (isEmpty(q)) {
        printf("Toko kosong\n");
        return;
    }

    printf("List barang yang ada di toko :\n");
    
    currentIdx = q->idxHead;
    for (i = 0; i < q->size; i++) {
        printf("%d. ", i+1);
        int j = 0;
        while (q->data[currentIdx].nama[j] != '\0') {
            printf("%c", q->data[currentIdx].nama[j]);
            j++;
        }
        printf("\n");
        
        currentIdx = (currentIdx + 1) % CAPACITY;
    }
}