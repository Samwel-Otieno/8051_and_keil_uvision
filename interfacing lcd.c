// Program for LCD Interfacing with 8051 Microcontroller


#include<reg51.h>

#define display_port P2      //Data pins connected to port 2 on microcontroller

sbit rs = P3^2;  //RS pin connected to pin 2 of port 3

sbit rw = P3^3;  // RW pin connected to pin 3 of port 3

sbit e =  P3^4;  //E pin connected to pin 4 of port 3


void msdelay(unsigned int time)  // Function for creating delay in milliseconds.

{

    unsigned i,j ;

    for(i=0;i<time;i++)    

    for(j=0;j<1275;j++);

}

void lcd_cmd(unsigned char command)  //Function to send command instruction to LCD

{

    display_port = command;

    rs= 0; // set register select pin to command mode

    rw=0; // set read/write pin to write mode

    e=1; // set the enable pin to high

    msdelay(1);

    e=0; // set enable pin to low

}


void lcd_data(unsigned char disp_data)  //Function to send display data to LCD

{

    display_port = disp_data;

    rs= 1; // set register select pin to data mode

    rw=0; // set read/write pin to write mode

    e=1; // set enable pin to high

    msdelay(1);

    e=0; // set enable pin to low

}


 void lcd_init()    //Function to prepare the LCD  and get it ready

{

    lcd_cmd(0x38);  // for using 2 lines and 5X7 matrix of LCD

    msdelay(10);

    lcd_cmd(0x0F);  // turn display ON, cursor blinking

    msdelay(10);

    lcd_cmd(0x01);  //clear screen

    msdelay(10);

    lcd_cmd(0x81);  // bring cursor to position 1 of line 1
		
    msdelay(10);

	/*
Hex Code == Command to LCD Instruction Register

0F == LCD ON, cursor ON

01 == Clear display screen

02 == Return home

04 == Decrement cursor (shift cursor to left)

06 == Increment cursor (shift cursor to right)

05 == Shift display right

07 == Shift display left

0E == Display ON, cursor blinking

80 == Force cursor to beginning of first line

C0 == Force cursor to beginning of second line

38 == 2 lines and 5×7 matrix

83 == Cursor line 1 position 3

3C == Activate second line

08 == Display OFF, cursor OFF

OC == Display ON, cursor OFF

C1 == Jump to second line, position 1

C2 == Jump to second line, position 2
*/
}

void main()

{

    unsigned char a[]="@SAM_HALISI";    //string of characters with a null terminator.

    int l=0;

    lcd_init();

    while(a[l] != '\0') // searching the null terminator in the sentence

    {

        lcd_data(a[l]);

        l++;

        msdelay(50);

    }

}