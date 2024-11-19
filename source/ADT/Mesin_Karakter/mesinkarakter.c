#include "mesinkarakter.h"

int retval;
char currentChar;
boolean isFile;

FILE *pita;
FILE *pitaFile;

void START(char *path, char *type)
{
    if (path[0] == '\0' && type[0] == '\0')
    {
        isFile = false;
        pita = stdin;
        ADV();
    }
    else
    {
        isFile = true;
        pitaFile = fopen(path, type);
        if (pitaFile != NULL)
            ADV();
    }
}

void ADV()
{
    retval = fscanf(isFile ? pitaFile : pita, "%c", &currentChar);
    if (IsEOP())
        fclose(isFile ? pitaFile : pita);
}

char GetCC()
{
    return currentChar;
}

boolean IsEOP()
{
    return retval == EOF;
}