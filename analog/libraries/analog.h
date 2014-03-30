#ifndef ATHUL_PIC_LIBRARY_adc
#define ATHUL_PIC_LIBRARY_adc
#define AN0 0
#define AN1 1
#define AN2 2
#define AN3 3
#define AN4 4
#define AN5 5
// #define AN6 6
// #define AN7 7
// #define AN8 8
// #define AN9 9
#define AN10 10
#define AN11 11
#define AN12 12
// #define AN13 13
// #define AN14 14
// #define AN15 15

#define PWM1 1

#define F_OSC 8000000
#define PWM_FREQ 1000
#define PWM_PRESCALE 1






/**********function declarations************************/
void startADC(int);
int analogRead(int);
void analogWrite(int, long);
/*******************************************************/
#endif

