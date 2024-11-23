#include <stdio.h>
#include "load.h"

void load(char *filename, int *itemCount, char items[][100], int prices[], int *userCount, char users[][100], char passwords[][100], int balances[]) {
    STARTWORD(filename, "r"); // Membuka file untuk dibaca
    if (IsEOP()) {
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
        return;
    }
    printf("> Meload /save/%s\n", filename);
    ADVWORD();
    *itemCount = CharToInt(currentWord.TabWord);
    for (int i = 0; i < *itemCount; i++) {
        ADVWORD();
        prices[i] = CharToInt(currentWord.TabWord);
        ADVWORD();
        WordToString(currentWord, items[i]);
    }
    ADVWORD();
    *userCount = CharToInt(currentWord.TabWord);
    for (int i = 0; i < *userCount; i++) {
        ADVWORD();
        balances[i] = CharToInt(currentWord.TabWord);
        ADVWORD();
        WordToString(currentWord, users[i]);
        ADVWORD();
        WordToString(currentWord, passwords[i]);
    }
    printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");
}