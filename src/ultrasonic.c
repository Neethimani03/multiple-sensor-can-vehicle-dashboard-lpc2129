#include<LPC21xx.H>
#include"defines.h"

int main()
{	
	u32 D;
	CAN2_MSG m1;
	m1.id=2;
		m1.rtr=0;//data frame
		m1.dlc=4;
	can2_init();
	ultrasonic_init();
	while(1)
	{
		D=distance()/1000;
		m1.byteA =D;//sent fuellevel data 
	
		can2_tx(m1);//data-frame
		delay_millisec(500);
	}
}

void ultrasonic_init()
{
	IODIR0 = trig;
	IOCLR0 = trig;
	VPBDIV = 0x01;
	T1TCR = 0x00;	
}

u32 distance(void)
{	
		u32 time;
		transmit_sound();
		time = receive_echo();
		T1TCR = 0x03;
		T1TCR = 0x00;
		if(time < 38000)
			time = (time * speed) / 2;
		else 
			time = 0;
			return time;
}

void transmit_sound(void)
{
	T1PR = 60-1;
	T1PC = T1TC	= 0;	
	IOSET0 = trig;
	delay_microsec(10);
	IOCLR0 = trig;
}

u32 receive_echo(void)
{
		while(!echo);
		T1TCR = 0x01;
		while(echo);
		T1TCR = 0x00;
		return T1TC;	
}
