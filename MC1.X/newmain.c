/*
 * File:   newmain.c
 * Author: Family
 *
 * Created on September 21, 2019, 1:34 PM
 */


#include <xc.h>
#include "Confg.h"
#include "PWM.h"
#include "Recieve.h"
char i=0;
char array [5];

void main() 
{
     LCD_Initialize();
     GIE=1;
     recinit();
     BRG9600();
     PEIE=1;
     TRISB=0;
     LATB=0x00;
     pwminit();
     pwmreg(255);
     while(1)
     {
         
         if(array[4]=='R')
         
             LATB=8;
         else if(array[4]=='L')
             LATB=2;
         else if (array[4]=='U')
             LATB=1;
         else if (array[4]=='D')
             LATB=4;
         LCDGoto(0,0);
         LCDPutStr(array);
     }
     

}

void __interrupt() rec()
{
    if(RCIF)
    {
        if(RCREG!='\0')
        {
            array[i]=RCREG;
            i++;
            
            
        }
        else 
        {
            array[i]='\0';
            i=0;
        }
        RCIF=0;
        
    }
}
