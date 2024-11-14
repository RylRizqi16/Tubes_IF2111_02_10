#include <stdio.h>
#include "list.h"

List MakeList() {
    List L;
    IdxType i;

    for (i = 0; i < MaxEl; i++) {
        L.A[i] = 0;
    }
    return L;
}

boolean IsEmpty(List L){
    return (Length(L) == 0);
}

ElType Get(List L, IdxType i){
    return L.A[i];
}       

void Set(List *L, IdxType i, ElType v){
    L->A[i] = v;
}

int Length(List L) {
    IdxType i;
    int count = 0;

    for (i = 0; i < MaxEl; i++) {
        if (L.A[i] != 0) { 
            count++;
        }
    }
    return count;
}


IdxType FirstIdx(List L){
    return 0;
}

IdxType LastIdx(List L){
    return Length(L) - 1;
}

boolean IsIdxValid (List L, IdxType i){
    return (i >= 0 && i < MaxEl);
}

boolean IsIdxEff (List L, IdxType i){
    return (i >= FirstIdx(L) && i <= LastIdx(L));
}

boolean Search(List L, ElType X){
    IdxType i;
    boolean found = false;

    for (i = 0; i < MaxEl; i++) {
        if (L.A[i] == X) {
            found = true;
            break;
        }
    }

    return found;
}

void InsertFirst(List *L, ElType X){
    IdxType i;

    for (i = LastIdx(*L); i >= FirstIdx(*L); i--) {
        L->A[i + 1] = L->A[i];
    }

    L->A[FirstIdx(*L)] = X;
}

void InsertAt(List *L, ElType X, IdxType i){
    IdxType j;

    for (j = LastIdx(*L); j >= i; j--) {
        L->A[j + 1] = L->A[j];
    }

    L->A[i] = X;
}

void InsertLast(List *L, ElType X) {
    L->A[LastIdx(*L) + 1] = X; 
}


void DeleteFirst(List *L){
    IdxType i;

    for (i = FirstIdx(*L); i < LastIdx(*L); i++) {
        L->A[i] = L->A[i + 1];
    }

    L->A[LastIdx(*L)] = 0;
}

void DeleteAt(List *L, IdxType i){
    IdxType j;

    for (j = i; j < LastIdx(*L); j++) {
        L->A[j] = L->A[j + 1];
    }

    L->A[LastIdx(*L)] = 0;
}

void DeleteLast(List *L){
    L->A[LastIdx(*L)] = 0;
}

List Concat(List L1, List L2){
    List L;
    IdxType i, j;

    L = MakeList();

    for (i = 0; i < MaxEl; i++) {
        if (L1.A[i] != 0) {
            InsertLast(&L, L1.A[i]);
        }
    }

    for (j = 0; j < MaxEl; j++) {
        if (L2.A[j] != 0) {
            InsertLast(&L, L2.A[j]);
        }
    }

    return L;
}
