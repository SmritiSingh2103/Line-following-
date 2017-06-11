/*
 * IncFile2.h
 *
 * Created: 02-07-2016 15:52:31
 *  Author: user
 */ 


#ifndef CALIBRATING_H_
#define CALIBRATING_H_

#include <avr/eeprom.h>
//#include "Initialisation.h"
//#include "left.h"

uint8_t ref1[5];
uint8_t *ref[5];
uint8_t *white[5];
uint8_t *dark[5];

void calibinit(){
	int k;
	for (k=16;k<24;k++)
		white[k-16]=k;
	for (k=24;k<32;k++)
		dark[k-24]=k;
	for (k=0;k<8;k++)
		ref[k]=k;
}
void whitestart(){                                      //White Calibration
	unsigned char i;
	unsigned char in[5];
	
	
	                                  //Trans-LED On
	for (i=0;i<5;i++)
	{   
		/*cbit(PORTB,0);*/
		in[i] = read_adc(i);
		eeprom_write_byte(white[i],in[i]);
	
	}
// 	_delay_ms(100);
// 	
// 	                                    //Trans-LED Off
//  	for (i=0;i<7;i++)
//  	{
//  		sbit(PORTB,0); 
//  		in[i] = in[i] - read_adc(i);
//  		eeprom_write_byte(white[i],in[i]);	}
// 	_delay_ms(100);
// }
}
void darkstart(){                                      //Black Calibration
	unsigned char i;
	unsigned char in[5];
	//cbit(PORTB, 0);                                    //Trans-LED On
	for (i=0;i<5;i++)
	{
		in[i] = read_adc(i);
		eeprom_write_byte(dark[i],in[i]);
	}
//  _delay_ms(100);
// 	sbit(PORTB, 0);                                    //Trans-LED Off
// 	for (i=0;i<7;i++)
// 	{in[i] = in[i] - read_adc(i);
// 		eeprom_write_byte(dark[i],in[i]);
// 	}
// 		_delay_ms(100);
}
void calibrate(){
	
     cbit(PORTC,0); 
	 _delay_ms(2000);                                //Ref Calculation and Storing 
	uint8_t i,temp_ref[5];
	for (i=0;i<5;i++)
	{	temp_ref[i] = eeprom_read_byte(white[i]) + eeprom_read_byte(dark[i]);
		temp_ref[i] = temp_ref[i] / 2;
		eeprom_write_byte(ref[i],temp_ref[i]);
	}
}
void calib(){ 
	                                          //Checking state of the White and Black Switches
	calibinit();
	char con, wh, bl;
		con = PINC & (0B10000000);
	while(con){
		con = PINC & (0B10000000);
	/*	sbit(PORTB, 0);*/
		wh = PIND & (0B00000001);
		bl = PIND & (0B00000010);
		if(wh)
			{
                cbit(PORTC,2);
				whitestart();
			}
			
		if (bl)
			{
			    cbit(PORTC,3);	
				darkstart();
			}
	
	
	
	}	
	calibrate();
}
					
							
									
			




#endif 
