#ifndef LOGIN_H
#define LOGIN_H

#include <stdio.h> 

#define MAX_USERS 100
#define MAX_LEN 100

typedef struct {
    char username[MAX_LEN];
    char password[MAX_LEN];
    int money;
} User;

typedef struct {
    User users[MAX_USERS];
    int count;
} UserList;

UserList userList;
int currentUserIndex = -1;

int custom_strcmp(const char *str1, const char *str2);

void loginUser(char username[MAX_LEN], char password[MAX_LEN]);
/* Melakukan login pengguna ke sistem.
   I.S. : userList mungkin kosong atau berisi pengguna terdaftar, 
          currentUserIndex bernilai -1 jika tidak ada pengguna yang login
   F.S. : Jika username dan password cocok dengan pengguna dalam userList,
          currentUserIndex menunjuk ke indeks pengguna yang login
          Jika username atau password salah, currentUserIndex tetap -1
          Jika ada pengguna lain yang sedang login, meminta pengguna untuk logout terlebih dahulu */

#endif 