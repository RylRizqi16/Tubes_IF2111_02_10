#include <stdio.h>
#include <stdlib.h>
#include "store.h"

void QueueList(QueueBarang *q) {
    int i;
    int currentIdx;
    
    if (isEmpty(q)) {
        printf("Antrian kosong\n");
        return;
    }

    printf("List barang yang ada di antrian :\n");
    
    currentIdx = q->idxHead;
    for (i = 0; i < q->size; i++) {
        printf("%d. ", i+1);
        int j = 0;
        while (q->data[currentIdx].nama[j] != '\0') {
            printf("%c", q->data[currentIdx].nama[j]);
            j++;
        }
        printf("\n");
        
        currentIdx = (currentIdx + 1) % CAPACITY;
    }
}


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
        if (BandingkanChar("Terima",perintah)){
            printf("Masukkan harga barang: ");
            STARTWORD("","");
            char harga[MAX_LEN];
            WordToString(currentWord,harga);
            printf("\n");
            int j = 0;
            while (currentBarang.nama[j] != '\0') {
                printf("%c", currentBarang.nama[j]);
                j++;
            }
            addBarang(store, currentBarang);
            printf(" dengan harga %d berhasil ditambahkan ke toko.\n" , CharToInt(harga));
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

