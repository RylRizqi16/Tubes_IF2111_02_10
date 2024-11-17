#include "barang.h"
#include <stdlib.h>

Barang createBarang(char *nama, int harga) {
    Barang b;
    int i;

    for (i = 0; i < MAX_LEN && nama[i] != '\0'; i++) {
        b.nama[i] = nama[i];
    }
    b.nama[i] = '\0';
    b.harga = harga;
    return b;
}
