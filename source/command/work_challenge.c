#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include"../ADT/Mesin_Kata/mesinkata.h"

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
    char word[80][6] = {"abadi","abang","abjad","absah","absen","acara","acung","adisi","afiks","agama","agami","agung","ajaib","ajang","akbar","akhir",
                    "akmal","akrab","aksen","aksep","akses","aksis","aktif","aktor","alami","alarm","album","alias","alibi","altar","ambil","ambur",
                    "amino","amorf","ampas","ampuh","ampun","amsal","amuba","ancam","ancol","andai","andal","andil","aneka","angan","angga","angin",
                    "angka","angsa","anion","anjak","anode","antar","antek","antik","antre","antri","antuk","anual","anyam","anyir","aorta","apati",
                    "april","apron","apung","arang","arbab","areal","arena","argon","aries","aroma","arsip","arsir","artis","arung","arwah","asasi"};
    int a = rng() % 80;
    char random_word[6];
    for(int i=0;i<5;i++){
        random_word[i] = word[a][i];
    }
    printf("Selamat datang di WORDL3!!!");
    printf("Anda mempunyai 5 kesempatan untuk menebak kata berikut!");
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
            printf("\nSayang sekali, sepertinya anda belum berhasil. ;)");
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
        boolean check_char[5];
        boolean check_place[5];
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                if(currentWord.TabWord[j] == random_word[k]){
                    check_char[j] = true;
                    if(j == k){
                        check_place[j]=true;
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
        i--;
    }
    return prize;
}

int work_challenge(){
    while(1){
        printf("Daftar Challenge:\n");
        printf("1. Tebak Angka (biaya: 200)\n");
        printf("2. WORDL3 (biaya: 500)\n\n");
        printf("Masukkan challenge yang ingin dimainkan: ");
        STARTWORD("","");
        if(currentWord.Length == 1 & currentWord.TabWord[0] == '1'){
            return tebak_angka();
        }
        else{
            printf("Tidak ada masukkan yang cocok. Silahkan coba kembali.\n\n");
        }
    }   
}

int main(){
    work_challenge();
    return 0;
}