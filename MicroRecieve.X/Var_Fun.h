/* 
 * File:   Var_Fun.h
 * Author: Noor
 *
 * Created on September 22, 2019, 9:30 PM
 */

#ifndef VAR_FUN_H
#define	VAR_FUN_H
#include <stdio.h>
#include <stdlib.h>
#include "conf.h"
#include "lcd.h"

char rec[10];
char dir[10];
char spd[10];
char duty[5];
char t[10];
char i=0;
  unsigned int d;
char k=0,j=0;
void BRG9600();
void recieveIni();
void pwmIni();
void Duty();
void DirLED();
void Ports();
void Delay(float fac);
#endif	/* VAR_FUN_H */

