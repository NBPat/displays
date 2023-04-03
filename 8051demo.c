#include <reg51.h>		// provided by SDCC 
#define reps 3
void DELAY_ms(unsigned int ms_Count)
{   int i,j;			    // wait loop, not precise
    for(i=0;i<ms_Count;i++) {for(j=0;j<100;j++);  }}
int main() {
    while(1)
    {	
	// decimal version of P1 = 1 then P1 = 0
	P1 = 1;  			DELAY_ms(500);		    // led on
	P1 = 0;   			DELAY_ms(500);		  // led off
	// decimal version of P1 = 255 then P1 = 0
	P1 = 255;  			DELAY_ms(500);	
	P1 = 0;   			DELAY_ms(500);
	// binary version of P1 = 1 then P1 = 0
	P1 = 0b00000001;  	DELAY_ms(500);	// led on
	P1 = 0b00000000;   	DELAY_ms(500);	// led off	
	// binary version of P1 = 255 then P1 = 0	
	P1 = 0b11111111;  	DELAY_ms(500);	
	P1 = 0b00000000;   	DELAY_ms(500);	
	// hexadecimal version of P1 = 1 then P1 = 0
	P1 = 0x01;  		DELAY_ms(500);		  // led on
	P1 = 0x00;   		DELAY_ms(500);		  // led off	
	// hexadecimal version of P1 = 255 then P1 = 0
	P1 = 0xFF;  		DELAY_ms(500);		  // led on
	P1 = 0x00; 			DELAY_ms(500);		  // led off	
		
	// shifts single bit from P1.0 to P1.7
	for (int j=0;j < reps;j++) {			
	for (int i=0; i < 8 ;i++) { P1 = (1<<i); DELAY_ms(400);}
	for (int i=0; i < 8 ;i++) { P1 = (128>>i); DELAY_ms(400);}
}
	// masking of bits with |= and &= operators
	for (int j=0;j < reps;j++) {
	P1 |= 0b00000001;  DELAY_ms(500);		// mask to force P1.0 = 1
	P1 &= 0b11111110;  DELAY_ms(500);		// mask to force P1.0 = 0
	}
	// alternate pattern
	for (int j=0;j < reps;j++) {
	P1 = 0x55;  DELAY_ms(900);				  // P1 = 0b01010101
	P1 = 0xAA;   DELAY_ms(900);			    // P1 = 0b10101010
	}
	// mathematical inverse of P1 is put into P1  
	for (int j=0;j < reps;j++) {
	P1 = !P1; DELAY_ms(950);
    }}}
	
