#ifndef BARANG_H
#define BARANG_H

#define MAX_LEN 100

typedef struct {
    char nama[MAX_LEN];
    int harga;
} Barang;

Barang createBarang(char *nama, int harga);

#endif
