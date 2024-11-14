#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;
static FILE *pita;
static int retval;

void START() {
    /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca dari stdin */
    /* Algoritma */
    pita = stdin;
    ADV();
}

void ADV() {
    /* Pita dimajukan satu karakter. Jika karakter yang dibaca adalah MARK, pita ditutup */
    /* Algoritma */
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK);
    if (EOP) {
        fclose(pita);
    }
}

char GetCC() {
    /* Mengirimkan currentChar */
    /* Algoritma */
    return currentChar;
}

boolean IsEOP() {
    /* Mengirimkan true jika currentChar = MARK */
    /* Algoritma */
    return EOP;
}

