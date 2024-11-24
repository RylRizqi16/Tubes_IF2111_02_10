#ifndef REGISTER_H
#define REGISTER_H

#include <stdio.h>
#include "boolean.h" 

#define MAX_LEN 100 

typedef struct {
    char username[MAX_LEN];
    char password[MAX_LEN];
} User;

void registerUser();

#endif
