#ifndef LOGIN_H
#define LOGIN_H

#include "../ADT/ArrayStatikUser/arrayuser.h"
#include "../ADT/Mesin_Kata/mesinkata.h"

typedef struct {
    boolean isLoggedIn;
    int currentUserIdx;  // Menyimpan indeks user yang sedang login
    int money;
} PenggunaSekarang;

void createPenggunaSekarang(PenggunaSekarang *PS);

void login(ArrayUser *users, PenggunaSekarang *PS);

void logout(PenggunaSekarang *PS);

boolean isUserLoggedIn(PenggunaSekarang PS);

int getCurrentUserIdx(PenggunaSekarang PS);

int getCurrentUserMoney(PenggunaSekarang PS);

#endif
