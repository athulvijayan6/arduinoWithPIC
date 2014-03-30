#include <p24F16KA102.h>


//configs
/********************************************************/
// _CONFIG2(0xF9FC);
// _CONFIG1(0x377F);
_FGS(GWRP_OFF & GCP_OFF);
_FOSCSEL(FNOSC_PRI & IESO_OFF);
_FOSC(POSCMOD_HS & OSCIOFNC_ON & POSCFREQ_HS & FCKSM_CSDCMD);
_FWDT(WINDIS_OFF & FWDTEN_OFF);
_FPOR(BOREN_BOR2 & PWRTEN_OFF  & MCLRE_ON);
_FDS(DSBOREN_OFF & DSWDTEN_OFF);

/********************************************************/
int main(){
    TRISB = 0x0000;
    LATB = 0xFFFF;
    while(1){

    }
    return 0;
}