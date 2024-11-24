#include "register.h"
#include "../ADT/Mesin_Kata/mesinkata.h"
#include "../ADT/Mesin_Karakter/mesinkarakter.c"

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

void registerUser() {
    User user;
    char username[MAX_LEN];
    char password[MAX_LEN];
    boolean validInput = false;
    FILE *file;

    while (!validInput) {
        printf("Username: ");
        readInput(username, MAX_LEN);

        // Cek apakah username mengandung spasi
        boolean validUsername = true;
        for (int k = 0; username[k] != '\0'; k++) {
            if (username[k] == ' ') {
                printf("Username HANYA bisa satu kata!\n");
                validUsername = false;
                break;
            }
        }
        if (!validUsername) continue;

        // Cek apakah username sudah digunakan
        file = fopen("users.txt", "r");
        if (file == NULL) {
            printf("Terjadi kesalahan saat membuka file.\n");
            return;
        }

        boolean usernameTaken = false;
        char fileUsername[MAX_LEN];
        while (fscanf(file, "%s", fileUsername) != EOF) {
            if (isEqual(username, fileUsername)) {
                usernameTaken = true;
                break;
            }
        }
        fclose(file);

        if (usernameTaken) {
            printf("Username sudah dipakai, buat username lain!\n");
            continue;
        }

        validInput = true;
    }

    validInput = false; // Reset untuk validasi password
    while (!validInput) {
        printf("Password: ");
        readInput(password, MAX_LEN);

        // Cek apakah password mengandung spasi
        boolean validPassword = true;
        for (int k = 0; password[k] != '\0'; k++) {
            if (password[k] == ' ') {
                printf("Password HANYA bisa satu kata!\n");
                validPassword = false;
                break;
            }
        }
        if (!validPassword) continue;

        validInput = true;

        // Simpan user baru ke file
        file = fopen("users.txt", "a");
        if (file != NULL) {
            fprintf(file, "%s %s\n", username, password);
            fclose(file);
            printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
        } else {
            printf("Terjadi kesalahan saat menyimpan data.\n");
        }
    }
}

//Testing
//int main() {
//    printf("=== Testing Register User ===\n");

//    registerUser();

//    printf("=== Testing Completed ===\n");

//    return 0;
//}
