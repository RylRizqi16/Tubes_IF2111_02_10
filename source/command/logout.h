#ifndef LOGOUT_H
#define LOGOUT_H

#include <stdio.h>
#include "../header/boolean.h"

#define MAX_LEN 100

typedef struct {
    char username[MAX_LEN];
    char password[MAX_LEN];
    int money;
} User;

extern boolean loginUser;
void logoutUser();

#endif