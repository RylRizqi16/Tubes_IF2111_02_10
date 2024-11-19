#include <stdio.h>
#include "backup_mesinkarakter.h"

char currentChar;
boolean EOP;

void START() {
    fscanf(stdin, "%c", &currentChar);
    if (currentChar == MARK) {
        EOP = true;
    } else {
        EOP = false;
    }
}

void ADV() {
    if (currentChar != MARK) {
        fscanf(stdin, "%c", &currentChar);
        if (currentChar == MARK) {
            EOP = true;
        }
    }
}

char GetCC() {
    return currentChar;
}

boolean IsEOP() {
    return (currentChar == MARK);
}