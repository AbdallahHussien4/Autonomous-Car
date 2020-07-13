#include "Var_Fun.h"
void DirLED()
{
    switch(dir[4])
    {
        case 'u': LATB=0x00; LATB0=1; break;
        case 'r': LATB=0x00; LATB1=1; break;
        case 'l': LATB=0x00; LATB2=1; break;
        case 'd': LATB=0x00; LATB3=1; break;
    }
}

void Duty()
{
    char f;
    for( f=0; spd[f+4]!='\0'; f++)
       duty[f]=spd[f+4]; 
    
    duty[f]='\0';
    d=atoi(duty);  
    TMR2ON=1;
    CCP1CONbits.DC1B=d&0x0003;
    CCPR1L=(d>>2)&0x00FF;
    __delay_ms(2);
     
}
void pwmIni()
{
   
    TMR2=0;
    PR2=0xFF;
    CCP1CONbits.CCP1M=12;
    T2CKPS1=1;
    T2CKPS0=1;
     
}

void recieveIni()
{
    RCIE = 1;
    RCIF = 0;
    GIE = 1;
    PEIE = 1;
    CREN = 1;
}
void BRG9600()
{
    SPEN = 1;
    SYNC = 0;
    BRGH = 0;
    BRG16 = 0;
    SPBRG = 12;
}

void Ports()
{
    TRISC2=0;
    LATC2=0;
    TRISB=0x00;
    LATB=0x00;
}
void Delay(float fac)
{
    for(char i=0; i<20*fac; i++)
        __delay_ms(50);
}