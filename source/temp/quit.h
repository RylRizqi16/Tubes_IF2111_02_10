#ifndef QUIT_H
#define QUIT_H

#include "../../ADT/Mesin_Karakter/mesinkarakter.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "save.h"

void quit(char *filename, int itemCount, char items[][100], int prices[], int userCount, char users[][100], char passwords[][100], int balances[]);

#endif