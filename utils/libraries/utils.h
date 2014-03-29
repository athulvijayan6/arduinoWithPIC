#ifndef ATHUL_PIC_LIBRARY_utils
#define ATHUL_PIC_LIBRARY_utils

#include <stdlib.h>

#define INPUT 1
#define OUTPUT 0
#define LOW 0
#define HIGH 1
#define true 1
#define false 0

#define RA0 0
#define RA1 1
#define RA2 2
#define RA3 3
#define RA4 4
#define RA5 5
#define RA6 6
#define RA7 7
#define RA8 8
#define RA9 9
#define RA10 10
#define RA11 11
#define RA12 12
#define RA13 13
#define RA14 14
#define RA15 15

#define RB0 20
#define RB1 21
#define RB2 22
#define RB3 23
#define RB4 24
#define RB5 25
#define RB6 26
#define RB7 27
#define RB8 28
#define RB9 29
#define RB10 30
#define RB11 31
#define RB12 32
#define RB13 33
#define RB14 34
#define RB15 35

#define RISING 0
#define FALLING 1

#define INT0 0
#define INT1 1
#define INT2 2
#define INT3 3
#define INT4 4




/**********function declarations************************/
int random(int, int);
int constrain(int, int, int);
long map(long x, long in_min, long in_max, long out_min, long out_max);
void digitalWrite(int, int);
int digitalRead(int);
void pinMode(int, int);

void attachInterrupt(int, int, int);
void dettachInterrupt(int);
char lowByte(long);
char highByte(long);
char bitRead(int, int);
int bitWrite(int, int, int);
int bitSet(int, int);
int bitClear(int, int);
/*******************************************************/
#endif

