#include <pic18f4620.h>
#include "Confg.h"
#include "ADC.h"

void ADCinit()
{
    ADCON0bits.CHS=0b0000;
    ADCON1bits.PCFG=0b1110;
    ADON=1;
    ADCON1bits.VCFG=0b00;
    ADFM=1;
    ADCON2bits.ACQT=0b001;
    ADCON2bits.ADCS=0b110;
    ADIE=1;
    GO_DONE=1;
    ADIF=0;
    
}
void Cmpinit()
{
    CCP1CONbits.CCP1M=0b1010;
    T1CONbits.RD16=1;
    T1CONbits.T1CKPS=0b11;
    T1OSCEN=1;
    TMR1CS=0;
    CCP1IE=1;
    CCP1IF=0;
    TMR1=0;
    TMR1ON=1;
    
}
void ADCSND ()
{
   for(char x=100;x>0;x/=10)
   {
       
       SEND (ADRESL/x+'0');
       ADRESL=ADRESL%x;
   }
}




