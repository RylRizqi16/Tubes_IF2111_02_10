#include "queue_barang.h"
#include "barang.h"
#include "mesinkarakter2.h"
#include "mesinkata2.h"
#include <stdio.h>
#include <stdlib.h>


void StoreList(QueueBarang *q) {
    int i;
    int currentIdx;
    
    if (isEmpty(q)) {
        printf("Toko kosong\n");
        return;
    }

    printf("List barang yang ada di toko :\n");
    
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

boolean isBarangAda(QueueBarang *q, char *nama) {
    if (isEmpty(q)) {
        return 0;
    }
    
    int i;
    int currentIdx = q->idxHead;
    
    for (i = 0; i < q->size; i++) {
        int j = 0;
        boolean same = true;

        while (q->data[currentIdx].nama[j] != '\0' && nama[j] != '\0') {
            if (q->data[currentIdx].nama[j] != nama[j]) {
                same = false;
                break;
            }
            j++;
        }

        if (q->data[currentIdx].nama[j] != nama[j]) {
            same = false;
        }
        
        if (same) {
            return 1;
        }
        
        currentIdx = (currentIdx + 1) % CAPACITY;
    }
    return 0;
}

void StoreRequest(QueueBarang *store, QueueBarang *request) {
    printf("Nama barang yang diminta: ");
    
    STARTWORD();

    char namaBarang[MAX_LEN];
    WordToString(CurrentWord, namaBarang);

    if (isBarangAda(store, namaBarang)) {
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
        return;
    }

    if (isBarangAda(request, namaBarang)) {
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
int TerimaTolakTunda(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return 0; 
        }
        str1++;
        str2++;
    }
    return (*str1 == '\0' && *str2 == '\0');
}

void StoreSupply(QueueBarang *request){
    Barang currentBarang;
    dequeue(request,&currentBarang);
    printf("Apakah kamu ingin menambahkan barang ");
    int j = 0;
    while (currentBarang.nama[j] != '\0') {
        printf("%c", currentBarang.nama[j]);
        j++;
    }
    printf("? \n");
    printf("Ketik: Terima / Tunda / Tolak\n");
    printf("\n>>> ");
    STARTWORD();
    printf("\n");
    char perintah[MAX_LEN];
    WordToString(CurrentWord, perintah);
    if (TerimaTolakTunda("Terima",perintah)){
        printf("Masukkan harga barang: ");
        STARTWORD();
        char harga[MAX_LEN];
        WordToString(CurrentWord,harga);
        printf("\n");
        int j = 0;
        while (currentBarang.nama[j] != '\0') {
            printf("%c", currentBarang.nama[j]);
            j++;
        }
        printf(" dengan harga %d berhasil ditambahkan ke toko.\n" , CharToInt(harga));
    } else if (TerimaTolakTunda("Tunda",perintah)){
        enqueue (request,currentBarang);
        int j = 0;
        while (currentBarang.nama[j] != '\0') {
            printf("%c", currentBarang.nama[j]);
            j++;
        }
        printf(" dikembalikan ke antrian.\n");
    } else if (TerimaTolakTunda("Tolak",perintah)){
        int j = 0;
        while (currentBarang.nama[j] != '\0') {
            printf("%c", currentBarang.nama[j]);
            j++;
        }
        printf(" dihapus dari antrian.\n");
    }
}
void StoreRemove(QueueBarang *store, QueueBarang *request);

int main() {
    QueueBarang q;
    // Menampilkan list kosong
    CreateQueueBarang(&q);
    StoreList(&q);
    printf("==================================\n");
    // Menambah beberapa barang
    Barang b1 = createBarang("Platypus Laser", 1000);
    Barang b2 = createBarang("Shrink Ray", 2000);
    enqueue(&q, b1);
    enqueue(&q, b2);
    // Menampilkan list
    StoreList(&q);
    printf("==================================\n");
    
    QueueBarang request;
    CreateQueueBarang(&request);
    
    // Simulasi command STORE REQUEST
    StoreRequest(&q, &request);
    printf("==================================\n");
    StoreList(&request);
    // Simulasi command STORE REQUEST dengan kondisi barang sudah ada di antrian
    CreateQueueBarang(&request);
    Barang b3 = createBarang("Makanan Enak", 500);
    enqueue(&request, b3);
    StoreRequest(&q, &request);
    // Simulasi command STORE SUPPLY
    QueueBarang q;
    CreateQueueBarang(&q);
    Barang b1 = createBarang("Platypus Laser", 1000);
    Barang b2 = createBarang("Shrink Ray", 2000);
    enqueue(&q, b1);
    enqueue(&q, b2);
    StoreSupply(&q);
    StoreList(&q);
    return 0;
}