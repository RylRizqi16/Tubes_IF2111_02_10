#include <stdio.h>
#include <string.h>
#include "load.h"
#include "../ADT/ArrayDinBarang/arraydinbarang.h"
#include "../ADT/ArrayStatikuser/arrayuser.h"
#include "../ADT/Mesin_Kata/mesinkata.h"

void load(char *filename, ArrayBarang *barangToko, User users[], int *userCount) {
    STARTWORD(filename, "r"); // Start reading the file
    if (IsEOP()) {
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
        return;
    }

    printf("> Meload /save/%s\n", filename);

    // Load items
    ADVWORD();
    int itemCount = CharToInt(currentWord.TabWord);
    for (int i = 0; i < itemCount; i++) {
        ADVWORD();
        int price = CharToInt(currentWord.TabWord);
        ADVWORD();
        char itemName[100];
        WordToString(currentWord, itemName);

        // Create and add item to barangToko
        Barang newBarang;
        strcpy(newBarang.nama, itemName);
        newBarang.harga = price;
        addBarang(barangToko, newBarang);
    }

    // Load users
    ADVWORD();
    *userCount = CharToInt(currentWord.TabWord);
    for (int i = 0; i < *userCount; i++) {
        ADVWORD();
        int balance = CharToInt(currentWord.TabWord);
        ADVWORD();
        char username[100], password[100];
        WordToString(currentWord, username);
        ADVWORD();
        WordToString(currentWord, password);

        // Populate the user array
        strcpy(users[i].name, username);
        strcpy(users[i].password, password);
        users[i].money = balance;
    }

    printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");
}
