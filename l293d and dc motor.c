#include <reg51.h>
// the control will be from a PIR motion detecctor sensor 
// and display the motion direction on an lcd

// define the pins for the l293 connection and the sensor 
sbit IN1=P0^0;
sbit IN2=P0^1;
sbit IN3=P0^2;
sbit IN4=P0^3;
sbit PIR=P1^0;

// define the pins for the lcd 
sbit rw=P3^5;
sbit en=P3^6;
sbit rs=P3^7;

//initialize function prototypes 
void clockwise(); // to turn motor clockwise
void anti_clockwise(); //to turn motor anti-clockwise
void Delay(unsigned int ); // provide a time delay
void motor_off(); // stop both motors
void lcd_cmd(unsigned char); // pass commands to control lcd
void lcd_data(unsigned char); // pass data to the lcd
void lcd_disp(); // display the data
void main(){
	P2=0x00; // initialize port for output and lcd ports declaration
	while (1){
		// Read sensor info
		if (PIR==1){
			clockwise();
			Delay(1000);
			anti_clockwise();	
		}
		else {
			motor_off();
		}	
		
		lcd_disp();
		
	}
	
}

void Delay(unsigned int x){
	unsigned int i,j;
	for(i=0; i<x; i++){
		for(j=0; j<100; j++);
		}
	}

void clockwise(){
	IN1=1;
	IN2=0;
	Delay(2000);
	IN3=1;
	IN4=0;
}

void anti_clockwise(){
	IN1=0;
	IN2=1;
	Delay(2000);
	IN3=0;
	IN4=1;
}

void motor_off(){
	Delay(1000);
	IN1=0;
	IN2=0;
	Delay(1000);
	IN3=0;
	IN4=0;
}
void lcd_cmd(unsigned char command){
	P2=command;
	rs=0;
	rw=0;
	en=1;
	Delay(100);
	en=0;

}
void lcd_data(unsigned char value){
	P2=value;
	rs=1;
	rw=0;
	en=1;
	Delay(100);
	en=0;
}
void lcd_disp(){
	 lcd_cmd(0x38);  // for using 2 lines and 5X7 matrix of LCD

   Delay(100);

   lcd_cmd(0x0F);  // turn display ON, cursor blinking

   Delay(100);

   lcd_cmd(0x01);  //clear screen

   Delay(100);

   lcd_cmd(0x81);  // bring cursor to position 1 of line 1
		
   Delay(100);
	 lcd_data('H');
	 Delay(100);
	 lcd_cmd(0xC1);
	 Delay(100);
	 lcd_data('I');
	 Delay(100);

//	unsigned char name[]="SAMWEL";
//	int i=0;
//	for (i=0;i<6;i++){
//		lcd_data(name[i]);
//	}
}