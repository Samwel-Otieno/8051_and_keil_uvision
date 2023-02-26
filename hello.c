#include<reg51.h>
#include<stdio.h>

//THIS PROGRAM PRINTS HELLO ON THE MONITOR

void delay_time(unsigned int);
void main(){
	SCON = 0x50; //serial mode 1, 8-bit UART,
	// baud rate set by timer 1, enable rcvr
	TMOD |= 0x20;//timer 1 in mode 2, 8-bit auto-reload
	TH1 = 2; //reload value for timer 1 1200 baud
	TR1 = 1; //run timer 1
	TI = 1; //set for interrupt,
	//send first char of UART
	while(1){
		printf("Hello \n");
		delay_time(2000);
		
	}
}

void delay_time(unsigned int x){
	unsigned int i,j;
	for(i=0; i<=x;i++){
		for(j=0; j<=100; j++);
	}
}