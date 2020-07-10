/*
 * GccApplication1.c
 *
 * Created: 27/06/2020 02:11:33 
 * Author : Ali/st Ahmed hosny
 */ 


#define F_CPU 16000000  //for until/delay.h
#include "lcd.h"
#include "lcdcfg.h"
#include <util/delay.h>




int main(void)
{
	LCD_Init();
	
	
	
		
	    
		sint32 num=1234;
		LCD_WriteIntger  (num);
		
		
	
	
	
	
return 0;
}

