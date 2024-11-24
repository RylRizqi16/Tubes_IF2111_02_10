#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
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
#include "ADT/Mesin_Kata/mesinkata.h"
#include "ADT/ArrayDinBarang/arraydinbarang.h"
#include "ADT/ArrayStatikUser/arrayuser.h"
#include "ADT/Barang/barang.h"
#include "ADT/Mesin_Karakter/mesinkarakter.h"
#include "ADT/Mesin_Kata/mesinkata.h"
#include "ADT/QueueBarang/queue_barang.h"
#include "ADT/User/user.h"


int main() {
    char input[100];
    Word currentCommand;
    int session = 0;  //Welcome Menu, 1: Login Menu, 2: Main Menu

    printf("Selamat datang di PURRMART! Ketik HELP untuk bantuan.\n");

    while (1) {
        // Tampilkan menu berdasarkan sesi
        ClearCurrentWord();
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

        // Membaca Input
        printf(">> ");
        scanf("%s", input);

        if (EndWord) {
            printf("Tidak ada input yang diberikan.\n");
            continue;
        }
        processCommand(input, &session);
    }
    return 0;
}

// Fungsi untuk mengolah command yang diberikan
void processCommand(char command, int session) {
    if (BandingkanChar(command, "QUIT") == 1 || BandingkanChar(command, "quit") == 1) {
        char saveFile[50];
        printf("Masukkan nama file penyimpanan: ");
        scanf("%s", saveFile);
        quit(saveFile);
    } 
    else if (*session == 0) { // Welcome Menu
        if (BandingkanChar(command, "START") == 1 || BandingkanChar(command, "start") == 1) {
            *session = 1;
        } 
        else if (BandingkanChar(command, "LOAD") == 1 || BandingkanChar(command, "load") == 1) {
            char filename[50];
            printf("Masukkan nama file yang ingin di-load: ");
            scanf("%s", filename);

            ArrayBarang items = CreateArrayBarang();
            ArrayUser users = CreateUserArray();

            load(filename, &itemCount, items, prices, &userCount, users, passwords, balances);
        }
        else if (BandingkanChar(command, "HELP") == 1 || BandingkanChar(command, "help") == 1) {
            welcome_menu();
        } 
        else {
            printf("Command tidak valid. Ketik HELP untuk daftar command.\n");
        }
    } 
    else if (*session == 1) { // Login Menu
        char username[100], password[100];
        if (command == "REGISTER" || command == "register") {
            if (BandingkanChar(command, "REGISTER") == 1 || BandingkanChar(command, "register") == 1) {
                printf("Username: ");
                scanf("%s", username);
                printf("Password: ");
                scanf("%s", password);
                registerUser(username, password);
        }
        else if (BandingkanChar(command, "LOGIN") == 1 || BandingkanChar(command, "login") == 1) {
            printf("Username: ");
            scanf("%s", username);
            printf("Password: ");
            scanf("%s", password);
            if (loginUser(username, password)) {
                *session = 2;
            }
        } 
        else if (BandingkanChar(command, "HELP") == 1 || BandingkanChar(command, "help") == 1) {
            login_menu();
        } 
        else {
            printf("Command tidak valid. Ketik HELP untuk daftar command.\n");
        }
    } 
    else if (*session == 2) { // Main Menu
        if (BandingkanChar(command, "WORK") == 1 || BandingkanChar(command, "work") == 1) {
            work();
        } else if (BandingkanChar(command, "WORKCHALLENGE") == 1 || BandingkanChar(command, "workchallenge") == 1) {
            workChallenge();
        } else if (BandingkanChar(command, "STORELIST") == 1 || BandingkanChar(command, "storelist") == 1) {
            storeList();
        } else if (BandingkanChar(command, "STORE REQUEST") == 1 || BandingkanChar(command, "store request") == 1) {
            storeRequest();
        } else if (BandingkanChar(command, "STORE SUPPLY") == 1 || BandingkanChar(command, "store supply") == 1) {
            storeSupply();
        } else if (BandingkanChar(command, "STORE REMOVE") == 1 || BandingkanChar(command, "store remove") == 1) {
            storeRemove();
        } else if (BandingkanChar(command, "LOGOUT") == 1 || BandingkanChar(command, "logout") == 1) {
            logout();
            *session = 1;
        } else if (BandingkanChar(command, "SAVE") == 1 || BandingkanChar(command, "save") == 1) {
            char filename[50];
            sscanf(command + 5, "%s", filename);
            saveState(filename);
        } else if (BandingkanChar(command, "HELP") == 1 || BandingkanChar(command, "help") == 1) {
            displayMainMenu();
        } else {
            printf("Command tidak valid. Ketik HELP untuk daftar command.\n");
        }
    }
    }
}