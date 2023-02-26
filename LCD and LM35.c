#include <reg51.h>
#include <intrins.h>

sbit sda=P2^1;  // i2c data line
sbit scl=P2^0;  // i2c clock line

//The LCD control pins
sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;

//B sfr register individual bits
sbit a0=B^0;
sbit a1=B^1;
sbit a2=B^2;
sbit a3=B^3;
sbit a4=B^4;
sbit a5=B^5;
sbit a6=B^6;
sbit a7=B^7;

// Initialize functions 
void start(); // a function to start i2c communication
void stop(); // stop communication 
void check(); // to verify acknowledgement from slave to master
void delay(); // time for canvasing and reading values from adc
void conversion(unsigned char ); // for adc in hexadecimal form 
void write(unsigned char); //to pass bit data from master to slave
unsigned char read(); // pass data from slave to master data from adc
void ack(); // acknowledge receipt of data from master to slave
void disp(unsigned char *); // display text on screen
void enable(); //enable line during looping
unsigned char v; //temporary variable to store value from adc

void main(){
	unsigned char com[4]={0x38, 0x10, 0x0e, 0x80}, s1; // LCD display parameters
	for(s1=0;s1<4;s1++){ // a for loop to initalize the LCD screen
		P3=com[s1];
		rs=0;
		rw=0;
		enable();
	}
	disp("TEMPERATURE: ");
	start(); // start the i2c communication
	write(0x90); // set the slave adress of the i2c device in write mode
	check(); //acknowledgement check
	write(0x00); // control byte for channel 0 of adc
	check();
	start(); // restart
	write(0x91); // set read mode
	check();
	
	while(1){ // read the adc data continuosly and display on the screen
		v=read();
		ack();
		conversion(v);
		stop();
	}
}

void start(){
	// the i2c rule to intiate communication by setting scl and sda high
	scl=1;
	sda=1;
	_nop_();_nop_(); // no operation functions they provide a 1us delay
	sda=0;
	scl=0;
}

void write(unsigned char val){
	unsigned char v1,v2,v3=0x80;
	v2=val;
	for(v1=0;v1<8;v1++){
		sda=v2&v3; //logical bitwise AND operation
		scl=1;
		_nop_();_nop_();
		scl=0;
		v2=v2<<1;
	}
}

void check(){
	bit c;
	scl=1;
	c=sda;
	for(v=0;v<12;v++);
	scl=0;
	if(c==1){
		stop();
	}
}

void stop(){
	scl=1;
	sda=0;
	_nop_();_nop_(); // no operation functions they provide a 1us delay
	sda=1;
	scl=0;
}

void enable(){
	unsigned int s2;
	en=1;
	for(s2=0;s2<2000;s2++);
	en=0;
}

void disp(unsigned char *s){
	unsigned char s3;
	for(s3=0;s[s3]!='\0';s3++){
		P3=s[s3];
		rs=1;
		enable();
	}
}
unsigned char read(){
	sda=1;
	a7=sda; //msb bit of b register
	scl=1;
	_nop_();_nop_(); // no operation functions they provide a 1us delay
	scl=0;
	a6=sda;
	scl=1;
	_nop_();_nop_();
	scl=0;
	a5=sda;
	scl=1;
	_nop_();_nop_();
	scl=0;
	a4=sda;
	scl=1;
	_nop_();_nop_();
	scl=0;
	a3=sda;
	scl=1;
	_nop_();_nop_();
	scl=0;
	a2=sda;
	scl=1;
	_nop_();_nop_();
	scl=0;
	a1=sda;
	scl=1;
	_nop_();_nop_();
	scl=0;
	a0=sda; // lsb of b register
	scl=1;
	_nop_();_nop_();
	scl=0;
	v=B;
	return v;
}

void ack(){
	sda=0;
	scl=1;
	_nop_();_nop_(); // no operation functions they provide a 1us delay
	scl=0;
}

void conversion(unsigned char val){
	unsigned char s4,s5,s6;
	s4=val;
	s5=s4/10;
	s6=s4%10;
	s5=s5|0x30;
	s6=s6|0x30;
	P3=0x8b;
	rs=0;
	enable();
	P3=s5;
	rs=1;
	enable();
	P3=s6;
	enable();	
}