#include "arrayuser.h"

void CreateArrayUser(ArrayUser *AU){
    (*AU).Neff = 0;
}

void TulisIsiUser(ArrayUser *user){
        for (int i = IdxMin; i <= user->Neff; i++) {
            printf("%s | %s | %d\n", user->user[i].name, user->user[i].password, user->user[i].money);
        }
    }

boolean Apakah_Username_Ada(ArrayUser users, char *username) {
    int i;
    for (i = IdxMin; i <= users.Neff; i++) {
        int j = 0;
        boolean same = true;
        
        while (users.user[i].name[j] != '\0' && username[j] != '\0') {
            if (users.user[i].name[j] != username[j]) {
                same = false;
                break;
            }
            j++;
        }
        if (same && users.user[i].name[j] == '\0' && username[j] == '\0') {
            return true;
        }
    }
    return false;
}

boolean Apakah_Password_Valid(ArrayUser *users, char *username, char *password) {
    int i;
    for (i = IdxMin; i <= users->Neff; i++) {
        int j = 0;
        boolean username_same = true;

        while (users->user[i].name[j] != '\0' && username[j] != '\0') {
            if (users->user[i].name[j] != username[j]) {
                username_same = false;
                break;
            }
            j++;
        }
        
        if (username_same && users->user[i].name[j] == '\0' && username[j] == '\0') {
            int k = 0;
            boolean password_same = true;
            
            while (users->user[i].password[k] != '\0' && password[k] != '\0') {
                if (users->user[i].password[k] != password[k]) {
                    password_same = false;
                    break;
                }
                k++;
            }

            if (password_same && users->user[i].password[k] == '\0' && password[k] == '\0') {
                return true;
            } else {
                return false; // Password salah untuk username yang benar
            }
        }
    }
    return false;
}