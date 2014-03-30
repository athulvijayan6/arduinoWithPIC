#include <xc.h>
#include <p24F16KA102.h>
#include "libraries/timer.h"

//configs
/********************************************************/
_FGS(GWRP_OFF & GCP_OFF);
_FOSCSEL(FNOSC_PRI & IESO_OFF);
_FOSC(POSCMOD_HS & OSCIOFNC_ON & POSCFREQ_HS & FCKSM_CSDCMD);
_FWDT(WINDIS_OFF & FWDTEN_OFF);
_FPOR(BOREN_BOR2 & PWRTEN_OFF  & MCLRE_ON);
_FDS(DSBOREN_OFF & DSWDTEN_OFF);
/********************************************************/
int main(){
	/*****blink code ********/
	TRISB = 0x00;
	startTimer1();
	LATB = 0xFFFF;

	while (1){
		LATBbits.LATB15 = 1;
		while(timer1Counter<1000);
		resetTimer1();
		startTimer1();
		LATBbits.LATB15 = 0;
		while(timer1Counter<1000);
		resetTimer1();
		startTimer1();
	}
	/************************/
	return 0;
}
