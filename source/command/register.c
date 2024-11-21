#include "register.h"

// Membandingkan dua string karakter demi karakter.
int custom_strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
    // Mengembalikan selisih nilai ASCII dari karakter pertama yang berbeda.
}

// Menyalin string dari src (sumber) ke dest (tujuan).
void custom_strcpy(char *dest, const char *src) {
    while ((*dest++ = *src++));
    // Salin setiap karakter (termasuk karakter null '\0') dari src ke dest.
}

// Membuat akun baru
void registerUser(char username[MAX_LEN], char password[MAX_LEN]) {
    if (userList.count >= MAX_USERS) {
        printf("User list is full, cannot register more users.\n");
        return;
    }
    
    printf("Username: ");
    scanf("%s", username);

    // Validasi untuk memastikan username hanya terdiri dari satu kata
    for (int i = 0; username[i] != '\0'; i++) {
        if (username[i] == ' ') {
            printf("Username HANYA boleh satu kata.\n");
            return;
        }
    }

    printf("Password: ");
    scanf("%s", password);

    // Validasi untuk memastikan password hanya terdiri dari satu kata
    for (int i = 0; password[i] != '\0'; i++) {
        if (password[i] == ' ') {
            printf("Password HANYA boleh satu kata.\n");
            return;
        }
    }

    // Cek apa username sudah ada
    for (int i = 0; i < userList.count; i++) {
        if (custom_strcmp(userList.users[i].username, username) == 0) {
            printf("Akun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", username);
            return; 
        }
    }

    // Menyalin username ke daftar pengguna (userList).
    custom_strcpy(userList.users[userList.count].username, username);
    // Menyalin password ke daftar pengguna (userList).
    custom_strcpy(userList.users[userList.count].password, password);
    // Inisialisasi money = 0 untuk pengguna baru.
    userList.users[userList.count].money = 0;
     // Menambah jumlah pengguna di userList.
    userList.count++;

    printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
}