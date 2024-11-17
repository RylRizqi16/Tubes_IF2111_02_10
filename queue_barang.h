#ifndef QUEUE_H
#define QUEUE_H

#include "barang.h"
#include "boolean.h"

#define IDX_UNDEF -1
#define CAPACITY 100

typedef int ElType;
typedef struct {
	Barang data[CAPACITY]; 
	int idxHead;
	int idxTail;
	int size;
} QueueBarang;

#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead]
#define     TAIL(q) (q).buffer[(q).idxTail]

void CreateQueueBarang(QueueBarang *q);
boolean isEmpty(QueueBarang *q);
boolean isFull(QueueBarang *q);
int enqueue(QueueBarang *q, Barang barang);
int dequeue(QueueBarang *q, Barang *barang);
#endif
