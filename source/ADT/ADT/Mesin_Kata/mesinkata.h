/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../Mesin_Karakter/mesinkarakter.h"

#define NMax 50
#define BLANK ' '

typedef struct
{
   char TabWord[NMax];
   int Length;
} Word;

extern boolean EndWord;
extern Word currentWord;

extern void ClearCurrentWord();

extern void ConcatWords(Word *str1, char separator, Word str2);

extern void IgnoreBlanks();

extern void IgnoreLines();

extern void STARTSENTENCE(char *path, char *type);

extern void STARTWORD(char *path, char *type);

extern void ADVSENTENCE();

extern void ADVWORD();

extern void CopyWord();

extern void CopySentence();

void WordToString(Word word, char* str);

int CharToInt(const char *str);

int BandingkanChar(const char *str1, const char *str2);

#endif