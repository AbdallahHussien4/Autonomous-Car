#include "Recieve.h"
#include "Confg.h"

void recinit()
{
    RCIE = 1;
    RCIF = 0;
    CREN = 1;
}
void BRG9600() {
    SPEN = 1;
    TXEN = 1;
    SYNC = 0;
    BRGH = 0;
    BRG16 = 0;
    SPBRG = 12;
}