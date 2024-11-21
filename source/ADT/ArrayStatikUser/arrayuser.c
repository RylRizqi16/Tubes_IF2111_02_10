#include "arrayuser.h"

void CreateArrayUser(ArrayUser *AU){
    (*AU).Neff = 0;
}

// /* ********** SELEKTOR ********** */
// /* *** Banyaknya elemen *** */
// int NbElmt(TabGames T)
// /* Mengirimkan banyaknya elemen efektif tabel */
// /* Mengirimkan nol jika tabel kosong */
// {
//     return T.Neff;
// }

// /* *** Daya tampung container *** */
// int MaxNbEl(TabGames T)
// /* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
// /* *** Selektor INDEKS *** */
// {
//     return IdxMax - IdxMin + 1;
// }

// IdxType GetFirstIdx(TabGames T)
// /* Prekondisi : Tabel T tidak kosong */
// /* Mengirimkan indeks elemen pertama */
// {
//     return 1;
// }

// IdxType GetLastIdx(TabGames T)
// /* Prekondisi : Tabel T tidak kosong */
// /* Mengirimkan indeks elemen terakhir */
// /* *** Menghasilkan sebuah elemen *** */
// {
//     return T.Neff;
// }

// ElType GetElmt(TabGames T, IdxType i)
// /* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
// /* Mengirimkan elemen tabel yang ke-i */
// {
//     return T.TI[i];
// }
// /* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
// /* Untuk type private/limited private pada bahasa tertentu */
// void SetTab(TabGames Tin, TabGames *Tout)
// /* I.S. Tin terdefinisi, sembarang */
// /* F.S. Tout berisi salinan Tin */
// /* Assignment THsl -> Tin */
// {
//     (*Tout).Neff = Tin.Neff;
//     for (int i = IdxMin; i <= Tin.Neff; i++)
//     {
//         (*Tout).TI[i] = Tin.TI[i];
//     }
// }

// void SetEl(TabGames *T, IdxType i, ElType v)
// /* I.S. T terdefinisi, sembarang */
// /* F.S. Elemen T yang ke-i bernilai v */
// /* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
// {
//     (*T).TI[i].harga = v.harga;
//     (*T).TI[i].nama = v.nama;
//     (*T).TI[i].rating = v.rating;

//     if ((*T).Neff < i)
//     {
//         (*T).Neff = i;
//     }
// }

// void SetNeff(TabGames *T, IdxType N)
// /* I.S. T terdefinisi, sembarang */
// /* F.S. Nilai indeks efektif T bernilai N */
// /* Mengeset nilai indeks elemen efektif sehingga bernilai N */
// {
//     (*T).Neff = N;
// }

// /* ********** Test Indeks yang valid ********** */
// boolean IsIdxValid(TabGames T, IdxType i)
// /* Prekondisi : i sembarang */
// /* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
// /* yaitu antara indeks yang terdefinisi utk container*/
// {
//     if ((i >= IdxMin) && (i <= IdxMax))
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// boolean IsIdxEff(TabGames T, IdxType i)
// /* Prekondisi : i sembarang*/
// /* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
// /* yaitu antara FirstIdx(T)..LastIdx(T) */
// {
//     if ((i >= IdxMin) && (i <= T.Neff))
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
// /* ********** TEST KOSONG/PENUH ********** */
// /* *** Test tabel kosong *** */
// /* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
// boolean IsEmpty(TabGames T)
// {
//     if (T.Neff > 0)
//     {
//         return false;
//     }
//     else
//     {
//         return true;
//     }
// }

// /* *** Test tabel penuh *** */
// boolean IsFull(TabGames T)
// /* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
// {
//     if (T.Neff == IdxMax)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
// /* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
// void TulisIsi(TabGames T)
// /* Proses : Menuliskan isi tabel dengan traversal */
// /* I.S. T boleh kosong */
// /* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
// /* Contoh print tabel
// Test | 8 | 300000
// Ini Juga Test | 5 | 12000
// Test Lagi | 6 | 50000
// */
// /* Jika T kosong : Hanya menulis "Tabel kosong" */
// {
//     if (IsEmpty(T))
//     {
//         printf("Tabel kosong\n");
//     }
//     else
//     {
//         for (int i = IdxMin; i <= T.Neff; i++)
//         {
//             printf("%s | %d | %d\n", T.TI[i].nama, T.TI[i].rating, T.TI[i].harga);
//         }
//     }
// }

