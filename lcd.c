#include "lcd.h"



void LCD_Init               (void)
{
	#if Lcd_Made==4
Dio_SetPinDir(Lcd_4bit_commdport,Lcd_RS_pin,dio_pin_output);
Dio_SetPinDir(Lcd_4bit_commdport,Lcd_Rw_pin,dio_pin_output);
Dio_SetPinDir(Lcd_4bit_commdport,Lcd_E_pin,dio_pin_output);

Dio_SetPinDir(Lcd_4bit_dateport,Lcd_D4_pin,dio_pin_output);
Dio_SetPinDir(Lcd_4bit_dateport,Lcd_D5_pin,dio_pin_output);
Dio_SetPinDir(Lcd_4bit_dateport,Lcd_D6_pin,dio_pin_output);
Dio_SetPinDir(Lcd_4bit_dateport,Lcd_D7_pin,dio_pin_output);

_delay_ms(200);

LCD_WriteCommd(0x33);
LCD_WriteCommd(0x32);
LCD_WriteCommd(0x28);
LCD_WriteCommd(0x0C);
LCD_WriteCommd(0x01);
LCD_WriteCommd(0x02);
LCD_WriteCommd(0x06);

_delay_ms(40);

    #endif	
}

void LCD_WriteCommd    (uint8 cmd)
{
	#if Lcd_Made == 4
	
   Dio_WritePin(Lcd_4bit_commdport,Lcd_Rw_pin,dio_pin_low);
   Dio_WritePin(Lcd_4bit_commdport,Lcd_RS_pin,dio_pin_low);
   Dio_WritePin(Lcd_4bit_commdport,Lcd_E_pin,dio_pin_low);
   
   PORTA = (cmd & 0xf0);
   
   Dio_WritePin(Lcd_4bit_commdport,Lcd_E_pin,dio_pin_high);
   _delay_ms(20);
   Dio_WritePin(Lcd_4bit_commdport,Lcd_E_pin,dio_pin_low);
   _delay_ms(10);
   
   PORTA = (cmd << 4);
   
   Dio_WritePin(Lcd_4bit_commdport,Lcd_E_pin,dio_pin_high);
   _delay_ms(20);
   Dio_WritePin(Lcd_4bit_commdport,Lcd_E_pin,dio_pin_low);
   _delay_ms(10);
   
#endif	
}

void LCD_WriteChar      (uint8 c)
{
#if Lcd_Made == 4

Dio_WritePin(Lcd_4bit_commdport,Lcd_Rw_pin,dio_pin_low);
Dio_WritePin(Lcd_4bit_commdport,Lcd_RS_pin,dio_pin_high);
Dio_WritePin(Lcd_4bit_commdport,Lcd_E_pin,dio_pin_low);

PORTA = (c & 0xf0);

Dio_WritePin(Lcd_4bit_commdport,Lcd_E_pin,dio_pin_high);
_delay_ms(20);
Dio_WritePin(Lcd_4bit_commdport,Lcd_E_pin,dio_pin_low);_delay_ms(10);

PORTA = (c<<4);

Dio_WritePin(Lcd_4bit_commdport,Lcd_E_pin,dio_pin_high);
_delay_ms(20);
Dio_WritePin(Lcd_4bit_commdport,Lcd_E_pin,dio_pin_low);_delay_ms(10);

#endif	
}
void LCD_WriteString  (sint8* str)
{
	
	uint8 i=0;
	while(str[i]!='\0')
	{
		LCD_WriteChar(str[i]);
		i++;
	}
}
void LCD_GoTo(uint8 row,uint8 col)
{
	uint8 pos[2]={0x80,0xc0};
		
		LCD_WriteCommd(pos[row]+col);
}
void LCD_Clear              (void)
{
	    LCD_WriteCommd(0x01);

}
void LCD_WriteIntger  (sint32 num)
{
    
	sint8 str[5]={0,0,0,0,0},l=5,i=l-1,j=0;
	sint32 sum=0;
	
	if(num<0)
	{
		 sum = num & 0xbfff;
	}
	
	while(num)
	{
		while(sum)
		{
        str[i]= num % 10;
        num   = num / 10;
        i--;
		if(i==0)break;
		}
		str[i]= num % 10;
		num   = num / 10;
		i--;
	}
	if(num<0)
	{
		
		LCD_WriteChar('-');
		j=1;
	}
	
	else
	j=5-l;

	for(i=j;i<l;i++)
	{
		LCD_WriteChar(48+str[i]);
	}
}