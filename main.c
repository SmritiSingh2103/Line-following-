
#define F_CPU 8000000UL
#include <avr/io.h>


#include "Initialisation.h"
#include "calibrate.h"
#include "left.h"
#include "Lmotor.h"


int main()
{
    
    //unsigned char s[10]; 
   // int a,i;
	
   	
	port();
	timer();
	analog();
	comm();
	
	sbit(PORTB,0);
 OCR0=200;
 OCR2=240;
	   char c;

while(1)
{
	//sbit(PORTB,0);
	//_delay_ms(500);
	
	
	c= PINC & (0B10000000);                               //Checking the State of Calib Switch
	if (c)
	{
		calib();
	}
	else
	{
		//readvalues();
	//	linesens();
			read1();
			break;
		 
	}
		
}

   	 	
	return 0;
	
}

