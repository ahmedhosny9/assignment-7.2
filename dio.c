#include "dio.h"

void Dio_SetPortDir(uint8 port ,uint8 dir){
	
switch (port){

case dio_portA :
DDRA = dir;
break;

case dio_portB :
DDRB = dir;
break;

case dio_portC :
DDRC = dir;
break;

case dio_portD :
DDRD = dir;
break;	

default:
break;	
}
}
void Dio_SetPinDir (uint8 port,uint8 pin ,uint8 dir){
	
switch (dir){

case dio_pin_output:          // output dir 

switch (port){
case dio_portA:
SET_BIT(DDRA,pin);
break;
case dio_portB:
SET_BIT(DDRB,pin);
break;
case dio_portC:
SET_BIT(DDRC,pin);
break;
case dio_portD:
SET_BIT(DDRD,pin);
break;	
}
break;

case dio_pin_input:                  //input dir
switch (port){
	case dio_portA:
	CLR_BIT(DDRA,pin);
	break;
	case dio_portB:
	CLR_BIT(DDRB,pin);
	break;
	case dio_portC:
	CLR_BIT(DDRC,pin);
	break;
	case dio_portD:
	CLR_BIT(DDRD,pin);
	break;
}
break;

default:
break;
	
}	
}

void Dio_WritePort(uint8 port,uint8 val){
switch (port){

case dio_portA :
PORTA = val;
break;

case dio_portB :
PORTB = val;
break;

case dio_portC :
PORTC = val;
break;

case dio_portD :
PORTD = val;
break;

default:
break;
}
}
void Dio_WritePin (uint8 port,uint8 pin,uint8 val){
switch (val){

	case dio_pin_high:          // output dir

	switch (port){
		case dio_portA:
		SET_BIT(PORTA,pin);
		break;
		case dio_portB:
		SET_BIT(PORTB,pin);
		break;
		case dio_portC:
		SET_BIT(PORTC,pin);
		break;
		case dio_portD:
		SET_BIT(PORTD,pin);
		break;
	}
	break;

	case dio_pin_low:                  //input dir
	switch (port){
		case dio_portA:
		CLR_BIT(PORTA,pin);
		break;
		case dio_portB:
		CLR_BIT(PORTB,pin);
		break;
		case dio_portC:
		CLR_BIT(PORTC,pin);
		break;
		case dio_portD:
		CLR_BIT(PORTD,pin);
		break;
	}
	break;

	default:
	break;
	
}	
}

void Dio_ReadPort(uint8 port,uint8* val){
switch (port){

	case dio_portA :
	*val=PINA;
	break;

	case dio_portB :
	*val=PINB;
	break;

	case dio_portC :
	*val=PINC;
	break;

	case dio_portD :
	*val=PIND;
	break;

	default:
	break;
}		
}

void Dio_ReadPin (uint8 port,uint8 pin,uint8* val){
switch (port){

	case dio_portA :
	*val= GET_BIT(PINA,pin);
	break;

	case dio_portB :
	*val=GET_BIT(PINB,pin);
	break;

	case dio_portC :
	*val=GET_BIT(PINC,pin);
	break;

	case dio_portD :
	*val=GET_BIT(PIND,pin);
	break;

	default:
	break;
}		
}

void Dio_ToggelePin(uint8 port,uint8 pin){
	switch (port){

		case dio_portA :
		Toggle_BIT(PINA,pin);
		break;

		case dio_portB :
		Toggle_BIT(PINA,pin);
		break;

		case dio_portC :
		Toggle_BIT(PINA,pin);
		break;

		case dio_portD :
		Toggle_BIT(PINA,pin);
		break;

		default:
		break;
	}
}