#include "skill.h"
#include <stdio.h>


void InstantUpgrade (Pemain Pe, BangunanTot *Ba, int PemainKe)
    /* Pemain mendapatkan skill ini pada skill awal
        I.S Penain mungkin belom punya bangunan
        F.S Setiap banguna yang dimiliki pemain naik satu level*/
{
    address P;
    if(PemainKe == 1){
    P = First(Pe.L1);
    while(P != Nil){
        (*Ba).TI[Info(P)].B.Level+=1;
        Next(P);

    }
    }else if(PemainKe == 2){
        P = First(Pe.L2);
        while( P!= Nil){
            (*Ba).TI[Info(P)].B.Level +=1;
            Next(P);
        }
    }

}
void Shield (Pemain Pe, BangunanTot *Ba, int PemainKe) //Bonus
    /*Seluruh bangunan yang dimiliki pemain akan memiliki pertahanan selama 2 turn
        apabila pemain menggunakan skill ini 2 kali beturut-turut durasi tidak akan bertamabah, namun menjadi nilai maksimum    */
{
    address P;
    ACUAN A;
    Inisialisasi(&A);
    if(PemainKe == 1){
        P = First(Pe.L1);
        while(P != Nil){
        if(!IsAdaPertahanan((*Ba).TI[Info(P)].B)){
            CariDariAcuan(A,(*Ba).TI[Info(P)].B.Jenis,(*Ba).TI[Info(P)].B.Level,'P')==1;
        }else{
            // bangunana akan menjadi nilai maksimum
        }
        Next(P);
        }
    }else if(PemainKe == 2){
        P = First(Pe.L2);
        while(P != Nil){
        if(!IsAdaPertahanan((*Ba).TI[Info(P)].B)){
            CariDariAcuan(A,(*Ba).TI[Info(P)].B.Jenis,(*Ba).TI[Info(P)].B.Level,'P')==1;
        }else{
            // bangunana akan menjadi nilai maksimum
        }
        Next(P);
        }
    }
}
void ExtraTurn (){}
    /*setelah pengaktifan skill ini berakhir, pemain selanjutnya tetap pemain yang sama*/

void AttackUp() //Bonus
 /*Jika pemain mengaktifkan skill ini, maka pertahanan lawan tidak akan mempengaruhi penyerangan.
    Syarat: Pemain baru saja melakukan penyerangan ke tower lawan dan tower pemain menjadi berjumlah 3 */
    {

    }
void CriticalHit (){} //Bonus
    /* Syarat: Musuh baru saja melakukan skill Extra Turn
        F.S: pada bangunan yang melakukan serangan tepta selanjutnya hanya berkurang 1/2 dari jumlah seharusnya. */
void InstantReinforcement(Pemain Pe, BangunanTot *Ba, int PemainKe)
    /* Syarat : Diakhir gilirannya, bila semua bangunan yang ia miliki memiliki level 4
        F.S: Seluruh bangunan yang ia miliki bertambah 5 pasukannya*/
        {
            address P;
            if(PemainKe == 1){
                P = First(Pe.L1);
                while(P != Nil){
                    (*Ba).TI[Info(P)].B.Jpas += 5;
                    Next(P);
                }
            }else if(PemainKe == 2){
                P = First(Pe.L2);
                while(P != Nil){
                    (*Ba).TI[Info(P)].B.Jpas += 5;
                    Next(P);
                }
            }
        }
void Barrage (Pemain Pe, BangunanTot *Ba, int PemainKe)
    /* Syarat: Jumalah bangunan lawan baru saja menjadi 10
        F.S: Jumlah pasukan pada setiap bangunan lawan berkurang 10 */
        {
            address P;
            if(PemainKe == 1){
                P = First(Pe.L2);
                while(P != Nil){
                    (*Ba).TI[Info(P)].B.Jpas -= 10;
                    Next(P);
                }
            }else if(PemainKe == 2){
                P = First(Pe.L1);
                while(P != Nil){
                    (*Ba).TI[Info(P)].B.Jpas -= 10;
                    Next(P);
                }
            }
        }