#include <xc.h>
#include <p24F16KA102.h>
#include "libraries/serial.h"

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
	Serial1_begin(9600);
	char c;
	while(1){
		while (Serial1_available()<1);
		c = Serial1_read();
		Serial1_write(c);
	}
	return 0;
}