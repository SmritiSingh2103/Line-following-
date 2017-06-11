/*
 * IncFile2.h
 *
 * Created: 14-09-2016 12:40:25
 *  Author: Smriti Singh
 */ 


#ifndef LMOTOR_H_

#define LMOTOR_H_

//#include "Initialisation.h"
//#include "left.h"
#include <avr/io.h>


void forward(int m0,int m2)
{
	
OCR0=m0;
OCR2=m2;	
	
sbit(PORTD,5);
cbit(PORTD,4);

cbit(PORTD,6);  //Right motor
sbit(PORTD,3);

}


void stop()
{
	
	OCR0=0;
	OCR2=0;

	cbit(PORTD,5);
	cbit(PORTD,4);
	
	cbit(PORTD,6);
	cbit(PORTD,3);
} 

void reverse( )
{
	OCR0= 180;
	OCR2=170 ;
	
	cbit(PORTD,5);
	sbit(PORTD,4);

	sbit(PORTD,6);  //Right motor
	cbit(PORTD,3);
}

void rleft( )
{
	OCR0=0  ;
	OCR2= 0 ;
	
	sbit(PORTD,5);
	cbit(PORTD,4);

	sbit(PORTD,6);
	cbit(PORTD,3);

}

void rright( )
{
	OCR0=  0;
	OCR2= 0 ;
	
	sbit(PORTD,5);
	cbit(PORTD,4);

	sbit(PORTD,6);
	cbit(PORTD,3);

}


void left()
{
	
OCR0=75;
OCR2=150;

sbit(PORTD,5);
cbit(PORTD,4);
	
cbit(PORTD,6);
sbit(PORTD,3);
	
}
void leftmore()
{
	
	OCR0=20;
	OCR2=150;

	cbit(PORTD,5);
	sbit(PORTD,4);
	
	cbit(PORTD,6);
	sbit(PORTD,3);
	
}

void left90()
{
	OCR0=150 ;
	OCR2=150  ;
	
cbit(PORTD,5);                  
sbit(PORTD,4);

cbit(PORTD,6);                  
sbit(PORTD,3);	

}

void right()
{
	OCR0=150;
	OCR2=75;
	
	sbit(PORTD,5);
	cbit(PORTD,4);
	
	cbit(PORTD,6);
	sbit(PORTD,3);
	
}



void right90()
{
	OCR0=150;
	OCR2=150;
	
	sbit(PORTD,5);
	cbit(PORTD,4);

	sbit(PORTD,6);
	cbit(PORTD,3);

}

#endif /* INCFILE2_H_ */
