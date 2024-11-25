#include <stdio.h>
#include <stdlib.h>
#include "quit.h"

void quit(char *filename, ArrayBarang *barangToko, ArrayUser *users){
    printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");
    START(NULL, "");
    ADV();
    char response = GetCC();
        if (response == 'Y' || response == 'y') {
            save(filename, barangToko, users); // Simpan data
            printf("Data berhasil disimpan. Kamu keluar dari PURRMART. Dadah ^_^/\n");
            exit(0);
        } else /*if (response == 'N' || response == 'n')*/ {
            printf("Kamu keluar dari PURRMART tanpa menyimpan. Dadah ^_^/\n");
            exit(0);
    }