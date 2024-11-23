#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "command/start.h"
#include "command/load.h"
#include "command/login.h"
#include "command/logout.h"
#include "command/register.h"
#include "command/work.h"
#include "command/workchallenge.h"
#include "command/store.h"
#include "command/help.h"
#include "command/save.h"
#include "command/quit.h"

int main() {
    char input[100];
    int session = 0; // 0: Welcome Menu, 1: Login Menu, 2: Main Menu

    printf("Selamat datang di PURRMART! Ketik HELP untuk bantuan.\n");

    while (1) {
        // Display menu sesuai sesi
        switch (session) {
            case 0:
                welcome_menu();
                break;
            case 1:
                login_menu();
                break;
            case 2:
                main_menu();
                break;
        }

        // Baca input pengguna
        printf(">> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        // Tangani command
        inputCommand(input, &session);
    }

    return 0;
}

// Fungsi untuk menangani command dari pengguna
void inputCommand(char *command, int *session) {
    if (strcasecmp(command, "QUIT") == 0) {
        char saveOption;
        printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");
        scanf(" %c", &saveOption);
        getchar();
        if (saveOption == 'Y' || saveOption == 'y') {
            char filename[50];
            printf("Masukkan nama file untuk menyimpan: ");
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = 0; 
            save(filename);
        }
        printf("Kamu keluar dari PURRMART. Dadah ^_^/\n");
        exit(0);
    } else if (*session == 0) { // Welcome Menu
        if (strcasecmp(command, "START") == 0) {
            startSession();
            *session = 1;
        } else if (strncasecmp(command, "LOAD", 4) == 0) {
            char filename[50];
            sscanf(command + 5, "%s", filename);
            if (loadSession(filename)) {
                *session = 1;
            }
        } else if (strcasecmp(command, "HELP") == 0) {
            welcome_menu();
        } else {
            printf("Command tidak valid. Ketik HELP untuk daftar command.\n");
        }
    } else if (*session == 1) { // Login Menu
        if (strcasecmp(command, "REGISTER") == 0) {
            registerUser();
        } else if (strcasecmp(command, "LOGIN") == 0) {
            if (loginUser()) {
                *session = 2;
            }
        } else if (strcasecmp(command, "HELP") == 0) {
            login_menu();
        } else {
            printf("Command tidak valid. Ketik HELP untuk daftar command.\n");
        }
    } else if (*session == 2) { // Main Menu
        if (strcasecmp(command, "WORK") == 0) {
            work();
        } else if (strcasecmp(command, "WORK CHALLENGE") == 0) {
            workChallenge();
        } else if (strcasecmp(command, "STORE LIST") == 0) {
            storeList();
        } else if (strcasecmp(command, "STORE REQUEST") == 0) {
            storeRequest();
        } else if (strcasecmp(command, "STORE SUPPLY") == 0) {
            storeSupply();
        } else if (strcasecmp(command, "STORE REMOVE") == 0) {
            storeRemove();
        } else if (strcasecmp(command, "LOGOUT") == 0) {
            logout();
            *session = 1;
        } else if (strncasecmp(command, "SAVE", 4) == 0) {
            char filename[50];
            sscanf(command + 5, "%s", filename);
            saveState(filename);
        } else if (strcasecmp(command, "HELP") == 0) {
            displayMainMenu();
        } else {
            printf("Command tidak valid. Ketik HELP untuk daftar command.\n");
        }
    }
}
