#include "store.c"

int TerimaTolakTunda(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return 0; 
        }
        str1++;
        str2++;
    }
    return (*str1 == '\0' && *str2 == '\0');
}

void StoreSupply(QueueBarang *request){
    Barang currentBarang;
    dequeue(request,&currentBarang);
    printf("Apakah kamu ingin menambahkan barang ");
    int j = 0;
    while (currentBarang.nama[j] != '\0') {
        printf("%c", currentBarang.nama[j]);
        j++;
    }
    printf("? \n");
    printf("Ketik: Terima / Tunda / Tolak\n");
    printf("\n>>> ");
    STARTWORD();
    printf("\n");
    char perintah[MAX_LEN];
    WordToString(CurrentWord, perintah);
    if (TerimaTolakTunda("Terima",perintah)){
        printf("Masukkan harga barang: ");
        STARTWORD();
        char harga[MAX_LEN];
        WordToString(CurrentWord,harga);
        printf("\n");
        int j = 0;
        while (currentBarang.nama[j] != '\0') {
            printf("%c", currentBarang.nama[j]);
            j++;
        }
        printf(" dengan harga %d berhasil ditambahkan ke toko.\n" , CharToInt(harga));
    } else if (TerimaTolakTunda("Tunda",perintah)){
        enqueue (request,currentBarang);
        int j = 0;
        while (currentBarang.nama[j] != '\0') {
            printf("%c", currentBarang.nama[j]);
            j++;
        }
        printf(" dikembalikan ke antrian.\n");
    } else if (TerimaTolakTunda("Tolak",perintah)){
        int j = 0;
        while (currentBarang.nama[j] != '\0') {
            printf("%c", currentBarang.nama[j]);
            j++;
        }
        printf(" dihapus dari antrian.\n");
    }
}