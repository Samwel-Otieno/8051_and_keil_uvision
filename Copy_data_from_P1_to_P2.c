#include<reg51.h>

unsigned int temp;
void Delay_wait(unsigned int);

void main(void){
	while(1){	
	P1=0xFF; // set port 1 to read mode 
	P1=0x7F; // set the value of P1 to 127decimal
	
	while(P1 > 0){ // loop untill the value of P1 drops to zero
		Delay_wait(30); // delay wait for 30miliseconds
		P2=P1; //copy the value of P1 into P2 (read P1 and write to P2)
		temp=P2; // copy the value of P2 into a temporary memory holder
		temp>>=1; // divide the value of temp by half using right shift
		P1=temp; // write the value of temp back into P1
	}
	}
}

void Delay_wait(unsigned int x){ // write the time delay function 
	unsigned int i,j;
	for(i=0; i<=x; i++){
		for(j=0; j<=100; j++);
	}
}