// /* ********** KONSTRUKTOR GAMES ********** */
// ElType MakeGame(char *Nama, int Rating, int Harga)
// /* Membentuk sebuah Game dari komponen-komponennya */
// /* I.S. Nama, Rating, Nilai terdefinisi */
// /* F.S. Game G terbentuk dengan Nama, Rating, Harga yang sesuai */
// {
//     ElType G;
//     G.nama = Nama;
//     G.rating = Rating;
//     G.harga = Harga;
//     return G;
// }

// /* ********** OPERATOR STATISTIK GAME ********** */
// float RataRataHarga(TabGames T)
// /* I.S. Tabel T tidak kosong */
// /* F.S. Menghasilkan rata-rata harga dari elemen tabel */
// {
//     int sum = 0;
//     for (int i = IdxMin; i <= T.Neff; i++)
//     {
//         sum += T.TI[i].harga;
//     }
//     return sum / T.Neff;
// }

// float RataRataRating(TabGames T)
// /* I.S. Tabel T tidak kosong */
// /* F.S. Menghasilkan rata-rata rating dari elemen tabel */
// {
//     int sum = 0;
//     for (int i = IdxMin; i <= T.Neff; i++)
//     {
//         sum += T.TI[i].rating;
//     }
//     return sum / T.Neff;
// }

// int MaxRating(TabGames T)
// /* I.S. Tabel T tidak kosong */
// /* F.S. Menghasilkan nilai rating maksimum dari elemen tabel */
// {
//     int max = T.TI[IdxMin].rating;
//     for (int i = IdxMin; i <= T.Neff; i++)
//     {
//         if (T.TI[i].rating > max)
//         {
//             max = T.TI[i].rating;
//         }
//     }
//     return max;
// }

// int MinRating(TabGames T)
// /* I.S. Tabel T tidak kosong */
// /* F.S. Menghasilkan nilai rating minimum dari elemen tabel */
// {
//     int min = T.TI[IdxMin].rating;
//     for (int i = IdxMin; i <= T.Neff; i++)
//     {
//         if (T.TI[i].rating < min)
//         {
//             min = T.TI[i].rating;
//         }
//     }
//     return min;
// }

// char *MaxHargaNama(TabGames T)
// /* I.S. Tabel T tidak kosong */
// /* F.S. Menghasilkan nama game dengan harga tertinggi */
// /* Jika ada lebih dari satu game dengan harga tertinggi, maka yang diambil yang memiliki rating lebih tinggi */
// {
//     int max = T.TI[IdxMin].harga;
//     int idx = IdxMin;
//     for (int i = IdxMin; i <= T.Neff; i++)
//     {
//         if (T.TI[i].harga > max)
//         {
//             max = T.TI[i].harga;
//             idx = i;
//         }
//         else if (T.TI[i].harga == max)
//         {
//             if (T.TI[i].rating > T.TI[idx].rating)
//             {
//                 idx = i;
//             }
//         }
//     }
//     return T.TI[idx].nama;
// }

// char *MinHargaNama(TabGames T)
// /* I.S. Tabel T tidak kosong */
// /* F.S. Menghasilkan nama game dengan harga tertinggi */
// /* Jika ada lebih dari satu game dengan harga terendah, maka yang diambil yang memiliki rating lebih tinggi */
// {
//     int min = T.TI[IdxMin].harga;
//     int idx = IdxMin;
//     for (int i = IdxMin; i <= T.Neff; i++)
//     {
//         if (T.TI[i].harga < min)
//         {
//             min = T.TI[i].harga;
//             idx = i;
//         }
//         else if (T.TI[i].harga == min)
//         {
//             if (T.TI[i].rating > T.TI[idx].rating)
//             {
//                 idx = i;
//             }
//         }
//     }
//     return T.TI[idx].nama;
// }

// int JumlahGamesRating(TabGames T, int R)
// /* I.S. Tabel T tidak kosong */
// /* F.S. Menghasilkan jumlah game yang memiliki rating R */
// /* Jika tidak ada game yang memiliki rating tersebut, maka menghasilkan 0 */
// {
//     int count = 0;
//     for (int i = IdxMin; i <= T.Neff; i++)
//     {
//         if (T.TI[i].rating == R)
//         {
//             count++;
//         }
//     }
//     return count;
// }