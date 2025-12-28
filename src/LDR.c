#include<LPC21xx.H>
#include"defines.h"

#define EINT0 14
#define int_en 1<<5
#define led1 1<<19


int toggle=1;
volatile CAN2_MSG m1;

void init_interrupt(void);

void headlight(void) __irq
{
	EXTINT = 0x01;

	if(toggle==1)
	{
		IOSET0=led1;	   // tur on light after it too dark 
		toggle=0;
	}
	else
	{	IOCLR0=led1;		   // tur off light in morning
		toggle=1;
	}

	EXTPOLAR^=(1<<0);//select raising edge

	VICVectAddr=0x00;
} 

int main()
{
	m1.id=1;
	m1.rtr=0;//data frame
	m1.dlc=4;
	m1.byteA=0;
	m1.byteB=0;		

	IODIR0 = led1;

	init_interrupt();
	can2_init();

	while(1)
	{
		m1.byteA=toggle;
		can2_tx(m1);
		delay_millisec(500);	
	}
}

void init_interrupt(void)
{
	PINSEL1 = 0x01;//p0.16 as EXTINT0
	VICIntSelect = 0;//All are vectored IRQS
	VICVectCntl0 = int_en|EINT0;//allocate slot 0 for Extrnl interrupt 0
	VICVectAddr0 = (int)headlight;
	EXTMODE = 0x01;//select edge sensitivity
	EXTPOLAR = 0x00;//select falling edge
	VICIntEnable = 1<<EINT0; 
}
