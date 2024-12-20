
/* File: quit.h */
/* Deskripsi: Header file untuk fungsi QUIT */

#ifndef QUIT_H
#define QUIT_H

#include "save.h"

void quit(char *filename, ArrayBarang *barangToko, ArrayUser *users);
/* Fungsi quit */
/* Mengakhiri program PURRMART dengan opsi untuk menyimpan state program ke file save. */
/* I.S. : filename valid berisi nama file yang akan dituliskan,
           itemCount berisi jumlah barang,
           items berisi array barang yang valid,
           userCount berisi jumlah pengguna,
           users berisi array pengguna yang valid */
/* F.S. : Program dihentikan setelah melakukan penyimpanan (jika pengguna memilih untuk menyimpan). */

#endif