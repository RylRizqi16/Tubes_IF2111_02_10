#ifndef setmap_H
#define setmap_H
#include <stdio.h>
#include "../../header/boolean.h"
#include "../Barang/barang.h"

#define MaxEl 100

typedef int JumlahBarang;

typedef struct
{
    Barang Elements;
    JumlahBarang JumlahElement;
} Barang_Jumlah;

typedef struct
{
    Barang_Jumlah Item[MaxEl];
    int Count;
} Keranjang;

void CreateKeranjang(Keranjang *K);

boolean IsKeranjangEmpty(Keranjang K);

boolean IsKeranjangFull(Keranjang K);

#endif