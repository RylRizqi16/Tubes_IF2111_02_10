#include "work_challenge.h"

int rng(){
    srand(time(NULL));
    int random_number = rand()*23;
    return random_number;
}

int tebak_angka(){
    int random_number = rng() % 100;
    int i = 10, prize = 500;
    while(1){
        if(i == 0){
            printf("Maaf, kamu sepertinya sedang tidak beruntung.\n");
            break;
        }
        else{
            int guess=0;
            printf("\nTebak Angka: ");
            STARTWORD("","");
            char b;
            WordToString(currentWord,&b);
            guess=CharToInt(&b);
            if(guess == 0){
                printf("Coba ulangi lagi :)\n");
                continue;
            }
            i--;
            prize-=50;
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
        }
    }
    return prize;
}

list rwg(){
    char word[400][6] = {"abadi","abang","abjad","absah","absen","acara","acung","adisi","afiks","agama","agami","agung","ajaib","ajang","akbar","akhir",
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
                        "binal","binar","biner","biola","biota","birit","bisik","bison","bisul","blong","blues","bobol","bodoh","bogor","bokek","bolak",
                        "boleh","bolos","bonus","borok","boros","bosan","botak","botol","bruto","buang","buaya","bubar","bubuh","bubuk","bubur","budak",
                        "budek","bufer","bufet","bugar","bugil","bujuk","bujur","bukan","bukau","buket","bukit","bukti","bulai","bulan","bulat","bulir",
                        "buluh","buluk","bulus","bumbu","bunda","bunga","buntu","bunuh","bunyi","buram","burik","burit","buron","bursa","buruh","buruk",
                        "buset","busuk","busur","butek","butik","butir","butuh","butut","buyar","buyur","buyut","cabai","cabik","cabir","cabul","cabut",
                        "cacah","cacar","cacat","cadar","cadas","cadel","cagar","cakap","cakar","cakep","cakra","cakup","calon","camar","camat","canai",
                        "canda","candi","candu","capai","capit","carik","catat","catur","cawan","ceban","cebok","cebol","cebur","cecah","cecak","cecer",
                        "cedok","cegah","ceguk","cekam","cekek","ceker","celah","celik","celup","cemar","cemas","cepak","capat","ceper","cerah","cerai",
                        "cerca","ceria","cerna","cetak","cetek","cewek","cibir","cicil","cicip","cicit","ciduk","cikal","cilik","cilok","cinta","cipok",
                        "cipta","citra","cobek","cocok","cocol","codet","colek","colok","comel","comot","copet","copot","corak","coret","cowok","cuaca",
                        "cubit","cucuk","cukai","cukup","cukur","culik","culun","cuman","cumbu","curah","dadar","dadih","dahak","dahan","dajal","dakar"};
    list selected_word;
    int idx = rng() % 400;
    for(int i=0;i<5;i++){
        selected_word.word[i]=word[idx][i];
    }
    return selected_word;
}

