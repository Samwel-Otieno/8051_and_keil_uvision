#include<reg52.h>

void main(){
	P0=0XFF;
	while(1){
		P1=P0^0X0F;
	}

} 