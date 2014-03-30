#include <xc.h>
#include <p24F16KA102.h>
#include "analog.h"

/*For simplicity, the ADC initiates as soon as analogRead() is called.
  For using a pin as digital after it is been used for analog,
  RESET Register A1PCFG for the corresponding pin                  */
/*******************Functions*****************************/
void startADC(int pin){
	AD1PCFG = ~(0x0001<<pin);
	AD1CON1 = 0x00;
	AD1CON1bits.ADSIDL = 1;
	AD1CON1bits.SSRC2 = 1;
	AD1CON1bits.SSRC1 = 1;
	AD1CON1bits.SSRC0= 1;
	AD1CON2 = 0x00;
	AD1CON3 = 0x1F01;
	AD1CHS = 0x00;
	AD1CSSL = 0x00;
	AD1CON1bits.ADON = 1;
}

void initPWM(int pin, int dutyCycle){
	if (pin == PWM1){
		OC1CONbits.OCTSEL = 1;
		OC1CONbits.OCM0 = 0;   //no fault detection
		OC1CONbits.OCM1 = 1;
		OC1CONbits.OCM2 = 1;
		OC1R = dutyCycle;
		OC1RS = dutyCycle;
	}
}

void analogWrite(int pin, long dutyCycle){
	
	PR3 = (int)F_OSC/(2*PWM_FREQ*PWM_PRESCALE)-1;
	if (T3CON == 0)
		T3CON = 0x8000;
	initPWM(pin, dutyCycle);	
}

int analogRead(int pin){
	startADC(pin);
	AD1CHS |= pin;
	AD1CON1bits.SAMP = 1;
	while (!AD1CON1bits.DONE);
	return ADC1BUF0;
}
/***********************************************************/

/***********************Interrupt Routines *****************/