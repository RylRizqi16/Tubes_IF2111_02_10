#include "help.h"
#include "stdio.h"

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
    printf("7. CART ADD         : Menambahkan barang ke keranjang\n");
    printf("8. CART REMOVE      : Menghapus barang dari keranjang\n");
    printf("9. CART SHOW        : Menampilkan barang-barang di keranjang\n");
    printf("10. CART PAY        : Membayar barang-barang di keranjang\n");
    printf("11. WISHLIST ADD    : Menambahkan barang ke wishlist\n");
    printf("12. WISHLIST SWAP   : Menukar barang di wishlist\n");
    printf("13. WISHLIST REMOVE : Menghapus barang dari wishlist\n");
    printf("14. WISHLIST REMOVE INDEX : Menghapus barang dari wishlist berdasarkan indeks\n");
    printf("15. WISHLIST CLEAR  : Menghapus semua barang dari wishlist\n");
    printf("16. WISHLIST SHOW   : Menampilkan barang-barang di wishlist\n");
    printf("17. PROFILE         : Melihat profil pengguna\n");
    printf("18. LOGOUT          : Keluar dari sesi\n");
    printf("19. SAVE            : Menyimpan state ke dalam file\n");
    printf("20. QUIT            : Keluar dari program\n");
    printf("21. HELP            : Menampilkan bantuan\n");
}
