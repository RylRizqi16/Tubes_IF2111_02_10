#ifndef LOAD_H
#define LOAD_H

#include "../../ADT/Mesin_Karakter/mesinkarakter.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"

void load(char *filename, int *itemCount, char items[][100], int prices[], int *userCount, char users[][100], char passwords[][100], int balances[]);

#endif