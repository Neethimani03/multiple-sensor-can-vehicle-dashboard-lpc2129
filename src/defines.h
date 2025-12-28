/*lcd defines*/

#define LCD_D 0x0f<<4
#define RS 1<<8
#define E 1<<9

/*ultrasonic defines*/

#define trig 1<<2
#define echo 1<<3
#define speed 34
#define echo_status (IOPIN0 & echo)

/*datatypes alias names*/

typedef unsigned int u32;
typedef unsigned char u8;
typedef signed   char s8;
typedef unsigned short u16;
typedef signed   short s16;
typedef unsigned int  u32;
typedef signed   int  s32;
typedef float  f32;
typedef double f64;

/*CAN data frame structure*/

typedef struct CAN2
{
	u32 id;
	u32 rtr;
	u32 dlc;
	s32 byteA;
	u32 byteB;
}CAN2_MSG;

/*CAN function defines*/

void can2_init(void);
void can2_tx(CAN2_MSG);
void can2_rx(CAN2_MSG*);

/*delay function defines*/

void delay_millisec(u32);
void delay_sec(u32);
void delay_microsec(u32);

/*ultrasonic function defines*/

void ultrasonic_init(void);
u32 distance(void);
void transmit_sound(void);
u32 receive_echo(void);

/*lcd function defines*/

void LCD_init(void);
void LCD_command(u8);
void LCD_data(u8);
void LCD_str(u8*);
void LCD_integer(u32 num);
void LCD_hex(u32 num);



