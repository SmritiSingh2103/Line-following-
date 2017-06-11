

#ifndef SENSING_H_
#define SENSING_H_


#include <avr/eeprom.h>

uint8_t overall;

void readvalues()
{
	overall = 0;
	uint8_t temp;
	int i ,j;
	
	for (j = 0; j<5; j++)
	{
		 temp = read_adc(j);
		if (temp < eeprom_read_byte(ref[j]))
		{
			sbit(overall, j);
			cbit(PORTC, 5-j);
		}
		
		else
		{
			cbit(overall,j);
			sbit(PORTC, 5-j);
		}
	}
	
	
}

void linesens()
{
	uint8_t temp;
	temp = overall & 0B01110;
	if ( temp == 0B01110)
	forward(150, 190);
	else if (temp == 0B00010)
	right();
	else if (temp == 0B00110)
	right();
	
	else if (temp == 0B1000)
	left();
	else if (temp == 0B01100)
	left();
	
}
void linesens2()
{
	if ( overall == 0B00100)
	forward(150, 200);
	else if (overall == 0B00110)
	right();
	else if (overall == 0B00010)
	right();
	else if (overall == 0B00001)
	right();
	else if (overall == 0B01100)
	left();
	else if (overall == 0B01000)
	left();
	else if (overall == 0B10000)
	leftmore();
	else if (overall == 0B00000)
	left();
	
	
}


void read1()
	{
		readvalues();
		
		while(overall & 0B10001) {
			forward(150,180);
			readvalues();
		}
		
		
	while(!(overall & 0B00001))
	{
		linesens();
		readvalues();
	}
	while((overall & 0B00001))
	{
		linesens();
		readvalues();
	}
	while(!(overall & 0B00001))
	{
		linesens();
		readvalues();
	}
	while((overall & 0B00001))
	{
		linesens();
		readvalues();
	}
	
// 	while(!(overall & 0B00001))
// 	{
// 	   linesens();
// 	   readvalues();
// 	  
// 		}
		forward(150,180);
		_delay_ms(850);
		 stop();
		 while (!(overall & 0B00001))
		 { 
			 reverse();
			 readvalues();
		 }
		
		 forward(180,140);	
		 _delay_ms(400); 
		 readvalues();
		 
// 		 while((overall & 0B10000))
// 		 {
// 			 
// 			 right90();
// 			 readvalues();
// 		 }
		 while(!(overall & 0B10000))			//10000
		 {
			 
			 right90();
			 readvalues();
		 }
		  while((overall & 0B10000))
		  {
			  
			  right90();
			  readvalues();
		  }
		   while(!(overall & 0B00100))
		   {
			   
			   right90();
			   readvalues();
		   }
		  while(!(overall & 0B10000)){
			  linesens();
			  readvalues();
		  }
		  
		   while((overall & 0B10000)){
			   linesens();
			   readvalues();
		   }
		    while(!(overall & 0B10000)){
			    linesens();
			    readvalues();
		    }
			 while((overall & 0B10000)){
				 linesens();
				 readvalues();
			 }
			  while(!(overall & 0B10000)){
				  linesens();
				  readvalues();
			  }
			  while((overall & 0B10000)){
				  linesens();
				  readvalues();
			  }
			  while(!(overall & 0B10000)){
				  linesens();
				  readvalues();
			  }
			  while((overall & 0B10000)){
				  linesens();
				  readvalues();
			  }
			  
			  forward(170,180);
			  _delay_ms(850);
			 
			  
			   while (!(overall & 0B10000))
			   { 
				   reverse();
				   readvalues();
			   }
			   
			   forward(150,180);
			   _delay_ms(400);
			   readvalues();
			   			   
			   while(!(overall & 0B00001))
			   {
				   
				   left90();
				   readvalues();
			   }
			   while((overall & 0B00001))
			   {
				   
				   left90();
				   readvalues();
			   }
			   while(!(overall & 0B00100))
			   {
				   
				   left90();
				   readvalues();
			   }
			   while(overall & 0B10000){
				   linesens();
				   readvalues();
			   }
			   
			   
			   
// 			     while((overall & 0B00001)){
// 						right90();
// 				     readvalues();
// 			     }
			   while(!(overall & 0B10000)){
				  reverse();
				   readvalues();
			   }
			   
			   _delay_us(150);
			   left90();
			   
			  
				 while(!(overall & 0B00001))
				 {
					 
					 left90();
					 readvalues();
				 }
				 
				 while((overall & 0B00001))
				 {
					 
					 left90();
					 readvalues();
				 }
// 				  while(!(overall & 0B00001))
// 				  {
// 					  
// 					  left90();
// 					  readvalues();
// 				  }
				  while(overall == 0B00000)
				  forward(150,180);
				  
				  while((overall & 0B00001))
				  {
					  
					  right();
					  readvalues();
				  }
				 while(!(overall & 0B00100))
				 {
					 
					linesens();
					 readvalues();
				 }
				
				 while(!(overall & 0B00001)){
					 linesens();
					 readvalues();
				 }
				
				  while((overall & 0B00001)){
					  linesens();
					  readvalues();
				  }
				   while(!(overall & 0B00001)){
					   linesens();
					   readvalues();
				   }
				    while((overall & 0B00001)){
					    linesens();
					    readvalues();
				    }
					 while(!(overall & 0B00001)){
						 linesens();
						 readvalues();
					 }
					 while((overall & 0B00001)){
						 linesens();
						 readvalues();
					 }
					  while(!(overall & 0B00001))
					  {
						  
						  left90();
						  readvalues();
					  }
					  while((overall & 0B00001))
					  {
						  
						  left90();
						  readvalues();
					  }
					  while(!(overall & 0B00100))
					  {
						  
						  left90();
						  readvalues();
					  }
					   while(!(overall & 0B10000)){
						   linesens();
						   readvalues();
					   }
					   while((overall & 0B10000)){
						   linesens();
						   readvalues();
					   }
					    while(!(overall & 0B10000)){
						    linesens();
						    readvalues();
					    }
					    while((overall & 0B10000)){
						    linesens();
						    readvalues();
					    }
												 						
						 forward(150,180);
						 _delay_ms(1000);
						 stop();
						 
						  while (!(overall & 0B10000))
						  {
							   reverse();
							  readvalues();
						  }
						  
						  forward(150,180);
						  _delay_ms(400);
						   readvalues();
						   
						  while(!(overall & 0B00001))
						  {
							  
							  left90();
							  readvalues();
						  }
						  while((overall & 0B00001))
						  {
							  
							  left90();
							  readvalues();
						  }
						  while(!(overall & 0B00100))
						  {
							  
							  left90();
							  readvalues();
						  } 
						  
						   while(!(overall & 0B00001)){
							   linesens();
							   readvalues();
						   }
						   while((overall & 0B00001)){
							   linesens();
							   readvalues();
						   }
						   
						    while(!(overall & 0B00001)){
							    linesens();
							    readvalues();
						    }
						    while((overall & 0B00001)){
							    linesens();
							    readvalues();
						    }
							
							while(!(overall & 0B00100)) {
								right90();
								readvalues();
							}
							 while(!(overall & 0B00001)){
								 linesens2();							//linesense can also be used?
								 readvalues();
							 }
							  while((overall & 0B00001)){
								  linesens2();
								  readvalues();
							  }
							  
							  while(!(overall & 0B00100)) {
								  right90();
								  readvalues();
							  }
							  
							 while(overall) {
								 linesens();
								 readvalues();
							 }
							  
										 
				
			   
		while(1){}
		
	}
	
	
	
	
		
		
		
		



#endif  /* SENSING_H_ */
