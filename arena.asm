/*
 * IncFile1.h
 *
 * Created: 15-06-2016 15:34:03
 *  Author: Smriti Singh
 */ 


#ifndef LEFT_H_
#define LEFT_H_
#define ref 0x1A

#include <avr/io.h>

#include "Initialisation.h"  
	
unsigned char si[10];

int inti,rval;
char val,pre;

	void read(void)
	{
		
		
	
		    for(inti=0;inti<7;++inti)
            {
	           si[inti]=read_adc(inti);
			   
			   if(si[inti]<ref) 
			    {
				  sbit(val,inti);
			      rval=1;
				}
			   
			    else 
			     {
					 cbit(val,inti);
					 rval=0;
				 }
			   			  			   
			   sensor(rval,inti);
			
			}
         
		
			switch(val)
			{
				case 0B00011100 : forward(255,255); break;        		
				case 0B00011111 : lrturn(120,180);break;
				//case 0B00001100 : rrturn(120,180);break;
				case 0B00001110 : lrturn(120,180);break;
				case 0B00001111 : lrturn(120,180);break;
				case 0B00000001 : lrturn(120,180); break;
				case 0B00000011 : lrturn(120,180);break;
				case 0B00000111 : lrturn(120,180);break;
				//case 0B00000100 : rrturn(180,180);break; //
				//case 0B00000110 : lrturn(120,180);break;
				case 0B01101110 : lrturn(120,180);break;
				case 0B00101110 : lrturn(120,180);break;
				//case 0B00011110 : lrturn(120,180);break;
				case 0B00010100 : lsturn(180,120);break; ////
				case 0B00110111 : lrturn(120,180); break;
				
				
				case 0B01110000 : rrturn(180,120);break;
				case 0B01110100 : rrturn(180,120);break;
				case 0B01100000 : lsturn(180,120);break; ////
				//case 0B01000000 : lsturn(180,120);break; ////
				//case 0B00010000 :rrturn(180,120);break;
				//case 0B00110000 :rrturn(180,120);break;
				case 0B00011000 : rrturn(180,120);break;
				case 0B00111000 : rrturn(180,120);break;
				case 0B01111000 : rrturn(180,120);break;
				case 0B01110110 : rrturn(180,120);break;
				
				case 0B01100011 : lrturn(80,80); break;		//inversion
				
				case 0B01110011 : lrturn(80,80); break;
				case 0B01111001 : lrturn(80,80); break;
				case 0B01111010 : lrturn(80,80); break;
				case 0B00111111 : lrturn(80,80); break;
				case 0B01111011 : lrturn(80,80); break;
				case 0B01100001 : lrturn(80,80); break;
				case 0B01110010 : lrturn(80,80); break;
				case 0B01000010 : lrturn(80,80); break;
				
				case 0B00101111 : rrturn(80,80); break;
				case 0B01101111 : rrturn(80,80); break;
				case 0B01100111 : rrturn(80,80); break;
				case 0B01001111 : rrturn(80,80); break;
				case 0B01111110 : lsturn(80,80);break;
				case 0B01000011 : rrturn(80,80); break;
				case 0B01110111:  rrturn(80,80); break;
				case 0B00110110 : rrturn(80,80); break
				case 0B01111101 : lrturn(80,80); break;
				
				
				
				case 0B01111111 : cbit(PORTC,0);
				forward(180,180);
				_delay_ms(262);
				sbit(PORTC,0); break;			//Checkpoint
				
				case 0B01001110 : rrturn(100,100); break;  //acute turn
				case 0B01011110 : rrturn(100,100); break;
				case 0B01001100 : rrturn(100,100); break;
				case 0B01011100 : rrturn(100,100); break;
				case 0B01111100 : rrturn(100,100); break;
				case 0B01101100 : rrturn(100,100); break;
				case 0B00100000: rrturn(120,75); break;
				case 0B00100100: rrturn(100,100);break;
				case 0B01101000: lrturn(100,100); break;
				case 0B01001000: rrturn(100,100); break; 
				case 0B00010110: lrturn(100,100); break; 
				case 0B00111011  : lrturn(100,100); break;
				case 0B00011011  : lrturn(100,100); break;
				case 0B00111001  : lrturn(100,100); break;
				case 0B00111101  : lrturn(100,100); break;
				case 0B00011001  :lrturn(100,100); break;
				case 0B00011101  : lrturn(100,100); break;
				case 0B00110100: rrturn(100,100); break; 
				
				case 0B00111110: rrturn(100,100); break;
				//case 0B00111110: reverse(200,200); break;
				
				
				default: previous(pre);
				
			}
			
			pre=val;
			
		}
		

