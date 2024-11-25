#include <stdio.h>
#include "save.h"

void save(char *filename, ArrayBarang *barangToko, ArrayUser *users) {
    FILE *file = fopen(filename, "w");

    if (!file) {
        printf("Gagal menyimpan file.\n");
        return;
    }
    printf("> Menyimpan ke /save/%s\n", filename);

    fprintf(file, "%d\n", barangToko->Neff);

    for (int i = 0; i < barangToko->Neff; i++) {
        fprintf(file, "%d %s\n", barangToko->data[i].harga, barangToko->data[i].nama);
    }

    fprintf(file, "%d\n", users->Neff);

    for (int i = 0; i < users->Neff; i++) {
        fprintf(file, "%d %s %s\n", users->user[i].money, users->user[i].name, users->user[i].password);
    }

    fclose(file);
    printf("Save file berhasil disimpan.\n");
}