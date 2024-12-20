#include "cart.h"

int IdxKeranjang(Keranjang cart, char *nama_barang) {
    int idx = 0, i = 0;  
    while (idx < cart.Count) {
        while (cart.Item[idx].Elements.nama[i] != '\0' && nama_barang[i] != '\0') {
            if (cart.Item[idx].Elements.nama[i] != nama_barang[i]) {
                i = 0; 
                break;
            }
            i++;
        }
        if (i == 0) {
            idx++;
        } else {
            break;
        }
    }
    if (i > 0) {
        return idx;
    }
    return -1;
}

Barang nama_to_item(ArrayBarang *item_list, char *nama_barang) {
    for (int i = 0; i < item_list->Neff; i++) {
        int j = 0;
        int same = 1; 
        while (item_list->data[i].nama[j] != '\0' && nama_barang[j] != '\0') {
            if (item_list->data[i].nama[j] != nama_barang[j]) {
                same = 0;
                break;
            }
            j++;
        }
        if (item_list->data[i].nama[j] != nama_barang[j]) {
            same = 0;
        }
        if (same) {
            return item_list->data[i];
        }
    }
    printf("Error: Barang tidak ditemukan!\n");
    Barang empty = {0};
    return empty;
}

void cart_add(Keranjang *cart, ArrayBarang *store, char *nama_barang, int quantity) {
    if (BarangDiToko(store, nama_barang)) {   
        Barang item = nama_to_item(store, nama_barang);
        int idx = IdxKeranjang(*cart, nama_barang);
        if (idx > -1) {
            cart->Item[idx].JumlahElement += quantity;
        } else {
            cart->Item[cart->Count].Elements = item;
            cart->Item[cart->Count].JumlahElement = quantity;
            cart->Count++;
        }
        printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", quantity, item.nama);
    } else {
        printf("Barang tidak ada di toko!\n");
    }
}

void cart_remove(Keranjang *cart, ArrayBarang *store, char *nama_barang, int quantity) {
    int idx = IdxKeranjang(*cart, nama_barang);
    if (idx > -1) {
        if (quantity > cart->Item[idx].JumlahElement) {
            printf("Tidak berhasil mengurangi, hanya terdapat %d %s pada keranjang!\n", cart->Item[idx].JumlahElement, cart->Item[idx].Elements.nama);
        } else if (quantity < cart->Item[idx].JumlahElement) {
            cart->Item[idx].JumlahElement -= quantity;
        } else {
            for (int i = idx; i < cart->Count - 1; i++) {
                cart->Item[i] = cart->Item[i + 1];
            }
            cart->Count--;
        }
        printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", quantity, cart->Item[idx].Elements.nama);
    } else {
        printf("Barang tidak ada di keranjang belanja!\n");
    }
}

int print_cart(Keranjang cart) {
    printf("%-10s %-10s %-10s\n", "Kuantitas", "Nama", "Total");
    int total_harga = 0;
    for (int i = 0; i < cart.Count; i++) {
        int total = cart.Item[i].Elements.harga * cart.Item[i].JumlahElement;
        total_harga += total;
        printf("%-10d %-10s %-10d\n", cart.Item[i].JumlahElement, cart.Item[i].Elements.nama, total);
    }
    printf("Total biaya yang harus dikeluarkan adalah %d\n", total_harga);
    return total_harga;
}

void cart_show(Keranjang cart) {
    if (cart.Count == 0) {
        printf("Keranjang kamu kosong!\n");
    } else {
        printf("Berikut adalah isi keranjangmu.\n");
        print_cart(cart);
    }
}

void pay_history(Keranjang cart, char *history) {
    if (cart.Count == 0) {
        history[0] = '\0'; 
        return;
    }
    int max_price = 0;
    char *expensive_item = cart.Item[0].Elements.nama;
    for (int i = 0; i < cart.Count; i++) {
        int current_price = cart.Item[i].Elements.harga * cart.Item[i].JumlahElement;
        if (current_price > max_price) {
            max_price = current_price;
            expensive_item = cart.Item[i].Elements.nama;
        }
    }
    sprintf(history, "%s %d", expensive_item, max_price);
}

void cart_pay(Keranjang *cart, int *money, char *history) {
    if (cart->Count == 0) {
        printf("Keranjang kamu kosong!\n");
        return;
    }
    printf("Kamu akan membeli barang berikut:\n");
    int total_harga = print_cart(*cart);
    printf("Apakah jadi dibeli? (Ya/Tidak): ");
    STARTWORD("", "");
    if (currentWord.TabWord[0] == 'Y' || currentWord.TabWord[0] == 'y') {
        if (currentWord.TabWord[1] == 'a') {
            if (*money < total_harga) {
                printf("Uang kamu hanya %d, tidak cukup untuk membeli keranjang!\n", *money);
                return;
            }
            *money -= total_harga;
            pay_history(*cart, history);
            cart->Count = 0;
            printf("Selamat kamu telah membeli barang-barang tersebut.\n");
        }
    }
}
