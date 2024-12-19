#include "cart.h"

int IdxKeranjang(Keranjang cart, char *nama_barang)
{
    int idx = 0, i = 0;  
    while (idx < cart.Count) {
        while ((cart.Item[idx].Elements.nama[i]!='\0')&&(nama_barang[i]!='\0'))
        {
            if (cart.Item[idx].Elements.nama[i]!=nama_barang[i])
            {
                i = 0;
                break;
            }
            i++;
        }
        if (i == 0)
        {
            idx++;
        }
        else{
            break;
        }
    }
    if (i > 0)
    {
        return idx;
    }
    return -1;
}

Barang nama_to_item(ArrayBarang *item_list, char *nama_barang){
    int currentIdx = 0;
    for (int i = 0; i < item_list->Neff; i++) {
        int j = 0;
        boolean same = true;
        while (item_list->data[currentIdx].nama[j] != '\0' && nama_barang[j] != '\0') {
            if (item_list->data[currentIdx].nama[j] != nama_barang[j]) {
                same = false;
                break;
            }
            j++;
        }
        if (item_list->data[currentIdx].nama[j] != nama_barang[j]) {
            same = false;
        }
        if (same) {
            return *item_list->data;
        }
        currentIdx +=1;
    }
}

void cart_add(Keranjang *cart, ArrayBarang *store, char *nama_barang, int quantity){
    if (BarangDiToko(store, nama_barang))
    {   
        Barang item = nama_to_item(store, nama_barang);
        int idx = IdxKeranjang(*cart, nama_barang);
        if (idx > -1){
            cart->Item[idx].JumlahElement += quantity;
        }
        else{
            cart->Item[cart->Count].Elements = item;
            cart->Item[cart->Count].JumlahElement = quantity;
            cart->Count++;
        }
        printf("Berhasil menambahkan %d %s ke kerangjang belanja!\n", quantity, item.nama);
        return;
    }
    printf("Barang tidak ada di toko!\n");
}

void cart_remove(Keranjang *cart, ArrayBarang *store, char *nama_barang, int quantity){
    if (BarangDiToko(store, nama_barang))
    {
        Barang item = nama_to_item(store, nama_barang);
        int idx = IdxKeranjang(*cart, nama_barang);
        if (idx > -1){
            if (quantity > cart->Item[idx].JumlahElement)
            {
                printf("Tidak berhasil mengurangi, hanya terdapat %d %s pada keranjang!\n", cart->Item[idx].JumlahElement, item.nama);
                return;
            }
            else if (quantity < cart->Item[idx].JumlahElement)
            {
                cart->Item[idx].JumlahElement -= quantity;
            }
            else{
                if (cart->Count == 1)
                {
                    cart->Count = 0;
                }
                else{
                    for(idx; idx < cart->Count - 1; idx++){
                    cart->Item[idx].Elements = cart->Item[idx + 1].Elements;
                    cart->Item[idx].JumlahElement = cart->Item[idx + 1].JumlahElement;
                    cart->Count--;
                    }
                }
            }
            printf("Berhasil mengurangi %d %s dari kerangjang belanja!\n", quantity, item.nama);
            return;
        }
    }
    printf("Barang tidak ada di keranjang belanja!\n");
}

int print_cart(Keranjang cart){
    char headers[][10] = {"Kuantitas", "Nama", "Total"};
    printf("%-*s %-*s %-*s\n", 
        10, headers[0],
        10, headers[1],
        10, headers[2]);
        int total_harga = 0;
    for(int i = 0; i < cart.Count; i++){
        int total = cart.Item[i].Elements.harga * cart.Item[i].JumlahElement;
        total_harga += total;
        printf("%-*d %-*s %-*d\n", 
            10, cart.Item[i].JumlahElement,
            10, cart.Item[i].Elements,
            10, total);
    }
    printf("Total biaya yang harus dikeluarkan adalah %d", total_harga);
    return total_harga;
}

void cart_show(Keranjang cart){
    if(cart.Count == 0){
        printf("Keranjang kamu kosong!\n");
        return;
    }
    printf("Berikut adalah isi keranjangmu.\n");
    int total_harga = print_cart(cart);
    printf(".\n");
}

void pay_history(Keranjang cart, char *history){
    int price = cart.Item[0].Elements.harga * cart.Item[0].JumlahElement;
    char item[11];
    int i = 0;
    int j = 0;
    while (cart.Item[i].Elements.nama[j] != '\0')
    {
        item[j] = cart.Item[i].Elements.nama[j];
        j++;
    }
    item[j] = '\0';
    while (i < cart.Count)
    {
        int current_price = cart.Item[i].Elements.harga * cart.Item[i].JumlahElement;
        if (price < current_price)
        {
            price = current_price;
            j = 0;
            while (cart.Item[i].Elements.nama[j] != '\0')
            {
                item[j] = cart.Item[i].Elements.nama[j];
                j++;
            }
            item[j] = '\0';
        }
        i++;
    }
    i = 0;
    while (item[i] != '\0')
    {
        history[i] = item[i];
        i++;
    }
    history[i] = ' ';
    i++;
    char str[10];
    sprintf(str, "%d", price);
    j = 0;
    while (str[j] != '\0')
    {
        history[i] = str[j];
        i++;
        j++;
    }
    history[i] = '\0';
}

void cart_pay(Keranjang *cart, int *money, char *history){
    if (cart->Count == 0)
    {
        printf("Kerangjang kamu kosong!\n");
    }
    printf("Kamu akan membeli barang berikut.\n");
    int total_harga = print_cart(*cart);
    printf(", apakah jadi dibeli?\n(Ya/Tidak): ");
    STARTWORD("","");
    if (currentWord.TabWord[0] == 'Y' || currentWord.TabWord[0] == 'y')
    {
        if (currentWord.TabWord[1] == 'a')
        {
            if (*money < total_harga)
            {
                printf("Uang kamu hanya %d, tidak cukup untuk membeli keranjang!\n",*money);
                return;
            }
            *money -= total_harga;
            cart->Count = Nil;
            printf("Selamat kamu telah membeli barang-barang tersebut.\n");
            pay_history(*cart, history);
        }
    }    
}