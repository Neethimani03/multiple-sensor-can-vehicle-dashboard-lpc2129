#include<LPC21xx.H>
#include"defines.h"

void LCD_init(void)
{
	IODIR0|=LCD_D|RS|E;//p0.4 to p0.9 as output pin
	LCD_command(0x01);//clear lcd command
	LCD_command(0x02);//return to home space
	LCD_command(0x0c);//display on
	LCD_command(0x28);//4 bit interfacing wid 2 lines
	LCD_command(0x80);//select the starting address of LCD
}

void LCD_command(u8 cmd)
{
	IOCLR0=LCD_D;//clear p0.4 to p0.7 
	IOSET0=(cmd&0xf0)<<0;//passing command in 4 bits	
	IOCLR0=RS;//enable command register
	IOSET0=E;//latch the data
	delay_millisec(2);//2 ms delay
	IOCLR0=E;//to relatch the nxt cycle
	IOCLR0=LCD_D;//clear p0.4 to p0.7
	IOSET0=(cmd&0x0f)<<4;//passing command in 4 bits
	IOCLR0=RS;//enable command register
	IOSET0=E;//latch the data
	delay_millisec(2);//2 ms delay
	IOCLR0=E;//to relatch the nxt cycle
}

void LCD_str(u8 *s)
{  
	while(*s)
		LCD_data(*s++);
}  

void LCD_data(u8 d)
{
	IOCLR0=LCD_D;//clear p0.4 to p0.7
	IOSET0=(d&0xf0)<<0;//passing data in 4 bits
	IOSET0=RS;//enable data register
	IOSET0=E;//latch the data on the data bits
	delay_millisec(2);//2 ms delay
	IOCLR0=E;//to relatch the nxt cycle
	IOCLR0=LCD_D;//clear p0.4 to p0.7
	IOSET0=(d&0x0f)<<4;//passing data in 4 bits 
	IOSET0=RS;//enable data register
	IOSET0=E;//latch the data on the data bits
	delay_millisec(2);//2 ms delay
	IOCLR0=E;//to relatch the nxt cycle
}

#include <stdio.h>

void LCD_integer(u32 num)
{
	u8 buf[10];
	sprintf(buf,"%d",num);
	LCD_str(buf);
}

void LCD_hex(u32 num)
{
	u8 buf[10];
	sprintf(buf,"%X",num);
	LCD_str(buf);
}


