#include "login_logout.h"
#include <stdio.h>
#include <stdlib.h>

void createPenggunaSekarang(PenggunaSekarang *PS) {
    PS->isLoggedIn = false;
    PS->currentUserIdx = -IdxUndef;
    PS->money = 0;
}

void login(ArrayUser *users, PenggunaSekarang *PS) {
    char username[MAX_LEN];
    char password[MAX_LEN];
    boolean valid = false;
    boolean spasi = false;
    int i = 0;

    while (!valid) {
        printf("Masukkan username: ");
        STARTSENTENCE("", "");
        for (i = 0; i < currentWord.Length; i++) {
            username[i] = currentWord.TabWord[i];
            if (username[i] == ' ') {
                spasi = true;
            }
        }
        username[i] = '\0';

        if (!spasi) {
            if (currentWord.Length >= MAX_LEN) {
                printf("Username terlalu panjang!\n");
            }
        }

        printf("Masukkan password: ");
        STARTSENTENCE("", "");
        for (i = 0; i < currentWord.Length; i++) {
            password[i] = currentWord.TabWord[i];
            if (password[i] == ' ') {
                spasi = true;
            }
        }
        password[i] = '\0';

        if (!spasi) {
            if (currentWord.Length >= MAX_LEN) {
                printf("Password terlalu panjang!\n");
            }
        }

        if (!Apakah_Password_Valid(users, username, password)) {
            printf("Username atau password salah!\n");
        } else {
            valid = true;
        }
    }

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
    printf("Login berhasil!\n");
    printf("Selamat datang, %s!\n", username);
    printf("Saldo Anda saat ini: %d\n", PS->money);
}

void logout(PenggunaSekarang *PS) {
    if (!PS->isLoggedIn) {
        printf("Anda belum login!\n");
        return;
    }

    PS->isLoggedIn = false;
    PS->currentUserIdx = IdxUndef;
    PS->money = 0;
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
