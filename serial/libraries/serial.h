#ifndef ATHUL_PIC_LIBRARY_serial
#define ATHUL_PIC_LIBRARY_serial

#define _serial_buffer_len 40
#define _serial1_buffer_len 40

/**********function declarations************************/
void Serial_begin(int);
void Serial_write(unsigned char);
unsigned char Serial_read(void);
int Serial_available(void);
void Serial_print(unsigned char*);
void Serial_println(char*);
void Serial_end(void);
void Serial_flush(void);
unsigned char Serial_peek(void);

void Serial1_begin(int);
void Serial1_write(unsigned char);
unsigned char Serial1_read(void);
int Serial1_available(void);
void Serial1_print(unsigned char*);
void Serial1_println(char*);
void Serial1_end(void);
void Serial1_flush(void);
/*******************************************************/
#endif

