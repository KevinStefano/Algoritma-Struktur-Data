#include "attack.h"
#include "STATE.h"
#include "array.h"
#include "mesininput.h"
#include <stdio.h>

int main(){
    STATE s;
    LoadSafeFile(&s);
    move(&s,&s.P1);
    move(&s,&s.P1);
    move(&s,&s.P1);
}