#include "register.h"

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

    // Cek apakah username sudah ada
    for (int i = 0; i < userList.count; i++) {
        if (strcmp(userList.users[i].username, username) == 0) {
            printf("Akun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", username);
            return;
        }
    }
    
    // Tambahkan pengguna baru
    strcpy(userList.users[userList.count].username, username);
    strcpy(userList.users[userList.count].password, password);
    userList.users[userList.count].money = 0; // Default money
    userList.count++;
    printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
}