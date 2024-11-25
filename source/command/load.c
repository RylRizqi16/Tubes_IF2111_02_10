#include <stdio.h>
#include "load.h"

void load(char *filename, ArrayBarang *barangToko, ArrayUser *users) {
    STARTWORD(filename, "r");

    if (IsEOP()) {
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
        return;
    }
    printf("> Meload /save/%s\n", filename);

    ADVWORD();
    int itemCount = CharToInt(currentWord.TabWord);

    for (int i = 0; i < itemCount; i++) {
        ADVWORD();
        int harga = CharToInt(currentWord.TabWord);

        ADVWORD();
        Barang barang = createBarang(currentWord.TabWord, harga);
        addBarang(barangToko, barang);
    }

    ADVWORD();
    int userCount = CharToInt(currentWord.TabWord);
    for (int i = 0; i < userCount; i++) {
        ADVWORD();
        int money = CharToInt(currentWord.TabWord);

        ADVWORD();
        char username[MAX_LEN];
        WordToString(currentWord, username);

        ADVWORD();
        char password[MAX_LEN];
        WordToString(currentWord, password);

        User user = createUser(username, password, money);
        users->user[users->Neff] = user;
        users->Neff++;
    }

    printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");
}
