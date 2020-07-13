#include "Var_Fun.h"


void BRG9600()
{
    SPEN = 1;
    TXEN = 1;
    SYNC = 0;
    BRGH = 0;
    BRG16 = 0;
    SPBRG = 12;
}

void SEND(char* x) {
    char i=0;
    while(x[i])
    {
    TXREG = x[i];
    while (!TRMT);
    i++;
    }

}


void Ports()
{
    TRISB=0xFF;
    LATB=0x00;
    
}
void Buttons()
{
    
     if(!PORTBbits.RB0)
         {
             __delay_ms(10);
             while(!PORTBbits.RB0);
             __delay_ms(10);
             SEND("Dir=u\r");
         }
     else if(!PORTBbits.RB1)
         {
             __delay_ms(10);
             while(!PORTBbits.RB1);
             __delay_ms(10);
             SEND("Dir=r\r");
         }
     else if(!PORTBbits.RB2)
         {
             __delay_ms(10);
             while(!PORTBbits.RB2);
             __delay_ms(10);
             SEND("Dir=d\r");
         }
     else if(!PORTBbits.RB3)
         {
             __delay_ms(10);
             while(!PORTBbits.RB3);
             __delay_ms(10);
             SEND("Dir=l\r");
         }
     else if(!PORTBbits.RB4)
         {
             __delay_ms(10);
             while(!PORTBbits.RB4);
             __delay_ms(10);
             SEND(txt);
         }
}

void CompareIni()
{
   CCP1CONbits.CCP1M=0b0010;
   TRISC2=0;
   
   CCP1IF=0;
   CCP1IE=1;
   T1CONbits.RD16=1;
   T1CONbits.T1OSCEN=1;
   T1CONbits.T1CKPS=0b11;
   T1SYNC=0;
   
   TMR1CS=1;
   TMR1=0;
   CCPR1=62500;
   TMR1ON=1;
}

void AdcIni()
{
     int duty = 0;
     GIE=1;
     PEIE=1;
     ADIE=1;
     ADIF=0;
    ADCON1bits.PCFG = 0b1110;
    ADCON0bits.CHS = 0b0000;
    ADCON1bits.VCFG = 0b00;
    ADON = 1;
    ADFM = 1;
    ADCON2bits.ACQT = 0b001;
    ADCON2bits.ADCS = 0b110;
   ADCON0bits.GO_DONE=1;
}
