#include<LPC21xx.H>
#include"defines.h"

void delay_millisec(u32 delay)
{
	T0PR = 60000 - 1;
	T0TCR = 0x01;
	while(T0TC<delay);
	T0TCR = 0x03;
	T0TCR = 0x00;	
}

void delay_sec(u32 delay)
{
	T0PR = 6000000 - 1;
	T0TCR = 0x01;
	while(T0TC<delay);
	T0TCR = 0x03;
	T0TCR = 0x00;	
}

void delay_microsec(u32 delay)
{
	T0PR = 60 - 1;
	T0TCR = 0x01;
	while(T0TC<delay);
	T0TCR = 0x03;
	T0TCR = 0x00;	
}

