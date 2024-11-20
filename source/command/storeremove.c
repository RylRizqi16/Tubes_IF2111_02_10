#include "storeremove.h"

void StoreRemove (ArrayBarang *store){
printf("==============================================\n");
    printf("Nama barang yang akan dihapus: ");
    STARTSENTENCE("","");
    char namaBarang[MAX_LEN];
    WordToString(currentWord, namaBarang);
    if (BarangDiToko(store, namaBarang)) {
        hapusBarang(store, IndeksBarangDiToko(store, namaBarang));
        printf("%s", namaBarang);
        printf(" telah berhasil dihapus\n");
    } else{
        printf("Barang tidak ditemukan di toko.\n");
    }
}