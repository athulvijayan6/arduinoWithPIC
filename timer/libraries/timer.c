#include <xc.h>
#include <p24F16KA102.h>
#include "timer.h"

long timer1Counter = 0;

/*******************Functions*****************************/
void initTimer1(int _interrupt_priority){
	T1CON = 0x00;   //Stops the Timer1 and reset control reg.
	TMR1 = 0x00;    //Clear contents of the timer register
	PR1 = 0x0FA0;   //Load the Period register with the value 4000 for 1ms period
	IPC0bits.T1IP = _interrupt_priority;
	IFS0bits.T1IF = 0;  //Clear the Timer1 interrupt status flag
	IEC0bits.T1IE = 1;  //Enable interrupt
}

void startTimer1(){
	initTimer1(5);
	T1CONbits.TON = 1;
}
void stopTimer1(){
	T1CONbits.TON = 0;
}

void resetTimer1(){
	stopTimer1();
	IFS0bits.T1IF = 0;  //Clear the Timer1 interrupt status flag
	TMR1 = 0x00;    //Clear contents of the timer register
	timer1Counter = 0;
}

/***********************************************************/

/***********************Interrupt Routines *****************/

void __attribute__((__interrupt__,__shadow__,__no_auto_psv__)) _T1Interrupt(void){
	timer1Counter++;
	IFS0bits.T1IF = 0;  //Reset Timer1 interrupt flag and Return from ISR
}
/***********************************************************/