#include <stdio.h>
#include <stdlib.h>
#include "../../header/boolean.h"
#include "../Barang/barang.h"
#include "../Mesin_Kata/mesinkata.h"

#ifndef ARRAYDINBARANG_H
#define ARRAYDINBARANG_H
#define InitialSize 10

typedef struct {
    Barang *data;
    int Capacity;
    int Neff;    
} ArrayBarang;

ArrayBarang CreateArrayBarang();

void addBarang(ArrayBarang *arr, Barang b);

void hapusBarang(ArrayBarang *array, int index);

void freeArrayBarang(ArrayBarang *arr);

boolean BarangDiToko(ArrayBarang *B, char *nama);

int IndeksBarangDiToko(ArrayBarang *B, char *nama);
#endif
