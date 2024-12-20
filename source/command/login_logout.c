#include "login_logout.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createPenggunaSekarang(PenggunaSekarang *PS) {
    PS->isLoggedIn = false;
    PS->currentUserIdx = IdxUndef;
    PS->money = 0;
    PS->name[0] = '\0';
}

void login(ArrayUser *users, PenggunaSekarang *PS) {
    char username[MAX_LEN];
    char password[MAX_LEN];
    boolean valid = false;

    while (!valid) {
        printf("Masukkan username : ");
        STARTSENTENCE("", "");

        int i = 0;
        boolean spasi = false;
        for (i = 0; i < currentWord.Length; i++) {
            username[i] = currentWord.TabWord[i];
            if (username[i] == ' ') {
                spasi = true;
            }
        }
        username[i] = '\0';

        // Check if the user wants to exit
        if (BandingkanChar(username, "exit") == 1) {
            printf("Kembali ke menu utama...\n");
            return;
        }

        if (spasi) {
            printf("Username tidak boleh mengandung spasi!\n");
            continue;
        }
        if (currentWord.Length >= MAX_LEN) {
            printf("Username terlalu panjang!\n");
            continue;
        }

        printf("Masukkan password: ");
        STARTSENTENCE("", "");
        spasi = false;
        for (i = 0; i < currentWord.Length; i++) {
            password[i] = currentWord.TabWord[i];
            if (password[i] == ' ') {
                spasi = true;
            }
        }
        password[i] = '\0';

        if (spasi) {
            printf("Password tidak boleh mengandung spasi!\n");
            continue;
        }
        if (currentWord.Length >= MAX_LEN) {
            printf("Password terlalu panjang!\n");
            continue;
        }

        if (!Apakah_Password_Valid(users, username, password)) {
            printf("Username atau password salah! Kembali ke menu utama.\n");
            return;
        }

        valid = true;

        int userIdx;
        for (i = IdxMin; i <= users->Neff; i++) {
            int j = 0;
            boolean same = true;

            while (users->user[i].name[j] != '\0' && username[j] != '\0') {
                if (users->user[i].name[j] != username[j]) {
                    same = false;
                    break;
                }
                j++;
            }

            if (same && users->user[i].name[j] == '\0' && username[j] == '\0') {
                userIdx = i;
                break;
            }
        }

        PS->isLoggedIn = true;
        PS->currentUserIdx = userIdx;
        PS->money = users->user[userIdx].money;
        int k = 0;
        while (users->user[userIdx].name[k] != '\0') {
            PS->name[k] = users->user[userIdx].name[k];
            k++;
        }
        PS->name[k] = '\0';
        printf("\nLogin berhasil!\n");
        printf("Selamat datang, %s!\n", PS->name);
        printf("Saldo Anda saat ini: %d\n", PS->money);
    }
}

void logout(PenggunaSekarang *PS) {
    if (!PS->isLoggedIn) {
        printf("Anda belum login!\n");
        return;
    }

    PS->isLoggedIn = false;
    PS->currentUserIdx = IdxUndef;
    PS->money = 0;
    PS->name[0] = '\0'; 
    printf("Logout berhasil!\n");
}

boolean isUserLoggedIn(PenggunaSekarang PS) {
    return PS.isLoggedIn;
}

int getCurrentUserIdx(PenggunaSekarang PS) {
    return PS.currentUserIdx;
}

int getCurrentUserMoney(PenggunaSekarang PS) {
    return PS.money;
}
