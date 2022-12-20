// UTFT_ViewFont from http://www.RinkyDinkElectronics.com/
// demo of the included fonts  requires the UTFT library.
// pins are specific to my board, my OpenSmart 9225
#include <UTFT.h>
// Declare which fonts we will be using
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];
///UTFT myGLCD(ILI9225, A2, A1, A3);
// UTFT myGLCD(ILI9225,LCD_RS,LCD_WR,LCD_CS); works
UTFT myGLCD(ILI9225, A2, A1, A3);
void setup()
{
  myGLCD.InitLCD();
  myGLCD.clrScr();
}
void loop()
{ while (1) {
//  myGLCD.setRotation(r);  // no!  not in the oSmart library!  not utft?
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
