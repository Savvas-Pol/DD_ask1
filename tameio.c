/*************************************************************************
Implementation File	: tameio.c
Author	Date		: Savvas Polychronakis 25/3/2018
Purpose 			: Ylopoihsh sinartisewn tameiou
Revision			:  <Savvas Polychronakis - 25/3/2018>
**************************************************************************/

#include <stdio.h>
#include "tameio.h"

void TameioDimiourgia(TTameio *tameio){
	tameio->TimeBusy = 0;
	tameio->TimeInactive = 0;
	tameio->ArithmoPelaton = 0;
	tameio->enapomenonXronos = 0;	
}

void TameioNewCustomer(TTameio *tameio, int Duration){
	tameio->ArithmoPelaton++;
	tameio->enapomenonXronos = Duration;
}

void TameioInService(TTameio *tameio){
	tameio->enapomenonXronos--;
}

void TameioNoWork(TTameio *tameio){
	tameio->TimeInactive++;	
}

void TameioBusy(TTameio *tameio){
	tameio->TimeBusy++;	
}

int TameioFree(TTameio tameio){	
	return (tameio.enapomenonXronos == 0);	
}

int TameioGetArithmosPelatwn(TTameio tameio){	
	return tameio.ArithmoPelaton;	
}

int TameioGetInactiveXronos(TTameio tameio){	
	return tameio.TimeInactive;	
}

int TameioGetBusyXronos(TTameio tameio){	
	return tameio.TimeBusy;	
}
