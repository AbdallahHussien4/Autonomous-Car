#include <pic18f4620.h>

#include "PWM.h"
void pwminit()
{
    CCP1CONbits.CCP1M=12;
    TRISC2=0;
    PR2=124;
    T2CONbits.T2CKPS=2;
    TMR2=0;
    TMR2ON=1;
}
void pwmreg(int duty)
{
    CCP1CONbits.DC1B=duty&0b11;
    CCPR1L=duty>>2;
}

