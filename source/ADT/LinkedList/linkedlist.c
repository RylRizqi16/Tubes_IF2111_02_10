#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

int IsEmpty(LinkedList L) {
    return (L == Nil);
}

void CreateEmpty(LinkedList *L) {
    *L = Nil;
}

Node* Alokasi(const char *X) {
    Node *P = (Node *)malloc(sizeof(Node));
    if (P != Nil) {
        int i = 0;
        while (X[i] != '\0' && i < MAX_LEN - 1) {
            P->Info[i] = X[i];
            i++;
        }
        P->Info[i] = '\0';
        P->Next = Nil;
    }
    return P;
}

void Dealokasi(Node **P) {
    free(*P);
    *P = Nil;
}

Node* Search(LinkedList L, const char *X) {
    Node *P = L;
    while (P != Nil) {
        if (BandingkanChar(P->Info, X)) return P;
        P = P->Next;
    }
    return Nil;
}

void InsVLast(LinkedList *L, const char *X) {
    Node *P = Alokasi(X);
    if (P != Nil) {
        if (IsEmpty(*L)) {
            *L = P;
        } else {
            Node *last = *L;
            while (last->Next != Nil) {
                last = last->Next;
            }
            last->Next = P;
        }
    }
}

void PrintInfo(LinkedList L) {
    Node *P = L;
    printf("[");
    while (P != Nil) {
        printf("%s", P->Info);
        P = P->Next;
        if (P != Nil) printf(",");
    }
    printf("]\n");
}

void DelIndex(LinkedList *L, int i) {
    if (IsEmpty(*L)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }

    int count = 0;
    Node *P = *L;
    Node *Prev = Nil;

    while (P != Nil) {
        count++;
        P = P->Next;
    }

    if (i <= 0 || i > count) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, Barang ke-%d tidak ada di WISHLIST!\n", i);
        return;
    }

    P = *L;
    for (int pos = 1; pos < i; pos++) {
        Prev = P;
        P = P->Next;
    }

    if (Prev == Nil) {
        *L = P->Next;
    } else {
        Prev->Next = P->Next;
    }

    printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n", i);
    Dealokasi(&P);
}


void DelP(LinkedList *L, const char *X) {
    Node *P = *L;
    Node *Prev = Nil;

    while (P != Nil && !BandingkanChar(P->Info, X)) {
        Prev = P;
        P = P->Next;
    }

    if (P != Nil) {
        if (Prev == Nil) {
            *L = P->Next;
        } else {
            Prev->Next = P->Next;
        }
        Dealokasi(&P);
    }
}

