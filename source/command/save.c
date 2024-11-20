// Ini adalah prototipe untuk algoritmanya

#include <stdio.h>
#include <stdlib.h>
#include "save.h"

void save(char *filename, int itemCount, char items[][100], int prices[], int userCount, char users[][100], char passwords[][100], int balances[]) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Gagal menyimpan file.\n");
        return;
    }
    printf("> Menyimpan ke /save/%s\n", filename);
    fprintf(file, "%d\n", itemCount);
    for (int i = 0; i < itemCount; i++) {
        fprintf(file, "%d %s\n", prices[i], items[i]);
    }
    fprintf(file, "%d\n", userCount);
    for (int i = 0; i < userCount; i++) {
        fprintf(file, "%d %s %s\n", balances[i], users[i], passwords[i]);
    }
    fclose(file);
    printf("Save file berhasil disimpan.\n");
}