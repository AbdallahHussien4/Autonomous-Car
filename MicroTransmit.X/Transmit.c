/* 
 * File:   Transmit.c
 * Author: Noor
 *
 * Created on September 21, 2019, 2:35 PM
 */

#include "Var_Fun.h"
void main()
{
    BRG9600();
    Ports();
    CompareIni();
    AdcIni();
    LCD_Initialize();
   
   
     while(1)
     {
         Buttons();
     }
 }
  


void interrupt adc()
{

    if(CCP1IF)
    {  
         ADCON0bits.GO_DONE=1;
         CCP1IF=0;
    }
     if(ADIF)
     {
         LCDGoto(0,0);
   
    // float result=ADRES*5.0/1023;
      
         
         sprintf(txt,"SPD=%u\r",ADRES);
       //  SEND(txt);
         ADIF=0;
     }



     


}