#ifndef LCD_H
#define LCD_H

#include "lcdcfg.h"
#include <util/delay.h>

void LCD_Init               (void);
void LCD_WriteCommd    (uint8 cmd);
void LCD_WriteChar       (uint8 c);
void LCD_WriteString  (sint8* str);
void LCD_GoTo(uint8 row,uint8 col);
void LCD_Clear              (void);
void LCD_WriteIntger  (sint32 num); // l=lengh of num 


#endif
