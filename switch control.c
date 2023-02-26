#include <reg51.h>
sbit LED=P1^4; // CONNECT LED TO PIN 4 OF PORT 1
sbit SW=P1^1;  // CONNECT SWITCH TO PIN 1 OF PORT 1
int main(){
	while(1){
		
		if(SW==0){
			LED=1;
		}
		else{
			LED=0;
		}
	}
}
