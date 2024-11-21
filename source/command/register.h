#ifndef REGISTER_H
#define REGISTER_H

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
void custom_strcpy(char *dest, const char *src);

void registerUser(char username[MAX_LEN], char password[MAX_LEN]);
/* Mendaftarkan pengguna baru ke dalam sistem.
   I.S. : userList mungkin kosong atau sudah berisi beberapa pengguna
   F.S. : Jika username belum terdaftar, pengguna baru ditambahkan ke userList
          Jika username sudah terdaftar, tidak ada perubahan pada userList
          Jika userList penuh, tidak ada perubahan pada userList 
          User diminta memasukkan username dan password, HANYA boleh satu kata*/

// Deklarasi fungsi manual (jika diperlukan di tempat lain)

#endif 
