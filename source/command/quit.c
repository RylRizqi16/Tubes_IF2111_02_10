#include <stdio.h>
#include <stdlib.h>
#include "quit.h"

void quit(char *filename, ArrayBarang *barangToko, ArrayUser *users){
    char response;

    do {
        printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");
        START(NULL, "");
        ADV();
        response = GetCC();

        if (response == 'Y' || response == 'y') {
            save(filename, barangToko, users); // Simpan data
            printf("Data berhasil disimpan. Kamu keluar dari PURRMART. Dadah ^_^/\n");
            exit(0);
        } else if (response == 'N' || response == 'n') {
            printf("Kamu keluar dari PURRMART tanpa menyimpan. Dadah ^_^/\n");
            exit(0);
        } else {
            printf("Input tidak valid. Silakan masukkan Y atau N\n");
        }
    } while (response != 'Y' && response != 'y' && response != 'N' && response != 'n');
}