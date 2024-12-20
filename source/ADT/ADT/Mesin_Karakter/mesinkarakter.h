/* File: mesinkarakter.h */
/* Definisi Mesin Karakter */

#ifndef __MESINKARAKTER_H_
#define __MESINKARAKTER_H_

#include <stdio.h>
#include "../../header/boolean.h"

#define MARK '.'
#define ENTER '\n'

/* State Mesin */
extern int retval;
extern char currentChar;
extern boolean isFile;

extern FILE *pita;
extern FILE *pitaFile;

extern void START(char *path, char *type);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin atau file tertentu, tergantung pada isi dari variabel isFile.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != EOF maka EOP akan padam (false)
          Jika currentChar = EOF maka EOP akan menyala (true) */

extern void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          Jika sudah mencapai EOF maka EOP akan menyala (true) */

extern char GetCC();
/* Mengirimkan currentChar */

extern boolean IsEOP();
/* Mengirimkan true jika sudah mencapai EOF (end of file) */

#endif