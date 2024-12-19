#include <stdio.h>
#include "history.h"

void History(Stack *history, int n) {
    if (IsEmpty(*history)) {
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
        printf("| Barang %d           | %11d |\n", history->T[i], history->T[i] * 100);
    }

    printf("+---------------------+-------------+\n");
}
