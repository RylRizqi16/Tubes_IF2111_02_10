#include <stdio.h>
#include "history.h"

void History(Stack *history, int n) {
    if (IsEmptyStack(*history)) {
        printf("Kamu belum membeli barang apapun!\n");
        return;
    }

    printf("Riwayat Pembelian:\n");
    printf("+---------------------+-------------+\n");
    printf("|  Nama Barang        | Total Harga |\n");
    printf("+---------------------+-------------+\n");

    int start = Top(*history) - n + 1;
    if (start < 0) start = 0;

    for (int i = Top(*history); i >= start; i--) {
        printf("| %-20s | %11d |\n", history->T[i].name, history->T[i].TotalHarga);
    }

    printf("+---------------------+-------------+\n");
}