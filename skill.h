#ifndef SKILL_H
#define SKILL_H
#include "bangunan.h"
#include "listlinier.h"
#include "array.h"


void InstantUpgrade (Pemain Pe, BangunanTot *Ba, int PemainKe);

    /* Pemain mendapatkan skill ini pada skill awal
        I.S Penain mungkin belom punya bangunan
        F.S Setiap banguna yang dimiliki pemain naik satu level*/

void Shield (ACUAN *Semi, Pemain Pe, BangunanTot *Ba, int PemainKe); //Bonus
    /*Seluruh bangunan yang dimiliki pemain akan memiliki pertahanan selama 2 turn
        apabila pemain menggunakan skill ini 2 kali beturut-turut durasi tidak akan bertamabah, namun menjadi nilai maksimum    */

void ExtraTurn ();
    /*setelah pengaktifan skill ini berakhir, pemain selanjutnya tetap pemain yang sama*/

void AttackUp(ACUAN Ac, Pemain Pe, BangunanTot Ba, int PemainKe); //Bonus
 /*Jika pemain mengaktifkan skill ini, maka pertahanan lawan tidak akan mempengaruhi penyerangan.
    Syarat: Pemain baru saja melakukan penyerangan ke tower lawan dan tower pemain menjadi berjumlah 3 */
void CriticalHit (); //Bonus
    /* Syarat: Musuh baru saja melakukan skill Extra Turn
        F.S: pada bangunan yang melakukan serangan tepta selanjutnya hanya berkurang 1/2 dari jumlah seharusnya. */
void InstantReinforcement(Pemain Pe, BangunanTot *Ba, int PemainKe);
    /* Syarat : Diakhir gilirannya, bila semua bangunan yang ia miliki memiliki level 4
        F.S: Seluruh bangunan yang ia miliki bertambah 5 pasukannya*/
void Barrage (Pemain Pe, BangunanTot *Ba, int PemainKe);
    /* Syarat: Jumalah bangunan lawan baru saja menjadi 10
        F.S: Jumlah pasukan pada setiap bangunan lawan berkurang 10 */
void GetSkill(SKILL *S, Pemain Pe, int PemainKe);
    /* Menegcek kondisi apakah pemain mendapatkan suatu skill. Jika Mendapakatkan skill
        maka skill tersbut akan di addlast queue */

#endif