#include <xc.h>
#include <p24F16KA102.h>
#include "libraries/utils.h"

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

    pinMode(RB5, OUTPUT);
    pinMode(RB6, OUTPUT);
    pinMode(RB10, OUTPUT);
    pinMode(RA6, OUTPUT);
    LATB = 0;
    LATA = 0;
    digitalWrite(RB5, HIGH);
    digitalWrite(RB6, HIGH);
    digitalWrite(RB10, LOW);
    digitalWrite(RA6, LOW);
    while(1){
    	// if (digitalRead(RB13)==1){
    	// 	digitalWrite(RB15, HIGH);
    	// }
    	// else if(digitalRead(RB13)==0)
    	// 	digitalWrite(RB15, LOW);
	}
    return 0;
}
