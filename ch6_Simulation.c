/*************************************************
Arxeio ylopoihshs	: ch6_Simulation.c
Syggrafeas			: Y. Cotronis 07/03/2016
Skopos				: Ylopoihsh ouras prosomoiwshs
Revision 			:  <Savvas Polychronakis - 25/3/2018>
**************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ch6_QArray.h"
#include "TStoixeiouOuras.h"
#include "tameio.h"

int main(void)
{	TOuras      	oura;				 /*oura pelatwn-aytokinhtvn */
	float			pithanotita_afiksis; /*pi8anothta afikshs*/
	unsigned int	xronos_eksipiretisis;/*xronos e3yphrethshs enos pelath*/ 
	unsigned int	xronos_leitourgias;  /*synolikos xronos leitourgias trapezas*/
	unsigned int	max;				 /*gia xrono eksipiretisis*/
	
	unsigned int	xronos;				 /*roloi prosomoiwshs*/
	unsigned int	xronos_anamonis;	 /*synolikos xronos anamonhs*/
	TSOuras			Pelatis;		 	 /* o pelaths sthn oyra*/
	float			mesos_xronos;		 /*mesos xronos anamonhs tvn pelatvn*/
	float			randomAfixi;
	int				duration;			 /*gia ti sunartisi TameioNewCustomer*/
	time_t			t;
	int arithmos_tameiwn,i,synolo_pelatwn;
	
	
	printf("Dwste xrono leitourgias trapezas (0 <=), pi8anothta afikshs in unit of time (0,1), max xrono e3yphrethshs (>=1) in unit of times)\n");
	scanf("%u %f %u %d",&xronos_leitourgias,&pithanotita_afiksis,&max,&arithmos_tameiwn);
	getchar();
	printf("H prosomoiwsh 8a diarkesei %4u units of time.\n",xronos_leitourgias);
	printf("H pi8anothta afikshs pelath se ena unit of time einai: %4.2f.\n",pithanotita_afiksis);
	printf("H diarkeia e3yphrethshs enos pelath einai apo 0 mexri %u .\n",max);
	TTameio			tameio[arithmos_tameiwn];
	OuraDimiourgia(&oura);
	printf("%d\n",arithmos_tameiwn);
	for(i=0;i<arithmos_tameiwn;i++){
		printf("GEIAAAA %d %d\n",i,arithmos_tameiwn);
		printf("tameio[i]->TimeBusy %d\n",tameio[i].TimeBusy);
		TameioDimiourgia(&(tameio[i]));
		printf("tameio[i]->TimeBusy %d\n",tameio[i].TimeBusy);
		printf("GEIAAAAsss %d %d\n",i,arithmos_tameiwn);
	}
	xronos = 0;
	xronos_anamonis =0;
	srand(time(&t));
	i=0;
	synolo_pelatwn = 0;
	printf("xronos %u,xronos leitourgias %4u, oura keni %d \n",xronos,xronos_leitourgias,OuraKeni(oura));
	while( xronos < xronos_leitourgias || !OuraKeni(oura))
	{
		printf("xronos ++\n");
		if(xronos < xronos_leitourgias){
			randomAfixi = (float)rand()/(float)RAND_MAX; 

			if ( randomAfixi < pithanotita_afiksis ){
				PelatisSetXronoEisodou(&Pelatis, xronos);
				xronos_eksipiretisis = rand() % max+1;
				PelatisSetXronoEksipiretisis(&Pelatis, xronos_eksipiretisis);
				if (!OuraProsthesi(&oura, Pelatis)){
					  printf("H oyra einai mikrh! H prosomoivsh stamataei \n");
					  getchar();
					  return 0;
				}
			}
		}
    	/* Tamias-Elegxos */
    	
		if ( TameioFree(tameio[i])){	/*eley8eros tamias*/
			if (!OuraKeni(oura))			/*yparxei pelaths*/
			{	OuraApomakrynsh(&oura,&Pelatis);		/*phgainei sto tamio*/
				xronos_anamonis += xronos - PelatisGetXronoEisodou(Pelatis);	/*ypologismos xronoy paramonhs sthn oura*/
				/* printf("Time is %d Time out %d\n", xronos, PelatisGetXronoEisodou(Pelatis)); */
				duration = (PelatisGetXronoEksipiretisis(Pelatis))-1; /* kallyptei to trexon unit time */
				printf("\nApo to tameio  eksyphreth8hkan %d pelates\n",TameioGetArithmosPelatwn(tameio[i]));
				TameioNewCustomer(&(tameio[i]), duration);
				printf("\nApo to tameio eksyphreth8hkan %d pelates\n",TameioGetArithmosPelatwn(tameio[i]));
				TameioBusy(&(tameio[i]));
				i++;
				if(i>=arithmos_tameiwn)
					i = 0;
			}else TameioNoWork(&(tameio[i]));
		}
		else{ 
			TameioInService(&(tameio[i]));		/*o tamias apasxolhmenos me pelath */
			TameioBusy(&(tameio[i]));
		}
		printf("xronos ++\n");
		xronos++; /*o xronos prosomoivshs ay3anetai kata 1 unit of time*/
	}
	for(i=0;i<arithmos_tameiwn;i++){
		synolo_pelatwn += TameioGetArithmosPelatwn(tameio[i]);
	}
	if (synolo_pelatwn == 0)
		mesos_xronos = 0.0;
	else
		mesos_xronos = ((float)xronos_anamonis)/((float)synolo_pelatwn);
		printf("GEIAAAA\n");
	for(i=0;i<arithmos_tameiwn;i++){
		printf("\nApo to tameio %d eksyphreth8hkan %d pelates\n", i,TameioGetArithmosPelatwn(tameio[i]));
		printf("To tameio %d itan apasxolimeno gia %d units of time\n",i, TameioGetBusyXronos(tameio[i]));
		printf("To tameio %d htan adranes gia %d units of time\n",i, TameioGetInactiveXronos(tameio[i]));
	}
	printf("%d pelates den eksyphreth8hkan\n",OuraGetSize(oura));
	printf("O mesos xronos anamonhs htan %4.2f units of time.\n",mesos_xronos);	
	printf("O pragmatikos telikos xronos einai %u kai xreiastikan %u epipleon lepta\n",xronos,xronos - xronos_leitourgias);
    getchar();
	return 0;
}

