#include "mesinkata.h"

boolean EndWord;
Word currentWord;

void ClearCurrentWord()
{
    currentWord.TabWord[0] = '\0';
    currentWord.Length = 0;
}

// boolean IsEqual(Word str1, char *str2)
// {
//     int i = 0;
//     boolean checker = (str1.Length == stringLength(str2));
//     while (str1.TabWord[i] != '\0' && str2[i] != '\0' && checker)
//     {
//         if (str1.TabWord[i] != str2[i])
//             checker = false;
//         i++;
//     }
//     return checker;
// }

void ConcatWords(Word *str1, char separator, Word str2)
{
    int i = str1->Length, j; //temp = str1->Length;
    if (separator != '\0')
    {
        str1->TabWord[i] = separator;
        i++;
    }
    for (j = 0; j < str2.Length; j++)
    {
        str1->TabWord[i] = str2.TabWord[j];
        i++;
    }
    str1->TabWord[i] = '\0';
    str1->Length = i;
}

void IgnoreBlanks()
{
    while (GetCC() == BLANK)
        ADV();
}

void IgnoreLines()
{
    while (GetCC() == ENTER)
        ADV();
}

void STARTWORD(char *path, char *type)
{
    START(path, type);
    ADVWORD();
}

void STARTSENTENCE(char *path, char *type)
{
    START(path, type);
    ADVSENTENCE();
}

void ADVWORD()
{
    IgnoreBlanks();
    if (GetCC() == BLANK || GetCC() == MARK || GetCC() == ENTER)
        EndWord = true;
    else
    {
        EndWord = false;
        CopyWord();
    }
    IgnoreBlanks();
}

void ADVSENTENCE()
{
    IgnoreBlanks();
    if (GetCC() == BLANK || GetCC() == MARK)
        EndWord = true;
    else
    {
        EndWord = false;
        CopySentence();
    }
    IgnoreBlanks();
}

void CopySentence() {
    int i = 0;
    while ((currentChar != ENTER) && (currentChar != MARK&& i < NMax)) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;
}

void CopyWord()
{
    int i = 0;
    while (!IsEOP() && !EndWord)
    {
        currentWord.TabWord[i] = GetCC();
        ADV();
        if (GetCC() == BLANK || GetCC() == MARK || GetCC() == ENTER)
            EndWord = true;
        i++;
    }
    if (i < NMax)
        currentWord.Length = i;
    else
        currentWord.Length = NMax;
    currentWord.TabWord[i] = '\0';
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

int BandingkanChar(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return 0; 
        }
        str1++;
        str2++;
    }
    return (*str1 == '\0' && *str2 == '\0');
}