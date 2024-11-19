/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "mesinkarakter.h"

#define NMax 50
#define BLANK ' '

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;

extern void ClearCurrentWord();

// extern boolean IsEqual(Word str1, char *str2);
// /* Mengecek apakah isi dari str1 = str2
//    I.S. : str1 tidak kosong (str1.TabWord ada dan str1.Length > 0);
//           str2 tidak kosong
//    F.S. : Mengembalikan true apabila isi dari str1.TabWord = str2 */

extern void ConcatWords(Word *str1, char separator, Word str2);
/* Menggabungkan isi dari str2 ke isi dari str1
   I.S. : str1 dan str2 tidak kosong (str1.TabWord dan str2.TabWord ada, serta str1.Length > 0 dan str2.Length > 0);
          separator bisa kosong ('\0')
   F.S. : str1.TabWord menjadi str1.TabWord yang digabungkan dengan str2.TabWord di akhir;
          Jika separator tidak kosong, maka antara str1.TabWord (yg lama) dan str2.TabWord akan dipisahkan oleh separator
*/

extern void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK */

extern void IgnoreLines();
/* Mengabaikan satu atau beberapa NEWLINE
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ NEWLINE */

extern void STARTWORD(char *path, char *type);
/* I.S. : currentChar sembarang
   F.S. : EndWord = true dan currentChar = MARK,
          atau EndWord = false dan currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

extern void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK/NEWLINE/EOF
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyWord */

extern void ADVLINE();
/* I.S. : currentChar adalah karakter pertama kalimat yang akan diakuisisi
   F.S. : currentWord adalah kalimat terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kalimat berikutnya, mungkin MARK/EOF
   Proses : Akuisisi kata menggunakan procedure CopyWord */

extern void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK atau currentChar = EOF;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void WordToString(Word word, char* str);
int CharToInt(const char *str);

#endif