int wordl3(){
    int prize = 1500;
    list random_word = rwg();
    printf("\n\nSelamat datang di WORDL3!!!\n");
    printf("Anda mempunyai 6 kesempatan untuk menebak kata tersebunyi berikut!\n\n");
    int i = 6;
    for(int l=0;l<i;l++){
            for(int m=0;m<4;m++){
                printf("_ ");
            }
            printf("_\n");
        }
    char history[6][16];
    while(1){
        if(i == 0){
            printf("\nSayang sekali, sepertinya anda belum berhasil ;)\n");
            printf("Kata yang benar adalah \"");
            for(int j=0;j<5;j++){
                printf("%c",random_word.word[j]);
            }
            printf("\"\n\n");
            prize = 0;
            break;
        }
        printf("\nMasukkan kata tebakan Anda:\n");
        printf("(Program akan meminta masukkan hingga menerima sebuah kata dengan 5 huruf)\n");
        STARTWORD("","");
        while(currentWord.Length != 5){
            STARTWORD("","");
        }
        if(currentWord.TabWord[0] == random_word.word[0] || currentWord.TabWord[0]+32 == random_word.word[0]){
            if(currentWord.TabWord[1] == random_word.word[1] || currentWord.TabWord[1]+32 == random_word.word[1]){
                if(currentWord.TabWord[2] == random_word.word[2] || currentWord.TabWord[2]+32 == random_word.word[2]){
                    if(currentWord.TabWord[3] == random_word.word[3] || currentWord.TabWord[3]+32 == random_word.word[3]){
                        if(currentWord.TabWord[4] == random_word.word[4] || currentWord.TabWord[4]+32 == random_word.word[4]){
                            printf("\nSelamat, Anda berhasil menebak kata tersebunyi!!!\n");
                            printf("%d rupiah telah ditambahkan ke akun anda.\n\n",prize);
                            break;
                        }
                    }
                }
            }
        }
        boolean check_char[] = {0,0,0,0,0};
        boolean check_place[] = {0,0,0,0,0};
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                if(currentWord.TabWord[j] == random_word.word[k] || currentWord.TabWord[j]+32 == random_word.word[k]){
                    check_char[j] = true;
                    if(j == k){
                        check_place[j]=true;
                        break;
                    }
                }
            }
        }
        for(int j=0;j<5;j++){
            history[6-i][j*3] = currentWord.TabWord[j];
            if(check_char[j] == true){
                if(check_place[j] == true){
                    history[6-i][j*3 + 1] = ' ';
                }
                else{
                    history[6-i][j*3 + 1] = '*';
                }
            }
            else{
                history[6-i][j*3 + 1] = '%';
            }
            history[6-i][j*3 + 2] = ' ';
        }
        i--;
        printf("Hasil:\n");
        for(int j=6;j>i;j--){
            for(int k=0;k<15;k++){
                printf("%c",history[6-j][k]);
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

int quantum_wordl3(){
    char random_word[5][6];
    int i = 4, prize = 0;
    while(i>0){
        if(i == 0){
            break;
        }
        list selected_word = rwg();
        for(int j=0;j<5;j++){
            random_word[i-1][j] = (char)selected_word.word[j];
        }
        if(random_word[i-1][0] == random_word[i][0]){
            if(random_word[i-1][1] == random_word[i][1]){
                if(random_word[i-1][2] == random_word[i][2]){
                    if(random_word[i-1][3] == random_word[i][3]){
                        if(random_word[i-1][4] == random_word[i][4]){
                            continue;
                        }
                    }
                }
            }
        }
        i--;
    }
    printf("\n\nSelamat datang di Quantum WORDL3!!!\n");
    printf("Anda mempunyai 9 kesempatan untuk menebak kata-kata tersebunyi berikut!\n\n");
    for(int i=0;i<9;i++){
            for(int j=0;j<4;j++){
                for(int k=0;k<4;k++){
                    printf("_ ");
                }
                printf("_ \t\t");
            }
            printf("\n");
        }
    char history[4][9][16];
    boolean right[4] = {0,0,0,0};
    int count = 0;
    i=9;
    while(1){
        if(i == 0){
            printf("\nSayang sekali, sepertinya anda belum berhasil ;)\n");
            printf("Kata yang benar adalah \"");
            for(int j=0;j<2;j++){
                for(int k=0;k<5;k++){
                    printf("%c",random_word[j][k]);
                }
                printf("\", \"");
            }
            for(int j=0;j<5;j++){
                printf("%c",random_word[2][j]);
            }
            printf("\", dan \"");
            for(int j=0;j<5;j++){
                printf("%c",random_word[3][j]);
            }
            printf("\"\n\n");
            prize = 0;
            break;
        }
        printf("\nKata yang berhasil anda tebak:\n");
        for(int j=0;j<4;j++){
            if(right[j]){
                for(int k=0;k<5;k++){
                    printf("%c",random_word[j][k]);
                }
                printf("\n");
            }
        }
        printf("\nMasukkan kata-kata tebakan Anda:\n");
        printf("(Program akan meminta masukkan hingga menerima sebuah kata dengan 5 huruf)\n");
        char answer[4][6];
        for(int j=0;j<4;j++){
            if(!right[j]){
                printf("%d. ",j+1);
                while(currentWord.Length != 5){
                    STARTWORD("","");
                }
                for(int k=0;k<5;k++){
                    answer[j][k] = currentWord.TabWord[k];
                }
                currentWord.Length = 0;
            }
        }
        for(int j=0;j<4;j++){
            if(!right[j]){
                if(answer[j][0] == random_word[j][0] || answer[j][0]+32 == random_word[j][0]){
                    if(answer[j][1] == random_word[j][1] || answer[j][1]+32 == random_word[j][1]){
                        if(answer[j][2] == random_word[j][2] || answer[j][2]+32 == random_word[j][2]){
                            if(answer[j][3] == random_word[j][3] || answer[j][3]+32 == random_word[j][3]){
                                if(answer[j][4] == random_word[j][4] || answer[j][4]+32 == random_word[j][4]){
                                    right[j]=1;
                                    prize += 1500;
                                    count++;
                                }
                            }
                        }
                    }
                }
            }
        }
        if(count == 4){
            printf("\nSelamat, Anda berhasil menebak kata tersebunyi!!!\n");
            printf("%d rupiah telah ditambahkan ke akun anda.\n\n",prize);
            break;
        }
        boolean check_char[4][5];
        boolean check_place[4][5];
        for(int j=0;j<4;j++){
            if(!right[j]){
                for(int k=0;k<5;k++){
                    check_char[j][k] = 0;
                    check_place[j][k] =0;
                }
            }
        }
        for(int j=0;j<4;j++){
            if(!right[j]){
                for(int k=0;k<5;k++){
                    for(int l=0;l<5;l++){
                        if(answer[j][k] == random_word[j][l] || answer[j][k]+32 == random_word[j][l]){
                            check_char[j][k] = true;
                            if(k == l){
                                check_place[j][k]=true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        for(int j=0;j<4;j++){
            if(!right[j]){
                for(int k=0;k<5;k++){
                    history[j][9-i][k*3] = answer[j][k];
                    if(check_char[j][k] == true){
                        if(check_place[j][k] == true){
                            history[j][9-i][k*3 + 1] = ' ';
                        }
                        else{
                            history[j][9-i][k*3 + 1] = '*';
                        }
                    }
                    else{
                        history[j][9-i][k*3 + 1] = '%';
                    }
                    history[j][9-i][k*3 + 2] = ' ';
                }
            }
            else{
                for(int k=0;k<15;k++){
                    history[j][9-i][k]=' ';
                }
            }
        }
        i--;
        printf("\n\nHasil:\n");
        for(int j=9;j>i;j--){
            for(int k=0;k<4;k++){
                for(int l=0;l<15;l++){
                    printf("%c",history[k][9-j][l]);
                }
                printf("\t\t");
            }
            printf("\n");
        }
        for(int j=0;j<i;j++){
            for(int k=0;k<4;k++){
                if(right[k]){
                    for(int l=0;l<5;l++){
                        printf("  ");
                    }
                }
                else{
                    for(int l=0;l<5;l++){
                        printf("_ ");
                    }
                }
                printf("\t\t");
            }
            printf("\n");
        }
    }
    return prize;
}

void work_challenge(int *money){
    while(1){
        printf("Daftar Challenge:\n");
        printf("1. Tebak Angka (biaya: 200)\n");
        printf("2. WORDL3 (biaya: 500)\n");
        printf("3. Quantum WORDL3 (biaya: 2000)\n\n");
        printf("Masukkan challenge yang ingin dimainkan: ");
        STARTWORD("","");
        if(currentWord.Length == 1 && currentWord.TabWord[0] == '1' && *money >= 200){
            *money += tebak_angka() - 200;
            break;
        }
        else if(currentWord.Length == 1 && currentWord.TabWord[0] == '2' && *money >= 500){
            *money += wordl3() - 500;
            break;
        }
        else if(currentWord.Length == 1 && currentWord.TabWord[0] == '3' && *money >= 1000){
            *money += quantum_wordl3() - 2000;
            break;
        }
        else{
            printf("\nMasukan tidak valid atau uang anda tidak cukup. Silahkan coba kembali.\n\n");
        }
    }   
}