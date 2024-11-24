#include "login.h"
#include "../ADT/Mesin_Kata/mesinkata.h"
#include "../ADT/Mesin_Karakter/mesinkarakter.c"

boolean login;
char username[MAX_LEN];

void readInput(char *dest, int maxLen) {
    START("", ""); 
    int i = 0;

    while (i < maxLen - 1 && !IsEOP() && GetCC() != '\n') { 
        dest[i] = GetCC(); // Simpan karakter ke dalam array tujuan
        i++;
        ADV(); // Lanjutkan ke karakter berikutnya
    }

    dest[i] = '\0'; // Akhiri string dengan null character
}

boolean isEqual(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

void loginUser() {
    char inputUsername[MAX_LEN];
    char inputPassword[MAX_LEN];
    boolean validInput = false;
    FILE *file;

    while (!validInput) {
        printf("Username: ");
        readInput(inputUsername, MAX_LEN);

        printf("Password: "); // Input username
        readInput(inputPassword, MAX_LEN);

        // Membuka file untuk validasi
        file = fopen("users.txt", "r");
        if (file == NULL) {
            printf("Terjadi kesalahan saat membuka file.\n");
            return; // Keluar jika file gagal dibuka
        }

        // Menyocokan dengan data user yang sudah terdaftar
        boolean registeredUser = false;
        char fileUsername[MAX_LEN], filePassword[MAX_LEN];

        // Membaca file untuk menyocokan username dan password
        while (fscanf(file, "%s %s", fileUsername, filePassword) != EOP) {
            if (isEqual(inputUsername, fileUsername) && isEqual(inputPassword, filePassword)) {
                registeredUser = true;
                break;
            }
        }
        fclose(file);

        // Jika cocok dengan daftar user
        if (registeredUser) {
            printf("Login berhasil! Selamat datang, %s.\n", inputUsername);
            // Menyalin inputUsername ke variabel global username
            int i = 0;
            while (inputUsername[i] != '\0') {
                username[i] = inputUsername[i];
                i++;
            }
            username[i] = '\0';
            login = true;
            validInput = true;
        } else {
            printf("Username atau password salah. Silakan coba lagi.\n");
        }
    }
}

//Testing 
//int main() {
//    printf("=== Testing Register User ===\n");

//    loginUser();

//    printf("=== Testing Completed ===\n");

//    return 0;
//}