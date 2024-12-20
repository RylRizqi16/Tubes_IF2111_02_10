#include "user.h"
#include <stdlib.h>
#include <stdio.h>

User createUser(char *nama, char *pw, int uang){
    User u;
    int i;
    int j;
    for (i = 0; i < MAX_LEN && nama[i] != '\0'; i++) {
        u.name[i] = nama[i];
    }
    u.name[i] = '\0';

    for (j = 0; j < MAX_LEN && pw[j] != '\0'; j++) {
        u.password[j] = pw[j];
    }
    u.password[j] = '\0';
    u.money = uang;
    return u;
}