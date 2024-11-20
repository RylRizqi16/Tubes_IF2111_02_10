// Ini adalah prototipe untuk algoritmanya

#include <stdio.h>
#include <stdlib.h>
#include "load.h"
// Temporary
#include <string.h>

void load(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
        return;
    }
    printf("> Meload /save/%s\n", filename);
    // Membaca jumlah barang
    int itemCount;
    fscanf(file, "%d", &itemCount);
    for (int i = 0; i < itemCount; i++) {
        int price;
        char name[100];
        fscanf(file, "%d %[^\n]", &price, name);
        printf("Barang: %s, Harga: %d\n", name, price);
    }
    // Membaca jumlah pengguna
    int userCount;
    fscanf(file, "%d", &userCount);
    for (int i = 0; i < userCount; i++) {
        int money;
        char username[100], password[100];
        fscanf(file, "%d %s %s", &money, username, password);
        printf("User: %s, Saldo: %d\n", username, money);
    }
    fclose(file);
    printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");
}