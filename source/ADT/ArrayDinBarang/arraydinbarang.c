#include"arraydinbarang.h"

ArrayBarang CreateArrayBarang() {
    ArrayBarang array;
    array.data = (Barang *)malloc(InitialSize * sizeof(Barang));
    array.Capacity = InitialSize;
    array.Neff = 0;
    return array;
}

void addBarang(ArrayBarang *array, Barang b) {
    if (array->Neff >= array->Capacity) {
        array->Capacity *= 2;
        Barang *newData = (Barang *)realloc(array->data, array->Capacity * sizeof(Barang));
        if (newData == NULL) {
        printf("Gagal mengalokasikan memori tambahan untuk ArrayBarang.\n");
        return;
        }
        array->data = newData;
    }
    array->data[array->Neff] = b;
    array->Neff++;
}

void hapusBarang(ArrayBarang *array, int index) {
    if (index < 0 || index >= array->Neff) {
        printf("Indeks tidak valid.\n");
        return;
    }

    for (int i = index; i < array->Neff - 1; i++) {
        array->data[i] = array->data[i + 1];
    }

    array->Neff--;
    if (array->Neff > 0 && array->Neff <= array->Capacity / 4) {
        array->Capacity /= 2;
        Barang *newData = (Barang *)realloc(array->data, array->Capacity * sizeof(Barang));
        if (newData == NULL) {
            printf("Gagal memperkecil memori.\n");
        }
    }
}
       

void freeArrayBarang(ArrayBarang *array) {
    free(array->data);
}

boolean BarangDiToko(ArrayBarang *B, char *nama) {
    if (B->Neff == 0) {
        return 0;
    }
    int currentIdx = 0;
    
    for (int i = 0; i < B->Neff; i++) {
        int j = 0;
        boolean same = true;

        while (B->data[currentIdx].nama[j] != '\0' && nama[j] != '\0') {
            if (B->data[currentIdx].nama[j] != nama[j]) {
                same = false;
                break;
            }
            j++;
        }

        if (B->data[currentIdx].nama[j] != nama[j]) {
            same = false;
        }
        
        if (same) {
            return 1;
        }
        
        currentIdx +=1;
    }
    return 0;
}

int IndeksBarangDiToko(ArrayBarang *B, char *nama) {
    for (int i = 0; i < B->Neff; i++) {
        if (BandingkanChar(B->data[i].nama, nama)) {
            return i;
        }
    }
}