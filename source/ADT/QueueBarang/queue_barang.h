#ifndef QUEUEBARANG_H
#define QUEUEBARANG_H

#include "../Barang/barang.h"
#include "../../header/boolean.h"

#define IDX_UNDEF -1
#define CAPACITY 100

typedef struct {
    Barang data[CAPACITY]; 
    int idxHead;
    int idxTail;
    int size;
} QueueBarang;

#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define HEAD(q) (q).data[(q).idxHead] 
#define TAIL(q) (q).data[(q).idxTail] 

void CreateQueueBarang(QueueBarang *q);
boolean isEmpty(QueueBarang *q);
boolean isFull(QueueBarang *q);
int enqueue(QueueBarang *q, Barang barang);
int dequeue(QueueBarang *q, Barang *barang);
boolean BarangDiAntrian(QueueBarang *q, char *nama);

#endif