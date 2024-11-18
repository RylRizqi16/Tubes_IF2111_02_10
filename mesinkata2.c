#include <stdio.h>
#include "mesinkata2.h"

boolean EndWord;
Word CurrentWord;

void IgnoreBlanks() {
    while (currentChar == BLANK && !IsEOP()) {
        ADV();
    }
}

void STARTWORD() {

    START();
    IgnoreBlanks();
    if (IsEOP()) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD() {
    IgnoreBlanks();
    if (IsEOP()) {
        EndWord = true;
    } else {
        CopyWord();
        IgnoreBlanks();
    }
}

void ADVWORD2() {
    IgnoreBlanks();
    if (IsEOP()) {
        EndWord = true;
    } else {
        CopyWord2();
        IgnoreBlanks();
    }
}

void CopyWord() {
    int i = 0;
    while ((currentChar != ENTER) && (currentChar != MARK&& i < NMax)) {
        CurrentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    CurrentWord.Length = i;
}
void CopyWord2() {
    int i = 0;
    while ((currentChar != BLANK) && (currentChar != MARK&& i < NMax)) {
        CurrentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    CurrentWord.Length = i;
}

boolean IsWordEqual(Word word1, Word word2){
    if (word1.Length != word2.Length) {
        return false;
    }
    
    int i;
    for (i = 0; i < word1.Length; i++) {
        if (word1.TabWord[i] != word2.TabWord[i]) {
            return false;
        }
    }
    return true;
}


void WordToString(Word word, char* str){
    int i;
    for (i = 0; i < word.Length; i++) {
        str[i] = word.TabWord[i];
    }
    str[i] = '\0';
}

int CharToInt(const char *str) {
    int result = 0; 
    int negatif = 1;  
    int i = 0;
   
    if (str[0] == '-') {
        negatif = -1;
        i++; 
    }

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            printf("Error: Input bukan angka valid.\n");
            return 0;
        }
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result * negatif;
}