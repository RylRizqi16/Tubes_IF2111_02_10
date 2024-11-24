/* File: load.h */
/* Deskripsi: Header file untuk fungsi LOAD */

#ifndef LOAD_H
#define LOAD_H

#include "../ADT/Mesin_Karakter/mesinkarakter.h"
#include "../ADT/Mesin_Kata/mesinkata.h"
#include "../ADT/ArrayDinBarang/arraydinbarang.h"
#include "../ADT/ArrayStatikUser/arrayuser.h"

void load(char *filename, ArrayBarang *barangToko, ArrayUser *users);
/* Fungsi load */
/* Membaca data dari file save yang diberikan, kemudian menginisialisasi */
/* jumlah barang, daftar barang, jumlah pengguna, dan daftar pengguna. */
/* I.S. : filename valid berisi nama file yang akan dibaca, */
/*        barangToko sembarang, users sembarang */
/* F.S. : barangToko berisi array barang yang telah diinisialisasi, */
/*        users berisi array pengguna yang telah diinisialisasi */

#endif