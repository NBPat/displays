// Demo of Graphics on OpenSmart ILI9225 2.2inch shield 176x220
// Basic functions to print alphabet and to draw simple shapes
// This program requires the UTFT library 2.78 modified by OpenSmart

#include <UTFT.h>
// fonts are located in the file DefaultFonts.c
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];
// DATA0-DATA7 pins on shield are OpenSmart not MCUFRIEND
// #define LCD_CS A3 // Chip Select Analog 3
// #define LCD_RS A2 // Command/Data Analog 2
// #define LCD_WR A1 // LCD Write Analog 1
// UTFT myGLCD(ILI9225,LCD_RS,LCD_WR,LCD_CS);	// or use the line below
UTFT myGLCD(ILI9225, A2, A1, A3);

void setup()
{
  myGLCD.InitLCD();
  myGLCD.clrScr();
}
void loop()
{ while (1) {
    myGLCD.setColor(255, 0, 255);
    myGLCD.setBackColor(0, 0, 0);
    myGLCD.setFont(BigFont);
    myGLCD.clrScr();
    myGLCD.print(" !\"#$%&'()*+,-./", CENTER, 0);
    myGLCD.print("0123456789:;<=>?", CENTER, 16);
    myGLCD.print("@ABCDEFGHIJKLMNO", CENTER, 32);
    myGLCD.print("PQRSTUVWXYZ[\\]^_", CENTER, 48);
    myGLCD.print("`abcdefghijklmno", CENTER, 64);
    myGLCD.print("pqrstuvwxyz{|}~ ", CENTER, 80);
 //   delay(300);
    delay(100);

    // pigment
    myGLCD.clrScr();
    myGLCD.setBackColor(0, 0, 0);
    // colour 1
    myGLCD.setColor(0, 255, 255);   
    delay(100);
    myGLCD.fillRect(0, 4, 40, 80);
    myGLCD.print(" 0-255-255 ", RIGHT, 30);
    delay(200);
    // colour 2
    myGLCD.setColor(255, 0, 255);
    myGLCD.fillCircle(30, 90, 30);
    myGLCD.print(" 255-0-255 ", RIGHT, 90);
    // colour 3
    myGLCD.setColor(255, 255, 0);
    myGLCD.fillRoundRect(0, 130, 40, 170);
    myGLCD.print(" 255-255-0 ", RIGHT, 150);
 
    delay(2500);
    myGLCD.clrScr();       

    // smallfont
    myGLCD.setFont(SmallFont);
    myGLCD.setBackColor(0, 0, 0);
    // colour 1
    myGLCD.setColor(0, 255, 255); 
    myGLCD.print(" !\"#$%&'()*+,-./0123456789:;<=>?", CENTER, 40);
    myGLCD.print("@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_", CENTER, 102);
    myGLCD.print("`abcdefghijklmnopqrstuvwxyz{|}~ ", CENTER, 134);
    delay(300);
    myGLCD.clrScr();

    // primary
    myGLCD.clrScr();
    myGLCD.setFont(BigFont);
    myGLCD.setBackColor(0, 0, 0);
    // colour 1
    myGLCD.setColor(0, 0, 255);   
    delay(100);
    myGLCD.fillRect(0, 4, 40, 80);
    myGLCD.print(" 0-0-255 ", RIGHT, 30);
    delay(200);
    // colour 2
    myGLCD.setColor(255, 0, 0);
    myGLCD.fillCircle(30, 90, 30);
    myGLCD.print(" 255-0-0 ", RIGHT, 90);
    // colour 3
    myGLCD.setColor(0, 255, 0);
    myGLCD.fillRoundRect(0, 130, 40, 170);
    myGLCD.print(" 0-255-0 ", RIGHT, 150);
 
    delay(2500);
    myGLCD.clrScr(); 
  }
}
