#include "../../header/boolean.h"
#include "../User/user.h"
#include <stdio.h>
#include <stdlib.h>
#ifndef ARRAYUSER_H
#define ARRAYUSER_H

#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999

typedef struct
{
    User user[IdxMax - IdxMin + 1];
    int Neff;
} ArrayUser;

void CreateArrayUser(ArrayUser *AU);

void TulisIsiUser(ArrayUser *user);

boolean Apakah_Username_Ada(ArrayUser users, char *username);

boolean Apakah_Password_Valid(ArrayUser *users, char *username, char *password);

#endif