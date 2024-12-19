#include "../ADT/Mesin_kata/mesinkata.h"
#include "../ADT/ArrayDinBarang/arraydinbarang.h"
#include "../ADT/SetMap/setmap.h"

int IdxKeranjang(Keranjang K, char *nama);

Barang nama_to_item(ArrayBarang *item_list, char *nama_barang);

void cart_add(Keranjang *cart, ArrayBarang *store, char *nama_barang, int quantity);

void cart_remove(Keranjang *cart, ArrayBarang *store, char *nama_barang, int quantity);

int print_cart(Keranjang cart);

void cart_show(Keranjang cart);

void cart_pay(Keranjang *cart, int *money, char *history);