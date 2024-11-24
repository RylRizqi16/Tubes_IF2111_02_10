#include "register.h"
#include "../ADT/Mesin_Kata/mesinkata.h"
#include "../ADT/Mesin_Karakter/mesinkarakter.h"

void registerUser() {
    User user;
    char username[MAX_LEN];
    char password[MAX_LEN];
    boolean validInput = false;
    FILE *file;

    while (!validInput) {
        printf("Username: "); // Input username
        STARTWORD(stdin, "word");
        int i = 0;
        while (currentWord.TabWord[i] != '\0'){
            username[i] = currentWord.TabWord[i];
            i++;
        }
        username[i] = '\0';

        // Cek apakah username mengandung spasi
        boolean validUsername = true;
        for (int k = 0; username[k] != '\0'; k++) {
                if (username[k] == ' ') {
                    printf("Username HANYA bisa satu kata!\n");
                    validUsername = false;
                    break;
                }
            }

        if (!validUsername) {
            continue;  // Minta input ulang jika username tidak valid
            }

        // Cek apakah username sudah digunakan
        file = fopen("users.txt", "r"); // Membuka file untuk membaca data pengguna
        if (file == NULL) {
            printf("Terjadi kesalahan saat membuka file.\n");
            return; 
        }

        boolean usernameTaken = false; 
        char fileUsername[MAX_LEN], filePassword[MAX_LEN];
        
        while (fscanf(file, "%s %s", fileUsername, filePassword) != EOF) {
            if (isEqual(username, fileUsername)) {
                usernameTaken = true; // Kalau ditemukan username yang sama
                break;
            }
        }
        fclose(file); // Tutup file setelah selesai membaca

        if (usernameTaken) {
            printf("Username sudah dipakai, buat username lain!\n");
            continue;  // Minta input ulang jika username sudah dipakai
            }

    validInput = true;    
}  

    while (!validInput) {
        printf("Password: "); // Input password 
        STARTWORD(stdin, "word");
        int j = 0;
        while (currentWord.TabWord[j] != '\0') {
            password[j] = currentWord.TabWord[j];
            j++;
        }
        password[j] = '\0';

        // Cek apakah password mengandung spasi
        boolean validPassword = true;
        for (int k = 0; password[k] != '\0'; k++) {
            if (password[k] == ' ') {
                printf("Password HANYA bisa satu kata!\n");
                validPassword = false;
                break;
            }
        }
    
        if (!validPassword) {
            continue;  // Minta input ulang jika password tidak valid
            }

        validInput = true;

        // Menyimpan informasi user baru ke file "users.txt"
        file = fopen("users.txt", "a"); // Membuka file untuk menambahkan data (mode append)
        if (file != NULL) {
            fprintf(file, "%s %s\n", username, password); 
            fclose(file); 
            printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
        } 
        else {
            printf("Terjadi kesalahan saat menyimpan data.\n");
        }
    }
}