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
        
        // Bandingkan nama barang
        while (q->data[currentIdx].nama[j] != '\0' && nama[j] != '\0') {
            if (q->data[currentIdx].nama[j] != nama[j]) {
                same = false;
                break;
            }
            j++;
        }
        
        // Pastikan kedua string sudah habis
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
    
    // Baca nama barang menggunakan mesin kata
    STARTWORD();
    
    // Konversi Word ke string
    char namaBarang[MAX_LEN];
    WordToString(CurrentWord, namaBarang);
    
    // Cek apakah barang sudah ada di toko
    if (isBarangAda(store, namaBarang)) {
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
        return;
    }
    
    // Cek apakah barang sudah ada di antrian
    if (isBarangAda(request, namaBarang)) {
        printf("Barang dengan nama yang sama sudah ada di antrian!\n");
        return;
    }
    
    // Jika belum ada, tambahkan ke antrian request
    Barang newBarang = createBarang(namaBarang, 0); // harga 0 karena belum ditentukan
    if (enqueue(request, newBarang)) {
        // Berhasil menambahkan ke antrian
        printf("Barang berhasil ditambahkan!\n");
    } else {
        printf("Antrian request penuh!\n");
    }
}
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
    return 0;
}