#define reps 3
#include <avr/io.h>
#include <util/delay.h>
int main() {while(1){ DDRB = 0xFF;  // really needed to add this
  // decimal version of PORTB = 1 then PORTB = 0
  PORTB = 1;       _delay_ms(5000);        // led on
  PORTB = 0;         _delay_ms(5000);      // led off
  // decimal version of PORTB = 255 then PORTB = 0
  PORTB = 255;       _delay_ms(5000);  
  PORTB = 0;         _delay_ms(5000);
  // binary version of PORTB = 1 then PORTB = 0
  PORTB = 0b00000001;    _delay_ms(5000);  // led on
  PORTB = 0b00000000;    _delay_ms(5000);  // led off  
  // binary version of PORTB = 255 then PORTB = 0 
  PORTB = 0b11111111;    _delay_ms(5000);  
  PORTB = 0b00000000;    _delay_ms(5000);  
  // hexadecimal version of PORTB = 1 then PORTB = 0
  PORTB = 0x01;      _delay_ms(5000);      // led on
  PORTB = 0x00;      _delay_ms(5000);      // led off  
  // hexadecimal version of PORTB = 255 then PORTB = 0
  PORTB = 0xFF;      _delay_ms(5000);      // led on
  PORTB = 0x00;      _delay_ms(5000);      // led off  
    
  // shifts single bit from PORTB.0 to PORTB.7
  for (int j=0;j < reps;j++) {      
  for (int i=0; i < 8 ;i++) { PORTB = (1<<i); _delay_ms(4000);}
  for (int i=0; i < 8 ;i++) { PORTB = (128>>i); _delay_ms(4000);}
}
  // masking of bits with |= and &= operators
  for (int j=0;j < reps;j++) {
  PORTB |= 0b00000001;  _delay_ms(5000);   // mask to force PORTB.0 = 1
  PORTB &= 0b11111110;  _delay_ms(5000);   // mask to force PORTB.0 = 0
  }
  // alternate pattern
  for (int j=0;j < reps;j++) {
  PORTB = 0x55;  _delay_ms(9000);          // PORTB = 0b01010101
  PORTB = 0xAA;   _delay_ms(9000);         // PORTB = 0b10101010
  }
  // mathematical inverse of PORTB is put into PORTB  
  for (int j=0;j < reps;j++) {
  PORTB = !PORTB; _delay_ms(5000);
    }}}
