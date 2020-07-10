#ifndef dio_h
#define dio_h

#include "ATMEGA32_Regs.h"
#include "BIT_Math.h"

#define dio_portA 0
#define dio_portB 1
#define dio_portC 2
#define dio_portD 3

#define dio_pin0 0
#define dio_pin1 1
#define dio_pin2 2
#define dio_pin3 3
#define dio_pin4 4
#define dio_pin5 5
#define dio_pin6 6
#define dio_pin7 7

#define dio_port_output 0xff
#define dio_port_input  0x00

#define dio_pin_output 1
#define dio_pin_input  0

#define dio_port_high 0xff
#define dio_port_low  0x00

#define dio_pin_high 1
#define dio_pin_low  0


void Dio_SetPortDir(uint8 port ,uint8 dir);
void Dio_SetPinDir (uint8 port,uint8 pin ,uint8 dir);

void Dio_WritePort(uint8 port,uint8 val);
void Dio_WritePin (uint8 port,uint8 pin,uint8 val);

void Dio_ReadPort(uint8 port,uint8* val);
void Dio_ReadPin (uint8 port,uint8 pin,uint8* val);
	
void Dio_ToggelePin(uint8 port,uint8 pin);	

//void Dio_SetPullUp();

	
	
	













#endif