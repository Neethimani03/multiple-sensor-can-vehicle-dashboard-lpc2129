#include<LPC21XX.H>
#include"defines.h"
#define INPUT2 1<<9

void pwm_init(void)
{
	PINSEL0|=0x00020000;//p0.8 as PWM4 
	IODIR0|=INPUT2;//p0.9 as O/P pin
	PWMMR0=6000-1;//set count for period register 
	PWMMR4=0;//set duty cycle for PWM4
	PWMMCR=0x00000003;//PWMTC=0;if TC count reaches period value
	PWMPCR=0x00001000;//O/P PWM 4 Enabled
	PWMTCR=0x00000009;//counter and PWM mode Enabled
	PWMLER=0x00000010;//latch the duty cycle value for PWM 4 
}

int main()
{	
	u32 count = 4200;
	u32 n=5;

	CAN2_MSG m1;

	can2_init();
	pwm_init(); 
	LCD_init();

	m1.id=3;
	m1.rtr=0;//data frame
	m1.dlc=4;
	m1.byteB=0;

	while(1)
	{
		while(((IOPIN0>>14) & 1)!=0);
		delay_millisec(250);
		while(((IOPIN0>>14) & 1)==0);
		count+=50;
		if(count>5999)
		{
			count=4200;
			n=0;
		}
		PWMMR4=count;
		PWMLER=0x00000010;//relatch the value
		n+=5;
		m1.byteA=n;
		can2_tx(m1);//data-frame

		delay_millisec(500);
	}
}
