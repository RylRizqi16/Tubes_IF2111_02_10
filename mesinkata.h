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
extern Word CurrentWord;

extern void ClearCurrentWord();

extern void ConcatWords(Word *str1, char separator, Word str2);

extern void IgnoreBlanks();

extern void IgnoreLines();

extern void STARTWORD(char *path, char *type);

extern void ADVWORD();

extern void ADVLINE();

extern void CopyWord();

void WordToString(Word word, char* str);

int CharToInt(const char *str);


#endif