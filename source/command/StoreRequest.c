#include "store.c"

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