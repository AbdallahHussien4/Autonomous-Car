#include "Transmiit.h"
#include "Confg.h"
void BRG9600()
{
    SPEN = 1;
    TXEN = 1;
    SYNC = 0;
    BRGH = 0;
    BRG16 = 0;
    SPBRG = 12;
}

void SEND(char x) 
{

    TXREG = x;
    while (!TRMT);

}

void DIR ()
{
    char txt[7]="Dir=";
    TRISB=1;
    if (PORTBbits.RB0)
    {
        txt[4]='R';
        txt[5]='\0';
        while (PORTBbits.RB0);
        for (char i = 0;txt[i]!='\0';i++)
        SEND(txt[i]);
        SEND('\0');

        
    }
    if (PORTBbits.RB1)
    {
        while (PORTBbits.RB1);
        txt[4]='L';
        txt[5]='\0';
        for (char i = 0;txt[i]!='\0';i++)
        SEND(txt[i]);
                SEND('\0');

        
    }
    if (PORTBbits.RB2)
    {
        while (PORTBbits.RB2);
        txt[4]='U';
        txt[5]='\0';
        for (char i = 0;txt[i]!='\0';i++)
        SEND(txt[i]);
                SEND('\0');

        
    }
    if (PORTBbits.RB3)
    {
        while (PORTBbits.RB3);
        txt[4]='D';
        txt[5]='\0';
        for (char i = 0;txt[i]!='\0';i++)
        SEND(txt[i]);
                SEND('\0');

        
    }
    
}