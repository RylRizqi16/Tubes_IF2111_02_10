#include "../../header/boolean.h"
#include "../User/user.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef ARRAYUSER_H
#define ARRAYUSER_H

#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999

typedef struct {
  char name[MAX_LEN];
  char password[MAX_LEN];
  int money;
} User;

typedef struct
{
    User user[IdxMax - IdxMin + 1];
    int Neff;
} ArrayUser;




void CreateArrayUser(ArrayUser *AU);

// int NbElmt(ArrayUser T);
// /* Mengirimkan banyaknya elemen efektif tabel */
// /* Mengirimkan nol jika tabel kosong */

// /* *** Daya tampung container *** */
// int MaxNbEl(ArrayUser T);
// /* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
// /* *** Selektor INDEKS *** */

// IdxType GetFirstIdx(ArrayUser T);
// /* Prekondisi : Tabel T tidak kosong */
// /* Mengirimkan indeks elemen pertama */

// IdxType GetLastIdx(ArrayUser T);
// /* Prekondisi : Tabel T tidak kosong */
// /* Mengirimkan indeks elemen terakhir */
// /* *** Menghasilkan sebuah elemen *** */

// ElType GetElmt(ArrayUser T, IdxType i);
// /* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
// /* Mengirimkan elemen tabel yang ke-i */

// /* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
// /* Untuk type private/limited private pada bahasa tertentu */
// void SetTab(ArrayUser Tin, ArrayUser *Tout);
// /* I.S. Tin terdefinisi, sembarang */
// /* F.S. Tout berisi salinan Tin */
// /* Assignment THsl -> Tin */

// void SetEl(ArrayUser *T, IdxType i, ElType v);
// /* I.S. T terdefinisi, sembarang */
// /* F.S. Elemen T yang ke-i bernilai v */
// /* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */

// void SetNeff(ArrayUser *T, IdxType N);
// /* I.S. T terdefinisi, sembarang */
// /* F.S. Nilai indeks efektif T bernilai N */
// /* Mengeset nilai indeks elemen efektif sehingga bernilai N */

// /* ********** Test Indeks yang valid ********** */
// boolean IsIdxValid(ArrayUser T, IdxType i);
// /* Prekondisi : i sembarang */
// /* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
// /* yaitu antara indeks yang terdefinisi utk container*/

// boolean IsIdxEff(ArrayUser T, IdxType i);
// /* Prekondisi : i sembarang*/
// /* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
// /* yaitu antara FirstIdx(T)..LastIdx(T) */

// /* ********** TEST KOSONG/PENUH ********** */
// /* *** Test tabel kosong *** */
// boolean IsEmpty(ArrayUser T);
// /* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */

// /* *** Test tabel penuh *** */
// boolean IsFull(ArrayUser T);
// /* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

// /* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
// void TulisIsi(ArrayUser T);
// /* Proses : Menuliskan isi tabel dengan traversal */
// /* I.S. T boleh kosong */
// /* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
// /* Contoh print tabel
// Test | 8 | 300000
// Ini Juga Test | 5 | 12000
// Test Lagi | 6 | 50000
// */
// /* Jika T kosong : Hanya menulis "Tabel kosong" */

// /* ********** KONSTRUKTOR GAMES ********** */
// ElType MakeGame(char *Nama, int Rating, int Harga);
// /* Membentuk sebuah Game dari komponen-komponennya */
// /* I.S. Nama, Rating, Nilai terdefinisi */
// /* F.S. Game G terbentuk dengan Nama, Rating, Harga yang sesuai */

// /* ********** OPERATOR STATISTIK GAME ********** */
// float RataRataHarga(ArrayUser T);
// /* I.S. Tabel T tidak kosong */
// /* F.S. Menghasilkan rata-rata harga dari elemen tabel */

// float RataRataRating(ArrayUser T);
// /* I.S. Tabel T tidak kosong */
// /* F.S. Menghasilkan rata-rata rating dari elemen tabel */

// int MaxRating(ArrayUser T);
// /* I.S. Tabel T tidak kosong */
// /* F.S. Menghasilkan nilai rating maksimum dari elemen tabel */

// int MinRating(ArrayUser T);
// /* I.S. Tabel T tidak kosong */
// /* F.S. Menghasilkan nilai rating minimum dari elemen tabel */

// char *MaxHargaNama(ArrayUser T);
// /* I.S. Tabel T tidak kosong */
// /* F.S. Menghasilkan nama game dengan harga tertinggi */
// /* Jika ada lebih dari satu game dengan harga tertinggi, maka yang diambil yang memiliki rating lebih tinggi */

// char *MinHargaNama(ArrayUser T);
// /* I.S. Tabel T tidak kosong */
// /* F.S. Menghasilkan nama game dengan harga tertinggi */
// /* Jika ada lebih dari satu game dengan harga terendah, maka yang diambil yang memiliki rating lebih tinggi */

// int JumlahGamesRating(ArrayUser T, int R);
// /* I.S. Tabel T tidak kosong */
// /* F.S. Menghasilkan jumlah game yang memiliki rating R */
// /* Jika tidak ada game yang memiliki rating tersebut, maka menghasilkan 0 */

#endif