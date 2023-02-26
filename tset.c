#include <reg51.h>
#define disp P2
sbit sw=P1^0;
void main(){
	unsigned char x,y;
	unsigned int i;
	disp=0x00;
	while(1){
		y=0x01;
		if(sw==0){
			for(x=0;x<4;x++){
				disp=y;
				for(i=0;i<500;i++);	
				y <<= 1;
		}
		}
		
	}
}