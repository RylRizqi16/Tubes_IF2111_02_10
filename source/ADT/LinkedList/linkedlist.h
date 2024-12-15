#include "../../header/boolean.h"
#include "../Barang/barang.h"
#include "../Mesin_Kata/mesinkata.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define Nil NULL
#define MAX_LEN 100

typedef struct Node {
    char Info[MAX_LEN];
    struct Node *Next;
} Node;

typedef Node* LinkedList;

int IsEmpty(LinkedList L);

void CreateEmpty(LinkedList *L);

Node* Alokasi(const char *X);

void Dealokasi(Node **P);

Node* Search(LinkedList L, const char *X);

void InsVLast(LinkedList *L, const char *X);

void PrintInfo(LinkedList L);

void DelIndex(LinkedList *L, int i);

void DelP(LinkedList *L, const char *X);

#endif
