/*
 * File:   newmain.c
 * Author: Family
 *
 * Created on September 21, 2019, 1:51 PM
 */


#include <xc.h>
#include "Confg.h"
#include "lcd.h"

void main() 
{
    GIE=1;
    PEIE=1;
    Cmpinit();
    ADCinit();
    BRG9600();
   
    while (1)
    {
       
     DIR ();
     
    }
    
}
void __interrupt()ADC()
{
    if(CCP1IF)
    {
        GO_DONE=1;
        
        CCP1IF=0;
    }
    if(ADIF)
    {
        while(GO_DONE);
        ADCSND();
        ADIF=0;
    }
}

