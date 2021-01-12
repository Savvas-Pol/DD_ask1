/*************************************************************************
Header File Name		: tameio.h
Author Date				: Savvas Polychronakis 25/3/2018
Purpose					: Struct TTameio kai dilwseis sinartisewn
Revision				:  <Savvas Polychronakis - 25/3/2018>
**************************************************************************/

#ifndef __TAMEIO__
#define __TAMEIO__

typedef struct{
	int TimeBusy;					/*xronos pou itan apasxolimeno*/
	int TimeInactive;				/*xronos pou itan adranes*/
	int ArithmoPelaton;				/*arithmos pelatwn pou eksipiretise*/
	int enapomenonXronos;			/*gia na oloklirwsei tin eksipiretisi enos pelati*/
}TTameio;

void TameioDimiourgia(TTameio *tameio);

void TameioNewCustomer(TTameio *tameio, int Duration);
void TameioInService(TTameio *tameio);
void TameioNoWork(TTameio *tameio);
void TameioBusy(TTameio *tameio);

int TameioFree(TTameio tameio);
int TameioGetArithmosPelatwn(TTameio tameio);
int TameioGetInactiveXronos(TTameio tameio);
int TameioGetBusyXronos(TTameio tameio);

#endif
