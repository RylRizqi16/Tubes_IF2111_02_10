#include "storerequest.h"

void StoreRequest(ArrayBarang *store, QueueBarang *request) {
    printf("==============================================\n");
    printf("Nama barang yang diminta: ");
    STARTSENTENCE("","");
    char namaBarang[MAX_LEN];
    WordToString(currentWord, namaBarang);

    if (BarangDiToko(store, namaBarang)) {
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
        return;
    }

    if (BarangDiAntrian(request, namaBarang)) {
        printf("Barang dengan nama yang sama sudah ada di antrian!\n");
        return;
    }

    Barang newBarang = createBarang(namaBarang, 0); 
    if (enqueue(request, newBarang)) {
        printf("Barang berhasil ditambahkan!\n");
    } else {
        printf("Antrian request penuh!\n");
    }
}