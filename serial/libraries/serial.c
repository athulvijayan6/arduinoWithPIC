#include <xc.h>
#include <p24F16KA102.h>
#include "serial.h"

/////////Serial1///////////
unsigned char _serial_buffer[_serial_buffer_len];
int _serial_buffer_size = 0;
/////////Serial2///////////
unsigned char _serial1_buffer[_serial1_buffer_len];
int _serial1_buffer_size = 0;

/*******************Functions*****************************/
void Serial_begin(int baud_rate){
	baud_rate = 25;        //FCPU/(16*baud_rate)-1; 	//calculate system baud rate
	
	AD1PCFGbits.PCFG4 = 1; //make RX Digital pins
	U1BRG = baud_rate;
	
	IPC2bits.U1RXIP2 = 1;	  //RX interrupt priority
	IPC2bits.U1RXIP1 = 0;     //RX interrupt subpriority
	IPC2bits.U1RXIP0 = 0;     //RX interrupt subpriority
	
	U1STA = 0;                //Reset status Register
	U1MODEbits.UARTEN = 1;    //Enable UART1
	U1STAbits.UTXEN = 1;      //Enable transmission
	
	IEC0bits.U1RXIE = 1;      //Enable RX interrupt
	IFS0bits.U1RXIF = 0;      //clear RX interrupt flag
}

void Serial_end(void){
	IFS0bits.U1RXIF = 0;      //clear RX interrupt flag
	IEC0bits.U1RXIE = 0;      //disable RX interrupt
	U1STA = 0; 
	U1MODEbits.UARTEN = 0;    //disable UART1
	AD1PCFGbits.PCFG4 = 0;
}

void Serial_flush(void){
	while (U1STAbits.UTXBF == 1);
}

unsigned char Serial_peek(void){
	return _serial_buffer[1];
}

void Serial_write(unsigned char data){
	while (U1STAbits.UTXBF == 1);
	U1TXREG = data;
}

void Serial_print(unsigned char* data){
	int i = 0;
	while (data[i]){
		Serial_write(data[i]);
		i++;
	}
}

unsigned char Serial_read(){
	if (_serial_buffer_size >0)
		_serial_buffer_size = _serial_buffer_size - 1;
	else
		return 0;
	unsigned char data = _serial_buffer[0];
	for (int i=0; i<_serial_buffer_size;i++){
		_serial_buffer[i]=_serial_buffer[1+i];
	}
	return data;
}

int Serial_available(){
	return _serial_buffer_size;
}

void Serial_println(char* data){
	Serial_print(data);
	Serial_write('\n');
}

void __attribute__((__interrupt__, auto_psv)) _U1RXInterrupt(void){
		if (U1STAbits.OERR == 1)
			U1STAbits.OERR = 0;
		else if((U1STAbits.OERR == 0)&&(U1STAbits.PERR == 0)&&(U1STAbits.FERR == 0)&&(U1STAbits.URXDA == 1)){
			_serial_buffer[_serial_buffer_size] = U1RXREG & 0xFF;
			if (_serial_buffer_size<_serial_buffer_len-1)
			{
				_serial_buffer_size++;
			}
			
		}
	IFS0bits.U1RXIF = 0;
}

void Serial1_begin(int baud_rate){
	baud_rate = 25;        //FCPU/(16*baud_rate)-1; 	//calculate system baud rate
	
	AD1PCFGbits.PCFG3 = 1; //make RX Digital pins
	AD1PCFGbits.PCFG2 = 1; //make RX Digital pins
	U2BRG = baud_rate;
	
	IPC7bits.U2RXIP2 = 1;	  //RX interrupt priority
	IPC7bits.U2RXIP1 = 0;     //RX interrupt subpriority
	IPC7bits.U2RXIP0 = 0;     //RX interrupt subpriority
	
	U2STA = 0;                //Reset status Register
	U2MODEbits.UARTEN = 1;    //Enable UART1
	U2STAbits.UTXEN = 1;      //Enable transmission
	
	IEC1bits.U2RXIE = 1;      //Enable RX interrupt
	IFS1bits.U2RXIF = 0;      //clear RX interrupt flag
}

void Serial1_end(void){
	IFS1bits.U2RXIF = 0;      //clear RX interrupt flag
	IEC1bits.U2RXIE = 0;      //disable RX interrupt
	U2STA = 0; 
	U2MODEbits.UARTEN = 0;    //disable UART1
	AD1PCFGbits.PCFG3 = 0; 
	AD1PCFGbits.PCFG2 = 0; 
}

void Serial1_flush(void){
	while (U2STAbits.UTXBF == 1);
}

unsigned char Serial1_peek(void){
	return _serial1_buffer[1];
}

void Serial1_write(unsigned char data){
	while (U2STAbits.UTXBF == 1);
	U2TXREG = data;
}

void Serial1_print(unsigned char* data){
	int i = 0;
	while (data[i]){
		Serial1_write(data[i]);
		i++;
	}
}

unsigned char Serial1_read(){
	if (_serial1_buffer_size >0)
		_serial1_buffer_size = _serial1_buffer_size - 1;
	else
		return 0;
	unsigned char data = _serial1_buffer[0];
	for (int i=0; i<_serial1_buffer_size;i++){
		_serial1_buffer[i]=_serial1_buffer[1+i];
	}
	return data;
}

int Serial1_available(){
	return _serial1_buffer_size;
}

void Serial1_println(char* data){
	Serial1_print(data);
	Serial1_write('\n');
}

void __attribute__((__interrupt__, auto_psv)) _U2RXInterrupt(void){
		if (U2STAbits.OERR == 1)
			U2STAbits.OERR = 0;
		else if((U2STAbits.OERR == 0)&&(U2STAbits.PERR == 0)&&(U2STAbits.FERR == 0)&&(U2STAbits.URXDA == 1)){
			_serial1_buffer[_serial1_buffer_size] = U2RXREG & 0xFF;
			if (_serial1_buffer_size<_serial1_buffer_len-1)
			{
				_serial1_buffer_size++;
			}
			
		}
	IFS1bits.U2RXIF = 0;
}
/***********************************************************/

/***********************Interrupt Routines *****************/