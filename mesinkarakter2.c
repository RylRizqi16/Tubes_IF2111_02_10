#include <stdio.h>
#include "mesinkarakter2.h"

char currentChar;
boolean EOP;

void START() {
    // currentChar = getchar();
    // if (currentChar == MARK) {
    //     EOP = true;
    // } else {
    //     EOP = false;
    // }
    fscanf(stdin, "%c", &currentChar);
    if (currentChar == MARK) {
        EOP = true;
    } else {
        EOP = false;
    }
}

void ADV() {
    // if (currentChar != MARK) {
    //     currentChar = getchar();
    //     if (currentChar == MARK) {
    //         EOP = true;
    //     }
    // }
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