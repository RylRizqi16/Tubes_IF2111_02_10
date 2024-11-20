#include "storelist.h"

void StoreList(ArrayBarang *B) {
    if (B->Neff == 0) {
        printf("==============================================\n");
        printf("Tokonya kosong nih, makanya isi dong pak\n");
        return;
    }
    printf("==============================================\n");
    printf("List barang yang ada di toko :\n");

    for (int i = 0; i < B->Neff; i++) {
        printf("%d. %s\n", i + 1, B->data[i].nama);
    }
}