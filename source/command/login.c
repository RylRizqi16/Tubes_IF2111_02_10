#include "login.h"
#include "../ADT/Mesin_Kata/mesinkata.h"
#include "../ADT/Mesin_Karakter/mesinkarakter.h"

boolean login;
char username[MAX_LEN];

void loginUser() {
    char inputUsername[MAX_LEN];
    char inputPassword[MAX_LEN];
    boolean validInput = false;
    FILE *file;

    while (!validInput) {
        printf("Username: "); // Input username
        STARTWORD(stdin, "word");
        int i = 0;
        while (currentWord.TabWord[i] != '\0'){
            inputUsername[i] = currentWord.TabWord[i];
            i++;
        }
        inputUsername[i] = '\0';

        printf("Password: "); // Input username
        STARTWORD(stdin, "word");
        int j = 0;
        while (currentWord.TabWord[j] != '\0') {
            inputPassword[j] = currentWord.TabWord[j];
            j++;
        }
        inputPassword[j] = '\0';

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