#define reps 3
void setup() {}
void loop() {
  // decimal version of PORTB = 1 then PORTB = 0
  PORTB = 1;       delay(500);        // led on
  PORTB = 0;         delay(500);      // led off
  // decimal version of PORTB = 255 then PORTB = 0
  PORTB = 255;       delay(500);  
  PORTB = 0;         delay(500);
  // binary version of PORTB = 1 then PORTB = 0
  PORTB = 0b00000001;    delay(500);  // led on
  PORTB = 0b00000000;    delay(500);  // led off  
  // binary version of PORTB = 255 then PORTB = 0 
  PORTB = 0b11111111;    delay(500);  
  PORTB = 0b00000000;    delay(500);  
  // hexadecimal version of PORTB = 1 then PORTB = 0
  PORTB = 0x01;      delay(500);      // led on
  PORTB = 0x00;      delay(500);      // led off  
  // hexadecimal version of PORTB = 255 then PORTB = 0
  PORTB = 0xFF;      delay(500);      // led on
  PORTB = 0x00;      delay(500);      // led off  
    
  // shifts single bit from PORTB.0 to PORTB.7
  for (int j=0;j < reps;j++) {      
  for (int i=0; i < 8 ;i++) { PORTB = (1<<i); delay(400);}
  for (int i=0; i < 8 ;i++) { PORTB = (128>>i); delay(400);}
}
  // masking of bits with |= and &= operators
  for (int j=0;j < reps;j++) {
  PORTB |= 0b00000001;  delay(500);   // mask to force PORTB.0 = 1
  PORTB &= 0b11111110;  delay(500);   // mask to force PORTB.0 = 0
  }
  // alternate pattern
  for (int j=0;j < reps;j++) {
  PORTB = 0x55;  delay(900);          // PORTB = 0b01010101
  PORTB = 0xAA;   delay(900);         // PORTB = 0b10101010
  }
  // mathematical inverse of PORTB is put into PORTB  
  for (int j=0;j < reps;j++) {
  PORTB = !PORTB; delay(950);
    }}
