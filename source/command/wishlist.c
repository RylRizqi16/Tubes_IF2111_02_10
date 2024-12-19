#include <stdio.h>
#include <stdlib.h>
#include "wishlist.h"

void WishlistAdd(ArrayBarang *store, LinkedList *wishlist) {
    printf("Masukkan nama barang: ");
    STARTSENTENCE("","");
    char namaBarang[MAX_LEN];
    WordToString(currentWord, namaBarang);
    if (BarangDiToko(store, namaBarang)) {
        if (Search(*wishlist, namaBarang) != NULL) {
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
    Node *prevI = NULL;
    Node *prevJ = NULL;
    Node *currI = *L;
    Node *currJ = *L;
    int idx = 1;
    while (currI != NULL && idx < i) {
        prevI = currI;
        currI = currI->Next;
        idx++;
    }
    idx = 1;
    while (currJ != NULL && idx < j) {
        prevJ = currJ;
        currJ = currJ->Next;
        idx++;
    }
    if (currI == NULL || currJ == NULL) {
        printf("Indeks i atau j tidak valid.\n");
        return;
    }
    if (prevI != NULL) {
        prevI->Next = currJ;
    } else {
        *L = currJ;
    }
    if (prevJ != NULL) {
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
    if (IsEmptyLinkedList(*wishlist)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }
    int count = 0;
    Node *P = *wishlist;
    Node *Prev = NULL;
    while (P != NULL) {
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
    if (Prev == NULL) {
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

    if (Search(*wishlist, namaBarang) != NULL) {
        DelP(wishlist, namaBarang);
        printf("%s berhasil dihapus dari WISHLIST!\n", namaBarang);
    } else {
        printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n", namaBarang);
    }
}

void WishlistClear (LinkedList *wishlist) {
    CreateEmptyLinkedList(wishlist);
    printf("Wishlist telah dikosongkan.\n");
}

void WishlistShow(LinkedList *wishlist) {
    if (IsEmptyLinkedList(*wishlist)) {
        printf("Wishlist kamu kosong, tambahin dong!\n");
        return;
    } else {
        Node *P = *wishlist;
        int i = 1;
        printf("Berikut adalah isi wishlist-mu:\n");
        while (P != NULL) {
            printf("%d. %s\n", i, P->Info);
            P = P->Next;
            i++;
        }
    }
    
}

// int main(){
//     ArrayBarang store = CreateArrayBarang();
//     Barang ayam = createBarang("ayam", 10000);
//     addBarang(&store, ayam);
//     Barang bebek = createBarang("bebek", 20000);
//     addBarang(&store, bebek);
//     Barang cacing = createBarang("cacing", 30000);
//     addBarang(&store, cacing);
//     Barang domba = createBarang("domba", 40000);
//     addBarang(&store, domba);
//     Barang elang = createBarang("elang", 50000);
//     addBarang(&store, elang);
//     LinkedList wishlist;
//     CreateEmptyLinkedList(&wishlist);
//     WishlistAdd(&store, &wishlist);
//     WishlistAdd(&store, &wishlist);
//     WishlistAdd(&store, &wishlist);
//     WishlistShow(&wishlist);
//     WishlistSwap(&wishlist, 1, 3);
//     WishlistShow(&wishlist);
//     WishlistRemoveIndex(&wishlist, 2);
//     WishlistShow(&wishlist);
//     WishlistRemove(&wishlist);
//     WishlistShow(&wishlist);
//     WishlistClear(&wishlist);
//     WishlistShow(&wishlist);
//     return 0;
// }
