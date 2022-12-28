/***********************************************************************************
  This program is a demo of clearing ILI9341 screen to display red,green,blue.
  modified from _9341uno.ino example program from LCD WIKI
  8bit parallel data port.  MCUFRIEND pin layout.  Screen size of 320x240 using coded values
  libraries not needed, program runs directly.
  MCUFRIEND shield pin assignment:
              LCD_CS  LCD_CD  LCD_WR  LCD_RD  LCD_RST  SD_SS  SD_DI  SD_DO  SD_SCK
  Arduino Uno    A3      A2      A1      A0      A4      10     11     12      13
              LCD_D0  LCD_D1  LCD_D2  LCD_D3  LCD_D4  LCD_D5  LCD_D6  LCD_D7
  Arduino Uno    8       9       2       3       4       5       6       7
  MCUFRIEND leaves D0-D1 uart pins and SPI pins D1-D13 free
**********************************************************************************/
#define LCD_RD   A0   // LCD read data pin
#define LCD_WR   A1   // LCD wait/ready pin
#define LCD_CD   A2   // LCD command/data pin
#define LCD_CS   A3   // LCD chip select    
#define LCD_RST A4    // reset LCD screen
void Lcd_Writ_Bus(unsigned char d)
{
  PORTD = (PORTD & B00000011) | ((d) & B11111100);
  PORTB = (PORTB & B11111100) | ((d) & B00000011);
  *(portOutputRegister(digitalPinToPort(LCD_WR))) &=  ~digitalPinToBitMask(LCD_WR);
  *(portOutputRegister(digitalPinToPort(LCD_WR))) |=  digitalPinToBitMask(LCD_WR);
}
void Lcd_Write_Com(unsigned char VH)
{
  *(portOutputRegister(digitalPinToPort(LCD_CD))) &=  ~digitalPinToBitMask(LCD_CD);//LCD_RS=0;
  Lcd_Writ_Bus(VH);
}
void Lcd_Write_Data(unsigned char VH)
{
  *(portOutputRegister(digitalPinToPort(LCD_CD))) |=  digitalPinToBitMask(LCD_CD); //LCD_RS=1;
  Lcd_Writ_Bus(VH);
}
void Lcd_Write_Com_Data(unsigned char com, unsigned char dat)
{
  Lcd_Write_Com(com);
  Lcd_Write_Data(dat);
}
void Address_set(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2)
{
  Lcd_Write_Com(0x2a);
  Lcd_Write_Data(x1 >> 8);
  Lcd_Write_Data(x1);
  Lcd_Write_Data(x2 >> 8);
  Lcd_Write_Data(x2);
  Lcd_Write_Com(0x2b);
  Lcd_Write_Data(y1 >> 8);
  Lcd_Write_Data(y1);
  Lcd_Write_Data(y2 >> 8);
  Lcd_Write_Data(y2);
  Lcd_Write_Com(0x2c);
}
void Lcd_Init(void)
{
  digitalWrite(LCD_RST, HIGH);
  delay(5);
  digitalWrite(LCD_RST, LOW);
  delay(15);
  digitalWrite(LCD_RST, HIGH);
  delay(15);
  digitalWrite(LCD_CS, HIGH);
  digitalWrite(LCD_WR, HIGH);
  digitalWrite(LCD_CS, LOW); //CS
  Lcd_Write_Com(0xCB);
  Lcd_Write_Data(0x39);
  Lcd_Write_Data(0x2C);
  Lcd_Write_Data(0x00);
  Lcd_Write_Data(0x34);
  Lcd_Write_Data(0x02);
  Lcd_Write_Com(0xCF);
  Lcd_Write_Data(0x00);
  Lcd_Write_Data(0XC1);
  Lcd_Write_Data(0X30);
  Lcd_Write_Com(0xE8);
  Lcd_Write_Data(0x85);
  Lcd_Write_Data(0x00);
  Lcd_Write_Data(0x78);
  Lcd_Write_Com(0xEA);
  Lcd_Write_Data(0x00);
  Lcd_Write_Data(0x00);
  Lcd_Write_Com(0xED);
  Lcd_Write_Data(0x64);
  Lcd_Write_Data(0x03);
  Lcd_Write_Data(0X12);
  Lcd_Write_Data(0X81);
  Lcd_Write_Com(0xF7);
  Lcd_Write_Data(0x20);
  Lcd_Write_Com(0xC0);    //Power control
  Lcd_Write_Data(0x23);   //VRH[5:0]
  Lcd_Write_Com(0xC1);    //Power control
  Lcd_Write_Data(0x10);   //SAP[2:0];BT[3:0]
  Lcd_Write_Com(0xC5);    //VCM control
  Lcd_Write_Data(0x3e);   //Contrast
  Lcd_Write_Data(0x28);
  Lcd_Write_Com(0xC7);    //VCM control2
  Lcd_Write_Data(0x86);   //--
  Lcd_Write_Com(0x36);    // Memory Access Control
  Lcd_Write_Data(0x48);
  Lcd_Write_Com(0x3A);
  Lcd_Write_Data(0x55);
  Lcd_Write_Com(0xB1);
  Lcd_Write_Data(0x00);
  Lcd_Write_Data(0x18);
  Lcd_Write_Com(0xB6);    // Display Function Control
  Lcd_Write_Data(0x08);
  Lcd_Write_Data(0x82);
  Lcd_Write_Data(0x27);
  Lcd_Write_Com(0x11);    //Exit Sleep
  delay(120);
  Lcd_Write_Com(0x29);    //Display on
  Lcd_Write_Com(0x2c);
}
void H_line(unsigned int x, unsigned int y, unsigned int l, unsigned int c)
{
  unsigned int i, j;
  Lcd_Write_Com(0x02c); //write_memory_start
  digitalWrite(LCD_CD, HIGH);
  digitalWrite(LCD_CS, LOW);
  l = l + x;
  Address_set(x, y, l, y);
  j = l * 2;
  for (i = 1; i <= j; i++)
  {
    Lcd_Write_Data(c);
  }
  digitalWrite(LCD_CS, HIGH);
}
void V_line(unsigned int x, unsigned int y, unsigned int l, unsigned int c)
{
  unsigned int i, j;
  Lcd_Write_Com(0x02c); //write_memory_start
  digitalWrite(LCD_CD, HIGH);
  digitalWrite(LCD_CS, LOW);
  l = l + y;
  Address_set(x, y, x, l);
  j = l * 2;
  for (i = 1; i <= j; i++)
  {
    Lcd_Write_Data(c);
  }
  digitalWrite(LCD_CS, HIGH);
}
void Rect(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int c)
{
  H_line(x  , y  , w, c);
  H_line(x  , y + h, w, c);
  V_line(x  , y  , h, c);
  V_line(x + w, y  , h, c);
}
void Rectf(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int c)
{
  unsigned int i;
  for (i = 0; i < h; i++)
  {
    H_line(x  , y  , w, c);
    H_line(x  , y + i, w, c);
  }
}
int RGB(int r, int g, int b)
{ return r << 16 | g << 8 | b;
}
void LCD_Clear(unsigned int j)
{
  unsigned int i, m;
  Address_set(0, 0, 240, 320);
  //Lcd_Write_Com(0x02c); //write_memory_start
  //digitalWrite(LCD_CD,HIGH);
  digitalWrite(LCD_CS, LOW);
  for (i = 0; i < 240; i++)
    for (m = 0; m < 320; m++)
    {
      Lcd_Write_Data(j >> 8);
      Lcd_Write_Data(j);
    }
  digitalWrite(LCD_CS, HIGH);
}
void setup()
{ // turn on digital IO pins d0 to d9 as data out, analog control pins
  for (int p = 0; p < 10; p++)
  {   pinMode(p, OUTPUT);}    // pins d0 to d9
  pinMode(A0, OUTPUT);        // LCD_RD read pin
  pinMode(A1, OUTPUT);        // LCD_WR wait/ready pin
  pinMode(A2, OUTPUT);        // LCD_CD command/data pin
  pinMode(A3, OUTPUT);        // LCD_CS chip select pin
  pinMode(A4, OUTPUT);        // LCD_RST reset screen pin
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  digitalWrite(A4, HIGH);
  Lcd_Init();
}
void loop()
{
  LCD_Clear(0xf800);   // red
  LCD_Clear(0xffe0);   // yellow
  LCD_Clear(0x07E0);   // green
  LCD_Clear(0x07ff);   // cyan
  LCD_Clear(0x001F);   // blue
  LCD_Clear(0xf81f);   // magenta
  /*  uncomment for random rectangles
    for(int i=0;i<1000;i++)
    { Rect(random(300),random(300),random(300),random(300),random(65535)); // rectangle at x, y, with, hight, color
    }*/
}
