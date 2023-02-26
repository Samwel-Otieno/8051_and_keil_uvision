#include<reg51.h>

void main(){
	unsigned char x,y; // char variables for toggling LED 
	unsigned int i; // delay variable 
	
	P1=0x00; // configure port 0 for output
	while(1){
		x=0x01;  // initialize the value of x to 1
		for(y=0; y<8; y++){				// a for loop to toggle LEDs one by one
			P1=x; // assign the value of x to port 1
			for(i=0; i<=20000; i++); //a simple delay for loop
			x <<= 1; // left shift the value of x i.e multiply it by 2
		}
	}
}