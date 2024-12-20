#include "queue_barang.h"
#include <stdio.h>

void CreateQueueBarang(QueueBarang *q) {
    IDX_HEAD(*q) = IDX_UNDEF;  
    IDX_TAIL(*q) = IDX_UNDEF;
    q->size = 0;
}

boolean isEmpty(QueueBarang *q) {
    return q->size == 0;  
}

boolean isFull(QueueBarang *q) {
    return q->size == CAPACITY;  
}

int enqueue(QueueBarang *q, Barang barang) {
    if (isFull(q)) {
        return 0;
    }
    
    if (isEmpty(q)) {
        IDX_HEAD(*q) = 0;  
        IDX_TAIL(*q) = 0;
    } else {
        q->idxTail = (q->idxTail + 1) % CAPACITY;
    }
    
    q->data[q->idxTail] = barang;
    q->size++;
    return 1;
}

int dequeue(QueueBarang *q, Barang *barang) {
    if (isEmpty(q)) {
        return 0;
    }
    
    *barang = q->data[q->idxHead];
    
    if (q->size == 1) {
        IDX_HEAD(*q) = IDX_UNDEF; 
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        q->idxHead = (q->idxHead + 1) % CAPACITY;
    }
    
    q->size--;
    return 1;
}

boolean BarangDiAntrian(QueueBarang *q, char *nama) {
    if (isEmpty(q)) {
        return 0;
    }
    
    int i;
    int currentIdx = q->idxHead;
    
    for (i = 0; i < q->size; i++) {
        int j = 0;
        boolean same = true;

        while (q->data[currentIdx].nama[j] != '\0' && nama[j] != '\0') {
            if (q->data[currentIdx].nama[j] != nama[j]) {
                same = false;
                break;
            }
            j++;
        }

        if (q->data[currentIdx].nama[j] != nama[j]) {
            same = false;
        }
        
        if (same) {
            return 1;
        }
        
        currentIdx = (currentIdx + 1) % CAPACITY;
    }
    return 0;
}