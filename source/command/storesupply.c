#include "storesupply.h"

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