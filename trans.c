#include<reg51.h>

void main(){
	unsigned char temp;
	P1=0xFF;
	while(1){
		temp=P1;
		temp <<=1;
		P2=temp;
	}
}