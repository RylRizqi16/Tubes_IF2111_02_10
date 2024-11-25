#include "register.h"
#include <stdio.h>

void register_user(ArrayUser *users) {
    if ((*users).Neff >= IdxMax) {
        printf("Sistem tidak dapat menampung user baru.\n");
        return;
    }

    char username[MAX_LEN];
    char password[MAX_LEN];
    boolean valid;
    boolean spasi;
    int i=0;
    while (!valid){
        valid = false;
        spasi = false;
        printf("Masukkan username: ");
        STARTSENTENCE("","");
        for (i = 0; i < currentWord.Length; i++) {
            username[i] = currentWord.TabWord[i];
            if (username[i] == ' ') {
                printf("Username HANYA bisa satu kata!\n");
                spasi = true;
            }
        }
        username[i] = '\0';
        if (!spasi){
            if (currentWord.Length >= MAX_LEN) {
                printf("Username terlalu panjang!\n");
            } else if (Apakah_Username_Ada(*users, username)) {
                printf("Username sudah digunakan!\n");
            } else {
                valid = true;
            }
        }
    }
    valid = false;
    while (!valid){
        spasi = false;
        printf("Masukkan password: ");
        STARTSENTENCE("","");
        for (i = 0; i < currentWord.Length; i++) {
            password[i] = currentWord.TabWord[i];
            if (password[i] == ' ') {
                printf("Password HANYA bisa satu kata!\n");
                spasi = true;
            }
        }
        password[i] = '\0';
        if (!spasi){
            if (currentWord.Length >= MAX_LEN) {
                printf("Password terlalu panjang!\n");
            } else {
                valid = true;
            }
        }
    }
    (*users).Neff++;
    User newUser = createUser(username,password, 0);
    (*users).user[(*users).Neff] = newUser;
    printf("Registrasi berhasil!\n");
}