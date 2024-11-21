#include "login.h"

int custom_strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

// Masuk sebagai pengguna yang telah terdaftar
void loginUser(char username[MAX_LEN], char password[MAX_LEN]) {
    if (currentUserIndex != -1) {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", userList.users[currentUserIndex].username);
        return;
    }
    
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

// Cari pengguna
    for (int i = 0; i < userList.count; i++) {
        if (custom_strcmp(userList.users[i].username, username) == 0 &&
            custom_strcmp(userList.users[i].password, password) == 0) {
            currentUserIndex = i;
            printf("Anda telah login ke PURRMART sebagai %s.\n", username);
            return;
        }
    }
    printf("Username atau password salah.\n");
}