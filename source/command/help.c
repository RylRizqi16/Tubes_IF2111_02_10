#include "help.h"

void welcome_menu(){
    printf("\n=====================================[ Welcome Menu Help PURRMART ]===================================\n");
    printf("========================================================================================================\n");
    printf("\nGUNAKAN COMMAND BERIKUT UNTUK BERINTERAKSI DENGAN PROGRAM INI\n");
    printf("1. START            : Masuk sesi baru\n");
    printf("2. LOAD <nama_file> : Memulai sesi berdasarkan file konfigurasi\n");
    printf("3. QUIT             : Keluar dari program\n");
}

void login_menu(){
    printf("\n=====================================[ LOGIN Menu Help PURRMART ]===================================\n");
    printf("======================================================================================================\n");
    printf("\nGUNAKAN COMMAND BERIKUT UNTUK BERINTERAKSI DENGAN PROGRAM INI\n");
    printf("1. REGISTER   : Melakukan pendaftaran akun baru\n");
    printf("2. LOGIN      : Masuk ke dalam akun dan memulai sesi\n");
    printf("3. QUIT       : Keluar dari program\n");
}

void main_menu(){
    printf("\n======================================[ Menu Help PURRMART ]====================================\n");
    printf("==================================================================================================\n");
    printf("\nGUNAKAN COMMAND BERIKUT UNTUK BERINTERAKSI DENGAN PROGRAM INI\n");
    printf("1. WORK             : Bekerja\n");
    printf("2. WORK CHALLENGE   : Mengerjakan challenge\n");
    printf("3. STORE LIST       : Melihat barang-barang di toko\n");
    printf("4. STORE REQUEST    : Meminta penambahan barang\n");
    printf("5. STORE SUPPLY     : Menambah barang dari permintaan\n");
    printf("6. STORE REMOVE     : Menghapus barang\n");
    printf("7. LOGOUT           : Keluar dari sesi\n");
    printf("8. SAVE             : Menyimpan state ke dalam file\n");
    printf("9. QUIT             : Keluar dari program\n");
}
