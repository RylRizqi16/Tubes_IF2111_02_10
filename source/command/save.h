/* File: save.h */
/* Deskripsi: Header file untuk fungsi SAVE */

#ifndef SAVE_H
#define SAVE_H

#include "../ADT/Mesin_Karakter/mesinkarakter.h"
#include "../ADT/Mesin_Kata/mesinkata.h"
#include "../ADT/ArrayDinBarang/arraydinbarang.h"
#include "../ADT/ArrayStatikUser/arrayuser.h"

void save(char *filename, ArrayBarang *barangToko, ArrayUser *users);
/* Fungsi save */
/* Menyimpan data state program ke dalam file save yang diberikan. */
/* I.S. : filename valid berisi nama file yang akan dituliskan, */
/*        barangToko berisi array barang yang valid, */
/*        users berisi array pengguna yang valid */
/* F.S. : File save berhasil ditulis dengan format: */
/*        - barangToko->Neff */
/*        - Daftar barang (harga dan nama) */
/*        - users->Neff */
/*        - Daftar pengguna (saldo, username, password) */

#endif
