/* 
 * File:   Recieve.c
 * Author: Noor
 *
 * Created on September 21, 2019, 4:59 PM
 */
#include "Var_Fun.h"
void main()
{
    Ports();
    LCD_Initialize();
    pwmIni();
    recieveIni();
    BRG9600();
    
    while(1)
    {
        
        Duty();
        Delay(0.5);
        
    }
    
}

void interrupt REC() 
{
    if (RCIF&&i<10)
    {
        if(RCREG!='\r')
        {
         rec[i]=RCREG;
         i++;
        }
        else
        {
        rec[i]='\0';
        
        switch(rec[0])
        {
            case 'S': for(j=0; j<=i; j++) 
                        spd[j]=rec[j]; 
                     // spd[j]='\0';
                        
                      break;
            case 'D': for(k=0; k<=i; k++) 
                        dir[k]=rec[k]; 
                     // dir[k]='\0';
                      DirLED();
                      break; 
        }
        
        DisplayClr();
        LCDGoto(0,1);
        LCDPutStr(spd);
        LCDGoto(0,0);
        LCDPutStr(dir);
        i=0;
        }
        RCIF = 0;
    }

}