void sensor(int s,int c)
{
	
	if(s==1)
	cbit(PORTC,(7-c));
	else
	sbit(PORTC,(7-c));
}



#endif  /* INCFILE1_H_ */

void previous(int pre)
{
	
			switch(pre)
		{
			case 0B00011100 :forward(255,255);break; //forward,right & left turn
			case 0B00011111 : lrturn(120,180);break;
			//case 0B00001100 : rrturn(120,180);break;
			case 0B00001110 : lrturn(120,180);break;
			case 0B00001111 :lrturn(120,180);break;
			case 0B00000001 : lrturn(120,180); break;
			case 0B00000011 : lrturn(120,180);break;
			case 0B00000111 : lrturn(120,180);break;
			//case 0B00000100 : rrturn(180,180);break; //
			case 0B00000110 : lrturn(120,180);break;
			case 0B01101110 :  lrturn(120,180);break;
			case 0B00101110 :  lrturn(120,180);break;
			case 0B00011110 :  lrturn(120,180);break;
			case 0B00010100:  rrturn(180,120);break;
			case 0B00110111 :  lrturn(120,180); break;
			
			case 0B01110000 : rrturn(180,120);break;
			case 0B01110100 : rrturn(180,120);break;
			case 0B01100000 : rrturn(180,120);break;
			case 0B01000000 : rrturn(180,120);break;
			case 0B00010000 :rrturn(180,120);break;
			case 0B00110000 :rrturn(180,120);break;
			case 0B00011000 : rrturn(180,120);break;
			case 0B00111000 : rrturn(180,120);break;
			case 0B01111000 : rrturn(180,120);break;
			case 0B01110110 : rrturn(180,120);break;
			
			case 0B01100011 : lrturn(120,180); break;		//inversion
			
			case 0B01110011 : lrturn(100,100); break;
			case 0B01111001 :  lrturn(100,100); break;
			case 0B01111010:   lrturn(100,100); break;
			case 0B00111111:   lrturn(100,100); break;
			case 0B01111011 :   lrturn(100,100); break;
			case 0B01100001: lrturn(100,100); break;
			case 0B01110010:  lrturn(100,100); break;
			
			case 0B00101111: rrturn(100,100); break;
			case 0B01101111: rrturn(100,100); break;
			case 0B01100111 :rrturn(100,100); break;
			case 0B01001111 :rrturn(100,100); break;
			case 0B01111110:  lsturn(100,100);break;
			case 0B01000011:   rrturn(100,100); break;
			case 0B01110111: rrturn(100,100); break;
			case 0B00110110 : rrturn(100,100); break;  
			
			
			
			case 0B01111111: cbit(PORTC,0); forward(180,180);
			sbit(PORTC,0); _delay_ms(240);break;			//Checkpoint
			
			case 0B01001110 : rrturn(100,100); break;  //acute turn
			case 0B01011110 : rrturn(100,100); break;
			case 0B01001100 : rrturn(100,100); break;
			case 0B01011100 : rrturn(100,100); break;
			case 0B01111100 : lrturn(100,100); break;
			case 0B01101100 : rrturn(100,100); break;
			case 0B00100000: rrturn(120,75); break;
			case 0B00100100: rrturn(100,100);break;
			
			case 0B00111011  : lrturn(100,100); break;
			case 0B00011011  : lrturn(100,100); break;
			case 0B00111001  : lrturn(100,100); break;
			case 0B00111101  : lrturn(100,100); break;
			case 0B00011001  :lrturn(100,100); break;
			case 0B00011101  : lrturn(100,100); break;
			
			
			case 0B00111110: rrturn(100,100); break; 
			//case 0B00111110: reverse(200,200); break;

			

		}

	}










