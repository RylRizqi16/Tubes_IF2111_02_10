#include "setmap.h"

void CreateKeranjang(Keranjang *K)
{
    K->Count = 0;
}

boolean IsKeranjangEmpty(Keranjang K)
{
    return K.Count == 0;
}

boolean IsKeranjangFull(Keranjang K)
{
    return K.Count == MaxEl;
}