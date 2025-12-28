#include "defines.h"
#include<LPC21xx.H>

main(){
	u32 D;
	u32 s;	
	CAN2_MSG m1;
	can2_init();
	LCD_init();
	while(1)
	{
		can2_rx(&m1);
		switch(m1.id)
		{
			case 1:
				{   
					LCD_command(0x80);
					if(m1.byteA==1)
						LCD_str("light on ");
					else
						LCD_str("light off");
					delay_millisec(500);
					break;
				}
			case 2:
				{
					D=m1.byteA;
					if((D>=0)&&(D<=5))
						D=95;
					else if(((D>=5)&&(D<=10)))
						D=75;
					else if(((D>=10)&&(D<=15)))
						D=50;
					else if(((D>=15)&&(D<=20)))
						D=25;
					else if(((D>=20)&&(D<=25)))
						D=10;
					else
						D=0;
					LCD_command(0xc0);
					LCD_str("F=");	  
					LCD_integer(D);	  
					LCD_str("%");
					delay_millisec(500);
					break;
				} 
			case 3:
				{
					s=m1.byteA;					  
					LCD_command(0xc8);	  
					LCD_integer(s);
					LCD_str("km/hr");
					delay_millisec(500);
					break;
				}	
		} 				
	}
}
