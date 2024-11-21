#include <stdio.h>
#include <stdlib.h>
#include "quit.h"

void quit(char *filename, int itemCount, char items[][100], int prices[], int userCount, char users[][100], char passwords[][100], int balances[]) {
    printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");
    START(NULL, "");
    ADV();
    char response = GetCC();

    if (response == 'Y' || response == 'y') {
        save(filename, itemCount, items, prices, userCount, users, passwords, balances);
    }

    printf("Kamu keluar dari PURRMART. Dadah ^_^/\n");
    exit(0);
}