#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

int IsEmptyLinkedList(LinkedList L) {
    return (L == NULL);
}

void CreateEmptyLinkedList(LinkedList *L) {
    *L = NULL;
}

Node* Alokasi(const char *X) {
    Node *P = (Node *)malloc(sizeof(Node));
    if (P != NULL) {
        int i = 0;
        while (X[i] != '\0' && i < MAX_LEN - 1) {
            P->Info[i] = X[i];
            i++;
        }
        P->Info[i] = '\0';
        P->Next = NULL;
    }
    return P;
}

void Dealokasi(Node **P) {
    free(*P);
    *P = NULL;
}

Node* Search(LinkedList L, const char *X) {
    Node *P = L;
    while (P != NULL) {
        if (BandingkanChar(P->Info, X)) return P;
        P = P->Next;
    }
    return NULL;
}

void InsVLast(LinkedList *L, const char *X) {
    Node *P = Alokasi(X);
    if (P != NULL) {
        if (IsEmptyLinkedList(*L)) {
            *L = P;
        } else {
            Node *last = *L;
            while (last->Next != NULL) {
                last = last->Next;
            }
            last->Next = P;
        }
    }
}

void DelIndex(LinkedList *L, int i) {
    if (IsEmptyLinkedList(*L)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }

    int count = 0;
    Node *P = *L;
    Node *Prev = NULL;

    while (P != NULL) {
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

    if (Prev == NULL) {
        *L = P->Next;
    } else {
        Prev->Next = P->Next;
    }

    printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n", i);
    Dealokasi(&P);
}

void DelP(LinkedList *L, const char *X) {
    Node *P = *L;
    Node *Prev = NULL;

    while (P != NULL && !BandingkanChar(P->Info, X)) {
        Prev = P;
        P = P->Next;
    }

    if (P != NULL) {
        if (Prev == NULL) {
            *L = P->Next;
        } else {
            Prev->Next = P->Next;
        }
        Dealokasi(&P);
    }
}
