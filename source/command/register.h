#include <stdio.h>
#include <string.h>

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

void registerUser(char username[MAX_LEN], char password[MAX_LEN]); 
/* Mendaftarkan pengguna baru ke dalam sistem.
   I.S. : userList mungkin kosong atau sudah berisi beberapa pengguna
   F.S. : Jika username belum terdaftar, pengguna baru ditambahkan ke userList
          Jika username sudah terdaftar, tidak ada perubahan pada userList
          Jika userList penuh, tidak ada perubahan pada userList 
          User diminta memasukkan username dan password, HANYA boleh satu kata*/