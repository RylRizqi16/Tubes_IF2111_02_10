#include <stdio.h>
#include <stdlib.h>
#include "wishlist.h"

void WishlistAdd(ArrayBarang *store, LinkedList *wishlist) {
    printf("Masukkan nama barang: ");
    STARTSENTENCE("","");
    char namaBarang[MAX_LEN];
    WordToString(currentWord, namaBarang);
    if (BarangDiToko(store, namaBarang)) {
        if (Search(*wishlist, namaBarang) != Nil) {
            printf("%s sudah ada di wishlist!\n", namaBarang);
        } else {
            InsVLast(wishlist, namaBarang);
            printf("Berhasil menambahkan %s ke wishlist!\n", namaBarang);
        }
    } else {
        printf("Tidak ada barang dengan nama %s!\n", namaBarang);
    }
}

void WishlistSwap(LinkedList *L, int i, int j) {
    if (i == j) {
        printf("Indeks i dan j sama, tidak ada yang dipindah.\n");
        return;
    }
    if (i > j) {
        int temp = i;
        i = j;
        j = temp;
    }
    Node *prevI = Nil;
    Node *prevJ = Nil;
    Node *currI = *L;
    Node *currJ = *L;
    int idx = 1;
    while (currI != Nil && idx < i) {
        prevI = currI;
        currI = currI->Next;
        idx++;
    }
    idx = 1;
    while (currJ != Nil && idx < j) {
        prevJ = currJ;
        currJ = currJ->Next;
        idx++;
    }
    if (currI == Nil || currJ == Nil) {
        printf("Indeks i atau j tidak valid.\n");
        return;
    }
    if (prevI != Nil) {
        prevI->Next = currJ;
    } else {
        *L = currJ;
    }
    if (prevJ != Nil) {
        prevJ->Next = currI;
    } else {
        *L = currI;
    }
    Node *temp = currI->Next;
    currI->Next = currJ->Next;
    currJ->Next = temp;
    printf("Berhasil menukar %s dan %s di wishlist!\n", currI->Info, currJ->Info);
}

void WishlistRemoveIndex(LinkedList *wishlist, int i) {
    if (IsEmpty(*wishlist)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }
    int count = 0;
    Node *P = *wishlist;
    Node *Prev = Nil;
    while (P != Nil) {
        count++;
        P = P->Next;
    }
    if (i <= 0 || i > count) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, Barang ke-%d tidak ada di WISHLIST!\n", i);
        return;
    }
    P = *wishlist;
    for (int pos = 1; pos < i; pos++) {
        Prev = P;
        P = P->Next;
    }
    if (Prev == Nil) {
        *wishlist = P->Next;
    } else {
        Prev->Next = P->Next;
    }
    printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n", i);
    Dealokasi(&P);
}



void WishlistRemove(LinkedList *wishlist) {
    printf("Masukkan nama barang yang akan dihapus: ");
    STARTSENTENCE("", "");
    char namaBarang[MAX_LEN];
    WordToString(currentWord, namaBarang);

    if (Search(*wishlist, namaBarang) != Nil) {
        DelP(wishlist, namaBarang);
        printf("%s berhasil dihapus dari WISHLIST!\n", namaBarang);
    } else {
        printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n", namaBarang);
    }
}


int main(){
    ArrayBarang store = CreateArrayBarang();
    Barang ayam = createBarang("ayam", 10000);
    addBarang(&store, ayam);
    Barang bebek = createBarang("bebek", 20000);
    addBarang(&store, bebek);
    Barang cacing = createBarang("cacing", 30000);
    addBarang(&store, cacing);
    Barang domba = createBarang("domba", 40000);
    addBarang(&store, domba);
    Barang elang = createBarang("elang", 50000);
    addBarang(&store, elang);
    LinkedList wishlist;
    CreateEmpty(&wishlist);
    WishlistAdd(&store, &wishlist);
    WishlistAdd(&store, &wishlist);
    WishlistAdd(&store, &wishlist);
    WishlistAdd(&store, &wishlist);
    PrintInfo(wishlist);
    WishlistRemoveIndex(&wishlist, 5);
    PrintInfo(wishlist);
    return 0;
}