#include "login.h"

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
        if (strcmp(userList.users[i].username, username) == 0 &&
            strcmp(userList.users[i].password, password) == 0) {
            currentUserIndex = i;
            printf("Anda telah login ke PURRMART sebagai %s.\n", username);
            return;
        }
    }
    printf("Username atau password salah.\n");
}