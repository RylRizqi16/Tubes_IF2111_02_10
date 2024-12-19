#ifndef setmap_H
#define setmap_H
#include <stdio.h>
#include "boolean.h"
#include "barang.h"

#define Nil 0
#define MaxEl 205
#define Undefined 0

typedef int JumlahBarang;

typedef struct
{
    Barang Elements[MaxEl];
    JumlahBarang JumlahElement[MaxEl];
    int Count;
} Keranjang;

void CreateBarang(Keranjang *K);

boolean IsKeranjangEmpty(Keranjang K);

boolean IsKeranjangFull(Keranjang K);

#endif