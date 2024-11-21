#include "logout.h"

void logoutUser() {
    if (currentUserIndex == -1) {
        printf("Anda belum login. Silakan LOGIN terlebih dahulu.\n");
        return;
    }
    printf("%s telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n",
           userList.users[currentUserIndex].username);
    currentUserIndex = -1;
}