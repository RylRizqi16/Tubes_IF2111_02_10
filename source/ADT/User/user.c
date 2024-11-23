#include "user.h"
#include <stdlib.h>

User createUser(char *nama, char *pw, int uang){
    User u;
    int i;
    int j;
    for (i = 0; i < MAX_LEN && nama[i] != '\0'; i++) {
        u.name[i] = nama[i];
    }
    u.name[i] = '\0';

    for (j = 0; i < MAX_LEN && pw[j] != '\0'; i++) {
        u.password[i] = pw[i];
    }
    u.money = uang;
    return u;
}