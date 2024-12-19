#include <stdio.h>
#include <stdlib.h>
#include "store.h"

void StoreList(ArrayBarang *B) {
    if (B->Neff == 0) {
        printf("==============================================\n");
        printf("Tokonya kosong nih, makanya isi dong pak\n");
        return;
    }
    printf("==============================================\n");
    printf("List barang yang ada di toko :\n");

    for (int i = 0; i < B->Neff; i++) {
        printf("%d. %s - Harga: %d\n", i + 1, B->data[i].nama, B->data[i].harga);
    }
}

void StoreRequest(ArrayBarang *store, QueueBarang *request) {
    boolean Valid = false;
    while (!Valid){
        printf("==============================================\n");
        printf("Nama barang yang diminta: ");
        STARTSENTENCE("","");
        char namaBarang[MAX_LEN];
        WordToString(currentWord, namaBarang);
        if (BarangDiToko(store, namaBarang)) {
            printf("Barang dengan nama yang sama sudah ada di toko!\n");
        } else if (BarangDiAntrian(request, namaBarang)) {
            printf("Barang dengan nama yang sama sudah ada di antrian!\n");
        } else {
            Barang newBarang = createBarang(namaBarang, 0); 
        if (enqueue(request, newBarang)) {
            printf("Barang berhasil ditambahkan!\n");
        } else {
            printf("Antrian request penuh!\n");
        }
        Valid = true;
        }
    }
}

void StoreSupply(ArrayBarang *store, QueueBarang *request){
    Barang currentBarang;
    if (!isEmpty(request)) {
        dequeue(request,&currentBarang);
        printf("==============================================\n");
        printf("Apakah kamu ingin menambahkan barang ");
        int j = 0;
        while (currentBarang.nama[j] != '\0') {
            printf("%c", currentBarang.nama[j]);
            j++;
        }
        printf("? \n");
        printf("Ketik: Terima / Tunda / Tolak\n");
        printf("\n>>> ");
        STARTWORD("","");
        printf("\n");
        char perintah[MAX_LEN];
        WordToString(currentWord, perintah);
        boolean Valid = false;
        while (!Valid){
            if (BandingkanChar("Terima",perintah) || BandingkanChar("Tunda",perintah) || BandingkanChar("Tolak",perintah)){
                Valid = true;
            } else {
                printf("Perintah tidak valid. Silakan coba lagi.\n");
                printf("Ketik: Terima / Tunda / Tolak\n");
                printf("\n>>> ");
                STARTWORD("","");
                printf("\n");
                WordToString(currentWord, perintah);
            }
        }
        if (BandingkanChar("Terima",perintah)){
            addBarang(store, currentBarang);
            printf(" berhasil ditambahkan ke toko.\n");
        } else if (BandingkanChar("Tunda",perintah)){
            enqueue (request,currentBarang);
            int j = 0;
            while (currentBarang.nama[j] != '\0') {
                printf("%c", currentBarang.nama[j]);
                j++;
            }
            printf(" dikembalikan ke antrian.\n");
        } else if (BandingkanChar("Tolak",perintah)){
            int j = 0;
            while (currentBarang.nama[j] != '\0') {
                printf("%c", currentBarang.nama[j]);
                j++;
            }
            printf(" dihapus dari antrian.\n");
        }
    } else {
        printf("Antrian request kosong.\n");
    }
}

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




