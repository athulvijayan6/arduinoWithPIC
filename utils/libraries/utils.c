#include <xc.h>
#include <p24F16KA102.h>
#include "utils.h"

/*******************Functions*****************************/
int random(int start, int end){
	int ranTemp = rand();
	return start+ranTemp%(end-start);
}

int constrain(int x, int a, int b){
	if ((x-a)<0)
		return a;
	else if ((b-x)<0)
		return b;
	else
		return x;
}

long map(long x, long in_min, long in_max, long out_min, long out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void digitalWrite(int pin, int mode){
	if ((pin>0)&&(pin <16)){
		LATA = bitWrite(LATA, pin, mode);
	}
	else if ((pin>19)&&(pin<36))
	{
		LATB = bitWrite(LATB, pin-20, mode);
	}
}

int digitalRead(int pin){
	int bitstate = 0;

	if ((pin>0)&&(pin <16)){
		bitstate = (PORTA >> pin)&0x0001;
	}
	else if ((pin>19)&&(pin<36))
	{
		bitstate = (PORTB >> (pin-20))&0x0001;
	}
	return (bitstate);
}

void pinMode(int pin, int mode){
	if ((pin>0)&&(pin <16)){
		TRISA = bitWrite(TRISA, pin, mode);
	}
	else if ((pin>19)&&(pin<36))
	{
		TRISB = bitWrite(TRISB, pin-20, mode);
	}
}

void attachInterrupt(int pin, int trigger, int priority){
	INTCON1bits.NSTDIS = 1;
	INTCON2 = bitWrite(INTCON2, pin, trigger);
	switch (pin){
		case INT0:
			IPC0bits.INT0IP0 = bitRead(priority, 0);
			IPC0bits.INT0IP1 = bitRead(priority, 1);
			IPC0bits.INT0IP2 = bitRead(priority, 2);
			IEC0bits.INT0IE = 1;
			break;
		case INT1:
			IPC5bits.INT1IP0 = bitRead(priority, 0);
			IPC5bits.INT1IP1 = bitRead(priority, 1);
			IPC5bits.INT1IP2 = bitRead(priority, 2);
			IEC1bits.INT1IE = 1;
			break;
		case INT2:
			IPC7bits.INT2IP0 = bitRead(priority, 0);
			IPC7bits.INT2IP1 = bitRead(priority, 1);
			IPC7bits.INT2IP2 = bitRead(priority, 2);
			IEC1bits.INT2IE = 1;
			break;
	}
}

void dettachInterrupt(int pin){
	switch (pin){
		case INT0:
			IEC0bits.INT0IE = 0;
			break;
		case INT1:
			IEC1bits.INT1IE = 0;
			break;
		case INT2:
			IEC1bits.INT2IE = 0;
			break;
	}
}


char lowByte(long x){
	return x&0xFF;
}

char highByte(long x){
	return x>>8;
}

char bitRead(int x, int n){
	return (x>>n)&0x0001;
}

int bitWrite(int x, int n, int a){
	return a*(x|(0x0001<<n))+(!a)*((x^(0x0001<<n))-!((x>>n)&0x0001)*(0x0001<<n));
}

int bitSet(int x, int n){
	return x|(0x0001<<n);
}

int bitClear(int x, int n){
	return ((x^(0x0001<<n))-!((x>>n)&0x0001)*(0x0001<<n));
}

/***********************************************************/

/***********************Interrupt Routines *****************/