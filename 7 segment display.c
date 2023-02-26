#include <reg51.h>

void delay_time(unsigned int);
void main(){
	//define an array for the hexadecimal equivalent of 0-9 for 7 segment
	unsigned char seg[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80, 0x90};
	unsigned x; // variable for loop repetition
	P1=0x00; // set port 1 as output
	while(1){
		// pass the values to the segment display 
		for(x=0;x<10;x++){
			P1=seg[x];
			delay_time(1000);
		}
	
	}
}

void delay_time(unsigned int time){
	unsigned int i,j;
	for (i=0; i<time;i++)
	for (j=0; j<100; j++);
}

