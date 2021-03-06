//TUBES ALSTRUKDAT
// ADT ARRAY DINAMIK
#ifndef ARRAY_H
#define ARRAY_H

#include "boolean.h"
#include "bangunan.h"
#include "listlinier.h"

/*  Kamus Umum */
#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999 
#define ElUndef 999

typedef struct {
  BANGUNAN B;
  address P;
} ElType;

/* Jenis Bangunan tidak ada kepemilikan*/
typedef int IdxType;  /* type indeks */
typedef struct { 
  ElType *TI; /* memori tempat penyimpan elemen (container) */
} BangunanTot;

/* ********** SELEKTOR ********** */
#define TI(T)     (T).TI
#define Elmt(T,i) (T).TI[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyBangunanTot (BangunanTot * T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

void Dealokasi(BangunanTot *T);
/*I.S BangunanTot belom terdefinisi*/
/*F.S Dealokasi terhadap array berhasil dan Bangunan Tot terdefinisi*/

int NbElmt (BangunanTot T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */

/* *** Daya tampung container *** */
int MaxNbEl (BangunanTot T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (BangunanTot T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx (BangunanTot T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (BangunanTot T, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff (BangunanTot T, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (BangunanTot T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */



/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType SearchBangunanTotByAddress (BangunanTot T, address PP);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */

/* ********** OPERASI LAIN ********** */
void CopyBangunanTot(BangunanTot Tin, BangunanTot * Tout, IdxType in, IdxType out);
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */


/* ********** SORTING ********** */
//Array Terurut berdasarkan Lokasinya 
//Contoh : Lokasinya (8,2) (2,8) (4,5) (2,7) 
//Maka akan terurut dari barus kemudian kolom (2,7)(2,8)(4,5)(8,2)
void InsSortAsc (BangunanTot * T); ///~~~~~~~~~~~~~~
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
//Misalnya tabelnya maxnya 5 dan isinya POINT (8,2) (2,8) (4,5)  maka tabel arraynya akan menjadi (2,7)(2,8)(4,5) * * (Pendefinisian tabel harus SELALU terurut menaik berdasar lokasi)
//Array Terurut berdasarkan Lokasinya 
//Contoh : Lokasinya (8,2) (2,8) (4,5) * * (2,7) 
//Maka akan terurut dari baris kemudian kolom (2,7)(2,8)(4,5)(8,2) * *
// Metode searching dilakukan hingga menemukan ElUndef
// Saat menghapus satu elemen maka elemen lainnya akan menggeser. Misal (2,7) dihapus maka jadi (2,8)(4,5)(8,2) * * *
// Mirip PrioQueue



void Add1Urut (BangunanTot * T, BANGUNAN Ba);//////////////////UNTUK PENAMBAHAN ARRAY
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */


void Del1Urut (BangunanTot *T, address Pe, IdxType Idx, int JPasNetto, int PEMAINKE); //MENGHAPUS ADDRESS
//I.S BangunanTot belom terapus elemennya
//F.S Saat dihapus dari array artinya
//Elemen Array berubah MILIK
//address menjadi 0
//AKan terupdate JPas Awal sebanyak JUMLAH AKHIR nETTO. SUdah Hasil bersih dan bukan harus dikurang dari jumlah acuan


#endif