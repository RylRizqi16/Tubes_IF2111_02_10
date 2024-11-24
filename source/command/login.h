#ifndef LOGIN_H
#define LOGIN_H

#include <stdio.h> 
#include "../header/boolean.h"

#define MAX_LEN 100
#define EOP EOF

typedef struct {
    char username[MAX_LEN];
    char password[MAX_LEN];
    int money;
} User;

extern boolean login;
extern char username[MAX_LEN];

void loginUser();
/* Melakukan login pengguna ke sistem.
   I.S. : userList mungkin kosong atau berisi pengguna terdaftar, 
          currentUserIndex bernilai -1 jika tidak ada pengguna yang login
   F.S. : Jika username dan password cocok dengan pengguna dalam userList,
          currentUserIndex menunjuk ke indeks pengguna yang login
          Jika username atau password salah, currentUserIndex tetap -1
          Jika ada pengguna lain yang sedang login, meminta pengguna untuk logout terlebih dahulu */

#endif 