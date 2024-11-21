#include "work_challenge.h"

int rng(){
    srand(time(NULL));
    int random_number = rand();
    return random_number;
}

int tebak_angka(){
    int random_number = rng() % 100;
    int i = 10, prize = 500;
    printf("%d\n", random_number);
    while(1){
        printf("%d\n", random_number);
        int a=1;
        if(i == 0){
            printf("Maaf, kamu sepertinya sedang tidak beruntung.\n");
            break;
        }
        else{
            int guess=0;
            printf("\nTebak Angka: ");
            STARTWORD("","");
            for(int j=0;j<currentWord.Length;j++){
                if(currentWord.TabWord[j]<48 && currentWord.TabWord[j]>57){
                    printf("Sepertinya ada kesalahan dalam masukkanmu.\n");
                    printf("Silahkan ulangi masukkanmu.\n");
                    a=0;
                    break;
                }
                else{
                    a=1;
                }
            }
            char b;
            WordToString(currentWord,&b);
            guess=CharToInt(&b);
            if(guess>random_number){
                printf("Tebakanmu lebih besar!\n");
            }
            else if(guess<random_number){
                printf("Tebakanmu lebih kecil!\n");
            }
            else{
                printf("Selamat tebakanmu benar!\n");
                printf("%d rupiah telah ditambahkan ke akun anda.",prize);
                break;
            }
            if(a == 1){
                i--;
                prize-=50;
            }
        }
    }
    return prize;
}

int wordl3(){
    int prize = 1500;
    char word[240][6] = {"abadi","abang","abjad","absah","absen","acara","acung","adisi","afiks","agama","agami","agung","ajaib","ajang","akbar","akhir",
                        "akmal","akrab","aksen","aksep","akses","aksis","aktif","aktor","alami","alarm","album","alias","alibi","altar","ambil","ambur",
                        "amino","amorf","ampas","ampuh","ampun","amsal","amuba","ancam","ancol","andai","andal","andil","aneka","angan","angga","angin",
                        "angka","angsa","anion","anjak","anode","antar","antek","antik","antre","antri","antuk","anual","anyam","anyir","aorta","apati",
                        "april","apron","apung","arang","arbab","areal","arena","argon","aries","aroma","arsip","arsir","artis","arung","arwah","asasi",
                        "asbak","asbes","asing","aspal","aspek","aster","asyik","ateis","atlas","atlet","audio","aurat","avtur","babak","babat","babon",
                        "babun","bacem","bacok","bacot","badai","badak","badan","badui","badut","bagai","bagan","bagus","bahan","bahas","bahwa","bajaj",
                        "bajak","bakal","bakar","bakat","bakau","bakmi","bakso","bakti","bakul","balad","balet","balig","balik","balok","balon","balut",
                        "bambu","banci","bando","bantu","bapak","barak","barat","barel","baret","baris","baron","basah","basil","basis","basmi","basuh",
                        "batas","batik","batin","batok","batuk","bawah","bawel","bayam","bayar","bayam","bazar","bebal","beban","bebas","bebek","beber",
                        "becak","becek","becus","bedah","bedak","beduk","begah","begal","bejat","bekal","bekas","belah","belai","belas","belek","belia",
                        "belok","belot","beluk","belum","belut","benah","benak","benam","benar","benci","benda","benih","benua","berai","berak","beras",
                        "berat","beres","besar","beset","besit","besok","besuk","betah","betis","beton","betul","biang","biara","biasa","biaya","bibir",
                        "bibit","bidah","bidak","bidan","bidet","bidik","biduk","bihun","bijak","bijih","bikin","biksu","bilah","bilas","bilik","bilur",
                        "binal","binar","biner","biola","biota","birit","bisik","bison","bisul","blong","blues","bobol","bodoh","bogor","bokek","bolak"};
    int a = rng() % 240;
    char random_word[6];
    for(int j=0;j<5;j++){
        random_word[j] = word[a][j];
    }
    printf("\n\nSelamat datang di WORDL3!!!\n");
    printf("Anda mempunyai 5 kesempatan untuk menebak kata tersebunyi berikut!\n\n");
    int i = 5;
    for(int l=0;l<i;l++){
            for(int m=0;m<4;m++){
                printf("_ ");
            }
            printf("_\n");
        }
    char history[5][16];
    while(1){
        if(i == 0){
            printf("\nSayang sekali, sepertinya anda belum berhasil ;)\n");
            prize = 0;
            break;
        }
        printf("\nMasukkan kata tebakan Anda: ");
        STARTWORD("","");
        if(currentWord.Length != 5){
            printf("Tolong Masukkan sebuah kata berisi 5 huruf.\n");
            printf("Coba ulangi lagi :)\n");
            continue;
        }
        if(currentWord.TabWord[0] == random_word[0] || currentWord.TabWord[0]+32 == random_word[0]){
            if(currentWord.TabWord[1] == random_word[1] || currentWord.TabWord[1]+32 == random_word[1]){
                if(currentWord.TabWord[2] == random_word[2] || currentWord.TabWord[2]+32 == random_word[2]){
                    if(currentWord.TabWord[3] == random_word[3] || currentWord.TabWord[3]+32 == random_word[3]){
                        if(currentWord.TabWord[4] == random_word[4] || currentWord.TabWord[4]+32 == random_word[4]){
                            printf("\nSelamat, Anda berhasil menebak kata tersebunyi!!!\n");
                            printf("%d rupiah telah ditambahkan ke akun anda.\n\n",prize);
                            break;
                        }
                    }
                }
            }
        }
        boolean check_char[] = {false,false,false,false,false};
        boolean check_place[] = {false,false,false,false,false};
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                if(currentWord.TabWord[j] == random_word[k] || currentWord.TabWord[j]+32 == random_word[k]){
                    check_char[j] = true;
                    if(j == k){
                        check_place[j]=true;
                        break;
                    }
                }
            }
        }
        for(int j=0;j<5;j++){
            history[5-i][j*3] = currentWord.TabWord[j];
            if(check_char[j] == true){
                if(check_place[j] == true){
                    history[5-i][j*3 + 1] = ' ';
                }
                else{
                    history[5-i][j*3 + 1] = '*';
                }
            }
            else{
                history[5-i][j*3 + 1] = '%';
            }
            history[5-i][j*3 + 2] = ' ';
        }
        i--;
        printf("Hasil:\n");
        for(int j=5;j>i;j--){
            for(int k=0;k<15;k++){
                printf("%c",history[5-j][k]);
            }
            printf("\n");
        }
        for(int j=0;j<i;j++){
            for(int k=0;k<4;k++){
                printf("_ ");
            }
            printf("_\n");
        }
    }
    return prize;
}

void work_challenge(int *money){
    while(1){
        printf("Daftar Challenge:\n");
        printf("1. Tebak Angka (biaya: 200)\n");
        printf("2. WORDL3 (biaya: 500)\n\n");
        printf("Masukkan challenge yang ingin dimainkan: ");
        STARTWORD("","");
        if(currentWord.Length == 1 && currentWord.TabWord[0] == '1'){
            *money += tebak_angka() - 200;
            break;
        }
        else if(currentWord.Length == 1 && currentWord.TabWord[0] == '2'){
            *money += wordl3() - 500;
            break;
        }
        else{
            printf("\nTidak ada masukkan yang cocok. Silahkan coba kembali.\n\n");
        }
    }   
}

/*int main(){
    int money=1000;
    work_challenge(&money);
    printf("%d",money);
    return 0;
}*/