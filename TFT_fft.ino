// successful port of fft code to ili9225 shield
#include <Wire.h>                                     // 
#include "fix_fft.h"                                  // from fft sketch
#include <Adafruit_GFX.h>

#include <UTFT.h>
extern uint8_t SmallFont[];

#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_RS A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
//#define LCD_RST A0 //
UTFT tft(ILI9225, LCD_RS, LCD_WR, LCD_CS);

int audioIn = A4;
char re[128], im[128];                                // real and imaginary FFT result arrays
byte ylim = 170;                                       // 176 x 220

void setup()
{ randomSeed(analogRead(0));
  // Setup the LCD
  tft.InitLCD();
  tft.fillScr(255,0,255);
  tft.setFont(SmallFont);

  Serial.begin(9600);
  analogReference(DEFAULT);                           // use default analog reference of 5 volts or 3.3V
  Serial.print(" setup finished   \n\n");
}

void loop()
{
  tft.clrScr();
 // tft.fillScr(255,255,255);
  tft.setColor(255, 255, 255);
  tft.drawRect(0, 0, 219, 174);
    tft.drawRect(1, 1, 218, 173);
     tft.drawRect(2, 2, 217, 172);
          
  tft.setColor(255, 200, 200);
  tft.drawLine(0,ylim,219,ylim);
  // sample
  for (byte i = 0; i < 128; i++) {                    // read 128 analog input samples from ADC
    int sample = analogRead(audioIn);
    re[i] = sample / 4 - 128;                         // scale the samples to fit within a char variable
    im[i] = 0;                                        // there are no imaginary samples associated with the time domain so set to 0
  };
  // transform
  fix_fft(re, im, 7, 0);                              // send the samples for FFT conversion, returning the real/imaginary results in the same arrays
   tft.print("Audio Spectrum", CENTER, 11);                    // print a header on the top row of the display
  // draw 64 lines from ylim up to y=0
  for (byte i = 1; i < 64; i++) {
    int dat = sqrt(re[i] * re[i] + im[i] * im[i]);     // magnitude is square root of sum  squares of real and imaginary
    tft.drawLine(i * 4, ylim, i * 4, ylim - 8 * dat); // 176 x 220 with ylim-6 okay, and 3x64 = 192
    //      display.drawLine(i, i+1, 64-i, 63-i, WHITE);      // makes a diagonal line, ok
  };

  Serial.print(" end of loop   \n\n");
  delay(100);


}
