#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "command/cart.h"
#include "command/help.h"
#include "command/history.h"
#include "command/load.h"
#include "command/login_logout.h"
#include "command/quit.h"
#include "command/register.h"
#include "command/save.h"
#include "command/store.h"
#include "command/wishlist.h"
#include "command/work.h"
#include "command/optimasi_rute.h"
#include "command/work_challenge.h"
#include "ADT/ArrayDinBarang/arraydinbarang.h"
#include "ADT/ArrayStatikUser/arrayuser.h"
#include "ADT/Barang/barang.h"
#include "ADT/Mesin_Karakter/mesinkarakter.h"
#include "ADT/Mesin_Kata/mesinkata.h"
#include "ADT/QueueBarang/queue_barang.h"
#include "ADT/User/user.h"
#include "ADT/Setmap/setmap.h"
#include "ADT/Stack/stack.h"
#include "ADT/LinkedList/linkedlist.h"


// Fungsi untuk mengolah command yang diberikan
void processCommand(char *command, int *session, ArrayBarang *items, ArrayUser *users, QueueBarang *request, PenggunaSekarang *PS, Keranjang *cart, LinkedList *Wishlist) {
    if (BandingkanChar(command, "QUIT") == 1 || BandingkanChar(command, "quit") == 1) {
        quit();
    } else if (*session == 0) { // Welcome Menu
        if (BandingkanChar(command, "START") == 1 || BandingkanChar(command, "start") == 1) {
            *session = 1;
        } else if (BandingkanChar(command, "LOAD") == 1 || BandingkanChar(command, "load") == 1) {
            char saveFile[50];
            printf("Masukkan nama file yang ingin di-load: ");
            STARTSENTENCE("", "");
            WordToString(currentWord, saveFile);
            load(saveFile, items, users);
            *session = 1;
        } else if (BandingkanChar(command, "HELP") == 1 || BandingkanChar(command, "help") == 1) {
            welcome_menu();
        } else {
            printf("Command tidak valid. Ketik HELP untuk daftar command.\n");
        }
    } else if (*session == 1) { // Login Menu
        if (BandingkanChar(command, "REGISTER") == 1 || BandingkanChar(command, "register") == 1) {
            register_user(users);
        } else if (BandingkanChar(command, "LOGIN") == 1 || BandingkanChar(command, "login") == 1) {
            login(users, PS);
            if (isUserLoggedIn(*PS)) {
                *session = 2;
            }
        } else if (BandingkanChar(command, "HELP") == 1 || BandingkanChar(command, "help") == 1) {
            login_menu();
        } else {
            printf("Command tidak valid. Ketik HELP untuk daftar command.\n");
        }
    } else if (*session == 2) { // Main Menu
        if (BandingkanChar(command, "WORK") == 1 || BandingkanChar(command, "work") == 1) {
            int job_id;
            printf("=== Selamat datang di Work Simulator ===\n");
            printf("Pilih pekerjaan:\n");
            printf("1. Evil Lab Assistant\n");
            printf("2. OWCA Hiring Manager\n");
            printf("3. Cikapundunginator Caretaker\n");
            printf("4. Mewing Specialist\n");
            printf("5. Inator Connoisseur\n");
            printf("Pilihan Anda: ");
            scanf("%d", &job_id);

            Job selected_job = get_job(job_id);

            if (selected_job.job_id == 0) {
                printf("Pekerjaan tidak valid.\n");
            }

            printf("Anda telah memilih pekerjaan dengan durasi %d detik dan gaji %d rupiah.\n", selected_job.duration, selected_job.salary);

            start_job(selected_job.duration, selected_job.salary);
            printf("Uang Anda sekarang: %d\n", PS->money);
            PS->money += PS->money + selected_job.salary;
            printf("Uang Anda sekarang: %d\n", PS->money);

            printf("\nSelamat, pekerjaan Anda telah selesai!\n");
        } else if (BandingkanChar(command, "WORK CHALLENGE") == 1 || BandingkanChar(command, "work challenge") == 1) {
            work_challenge(&PS->money);
            PS -> money += 1000;
        } else if (BandingkanChar(command, "STORE LIST") == 1 || BandingkanChar(command, "store list") == 1) {
            StoreList(items);
        } else if (BandingkanChar(command, "STORE REQUEST") == 1 || BandingkanChar(command, "store request") == 1) {
            StoreRequest(items, request);
        } else if (BandingkanChar(command, "STORE SUPPLY") == 1 || BandingkanChar(command, "store supply") == 1) {
            StoreSupply(items, request);
        } else if (BandingkanChar(command, "STORE REMOVE") == 1 || BandingkanChar(command, "store remove") == 1) {
            StoreRemove(items);
        } else if (BandingkanChar(command, "LOGOUT") == 1 || BandingkanChar(command, "logout") == 1) {
            logout(PS);
            *session = 1;
        } else if (BandingkanChar(command, "SAVE") == 1 || BandingkanChar(command, "save") == 1) {
            char saveFile[50];
            printf("Masukkan nama file penyimpanan: ");
            STARTSENTENCE("", "");
            WordToString(currentWord, saveFile);
            save(saveFile, items, users);
        } else if (BandingkanChar(command, "HELP") == 1 || BandingkanChar(command, "help") == 1) {
            main_menu();
        } else if (BandingkanChar(command, "CART ADD") == 1 || BandingkanChar(command, "cart add") == 1) {
            char nama_barang[50];
            char strquantity[10];
            int quantity;
            printf("Masukkan nama barang: ");
            STARTSENTENCE("", "");
            WordToString(currentWord, nama_barang);

            printf("Masukkan jumlah barang: ");
            STARTSENTENCE("", "");
            WordToString(currentWord, strquantity);
            quantity = CharToInt(strquantity);

            cart_add(cart, items, nama_barang, quantity);
        } else if (BandingkanChar(command, "CART REMOVE") == 1 || BandingkanChar(command, "cart remove") == 1) {
            char nama_barang[50];
            char strquantity[10];
            int quantity;
            printf("Masukkan nama barang yang ingin dihapus: ");
            STARTSENTENCE("", "");
            WordToString(currentWord, nama_barang);

            printf("Masukkan jumlah barang yang ingin dihapus: ");
            STARTSENTENCE("", "");
            WordToString(currentWord, strquantity);
            quantity = CharToInt(strquantity);

            cart_remove(cart, items, nama_barang, quantity);
        } else if (BandingkanChar(command, "CART SHOW") == 1 || BandingkanChar(command, "cart show") == 1) {
            cart_show(*cart);
        } else if (BandingkanChar(command, "CART PAY") == 1 || BandingkanChar(command, "cart pay") == 1) {
            char history[100];
            cart_pay(cart, &PS->money, history);
            if (history[0] != '\0') {
                printf("Barang paling mahal yang kamu beli: %s\n", history);
            }
        } else if (BandingkanChar(command, "HISTORY") == 1 || BandingkanChar(command, "history") == 1) {
            static char history[100];
            if (history[0] != '\0') {
                printf("Transaksi terakhir, barang paling mahal: %s\n", history);
            } else {
                printf("Belum ada transaksi yang tercatat.\n");
            }
        } else if (BandingkanChar(command, "PROFILE") == 1 || BandingkanChar(command, "profile") == 1) {
            printf("Saldo: %d\n", PS->money);
        } else if (BandingkanChar(command, "WISHLIST ADD") == 1 || BandingkanChar(command, "wishlist add") == 1) {
            WishlistAdd(items, Wishlist);
        } else if (BandingkanChar(command, "WISHLIST REMOVE") == 1 || BandingkanChar(command, "wishlist remove") == 1) {
            WishlistRemove(Wishlist);
        } else if (BandingkanChar(command, "WISHLIST SWAP") == 1 || BandingkanChar(command, "wishlist swap") == 1) {
            int i, j;
            printf("Masukkan indeks barang pertama: ");
            scanf("%d", &i);
            printf("Masukkan indeks barang kedua: ");
            scanf("%d", &j);
            WishlistSwap(Wishlist, i, j);
        } else if (BandingkanChar(command, "WISHLIST REMOVE INDEX") == 1 || BandingkanChar(command, "wishlist remove index") == 1) {
            int i;
            printf("Masukkan indeks barang yang ingin dihapus: ");
            scanf("%d", &i);
            WishlistRemoveIndex(Wishlist, i);
        } else if (BandingkanChar(command, "WISHLIST CLEAR") == 1 || BandingkanChar(command, "wishlist clear") == 1) {
            WishlistClear(Wishlist);
        } else if (BandingkanChar(command, "WISHLIST SHOW") == 1 || BandingkanChar(command, "wishlist show") == 1) {
            WishlistShow(Wishlist);
        } else if (BandingkanChar(command, "OPTIMASI RUTE") == 1 || BandingkanChar(command, "optimasi rute") == 1) {
            optimasi_rute();
        } else {
            printf("Command tidak valid. Ketik HELP untuk daftar command.\n");
        }
    }
}

int main() {
    char input[100];
    int session = 0;
    ArrayBarang items = CreateArrayBarang();
    ArrayUser users;
    QueueBarang request;
    PenggunaSekarang PS;
    Keranjang cart;
    LinkedList Wishlist;
    CreateEmptyLinkedList(&Wishlist);
    createPenggunaSekarang(&PS);
    CreateQueueBarang(&request);
    CreateArrayUser(&users);
    CreateKeranjang(&cart);

    printf("Selamat datang di PURRMART! Ketik HELP untuk bantuan.\n");

    while (1) {
        // Tampilkan menu berdasarkan sesi
        ClearCurrentWord();
        switch (session) {
            case 0:
                printf("\n======================================[ Welcome Menu PURRMART ]====================================\n");
                break;
            case 1:
                printf("\n=======================================[ LOGIN Menu PURRMART ]=====================================\n");
                break;
            case 2:
                printf("\n========================================[ Main Menu PURRMART ]=====================================\n");
                break;
        }

        // Membaca Input
        printf(">> ");
        STARTSENTENCE("", "");
        WordToString(currentWord, input);
        processCommand(input, &session, &items, &users, &request, &PS, &cart, &Wishlist);
    }
    return 0;
}
