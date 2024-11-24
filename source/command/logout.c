#include "logout.h"

boolean loginUser;

void logoutUser() {
    char username[MAX_LEN];
    char password[MAX_LEN];
    int money;

    if (loginUser) {
        for (int i = 0; username[i] != '\0'; i++) {
            username[i] = '\0';
        }
        for (int i = 0; password[i] != '\0'; i++) { 
            password[i] = '\0'; 
        }
        money = 0; 
        loginUser = false;
    }
    else {
        printf("Kamu belum melakukan login, silakan login terlebih dahulu!"); 
        loginUser = true;
    }
}

//Testing 
//int main() {
//    printf("=== Testing Logout User ===\n");

//    logoutUser();

//    printf("=== Testing Completed ===\n");

//    return 0;
//}
