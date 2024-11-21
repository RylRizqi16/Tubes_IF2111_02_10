#include "../ADT/ArrayDinBarang/arraydinbarang.h"
#include "../ADT/Mesin_Kata/mesinkata.h"
#include "../ADT/QueueBarang/queue_barang.h"
void QueueList(QueueBarang *q);
void StoreList(ArrayBarang *B);
void StoreRemove (ArrayBarang *store);
void StoreRequest(ArrayBarang *store, QueueBarang *request);
void StoreSupply(ArrayBarang *store, QueueBarang *request);