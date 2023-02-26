#include <reg51.h>
void timedelay(unsigned int time);
sbit sw=P1^0;
sbit ledg=P2^0;
sbit ledr=P2^1;
sbit ledb=P2^2;
int main(){
	while(1){
		if(sw==0){
			ledg=1;
			timedelay(500);
			ledr=1;
			timedelay(500);
			ledb=1;
		}
		else{
			ledg=0;
			timedelay(500);
			ledr=0;
			timedelay(500);
			ledb=0;
		}
		
	}
}
void timedelay(unsigned int time){
	unsigned int i,j;
	for(i=0; i<=time; i++){
		for(j=0; j<=100; j++);
		}
	}