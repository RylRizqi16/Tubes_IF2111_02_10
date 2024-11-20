// Ini adalah prototipe untuk algoritmanya

#include <stdio.h>
#include "quit.h"
// Temporary
#include <string.h>

void quit(char *filename, int itemCount, char items[][100], int prices[], int userCount, char users[][100], char passwords[][100], int balances[]) {
    char saveOption;
    printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");
    scanf("%c", &saveOption);
    if (saveOption == 'Y' || saveOption == 'y') {
        save(filename, itemCount, items, prices, userCount, users, passwords, balances);
    }
    printf("\nKamu keluar dari PURRMART. Dadah ^_^/\n");
    exit(0);
}