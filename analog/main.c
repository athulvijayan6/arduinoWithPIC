#include <xc.h>
#include <p24F16KA102.h>
#include "libraries/analog.h"

// 2,3,11,12
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
	int adcValue;
	while(1)
		adcValue = analogRead(AN12);
	Serial_begin(9600);
    return 0;
}
