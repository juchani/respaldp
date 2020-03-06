#include <Adafruit_GFX.h>
#include <UTFTGLUE.h>         
UTFTGLUE myGLCD(0x0154, A2, A1, A3, A4, A0);

#if !defined(SmallFont)
extern uint8_t SmallFont[];   
String COLOR[] = {"ROJO", "VERDE ", "AZUL","OTRO"};

#endif
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF999
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define GRAY    0x8410
String numero;
char val;
int contador = 0;
int tiempo = 100;

void setup()
{

  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  Serial.begin(9600);
}

void loop()
{
  while (Serial.available()) { // If data is available to read,
    val = Serial.read(); // read it and store it in val
  }
  if (val == 'R') { // If H was received
    color(0);
  }
  if (val == 'G') { // If H was received
    color(1);
  }
  if (val == 'B') { // If H was received
    color(2);
  }
  if (val == 'O') { // If H was received
    color(3);
  }
  val == 'm';
}

void color(int c) {
  myGLCD.setRotation(1);
  int width = myGLCD.width();
  int height = myGLCD.height();
  myGLCD.fillScreen(GRAY);
  if (c == 0) {
    myGLCD.setTextSize(10);
    myGLCD.setTextColor(RED);
    myGLCD.setCursor(80, 20);
    myGLCD.print(COLOR[c], 40, 80);
    myGLCD.setColor(255, 255, 255);
    myGLCD.setBackColor(255, 0, 0);
  }
  if (c == 1) {
    myGLCD.setTextSize(9);
    myGLCD.setTextColor(GREEN);
    myGLCD.setCursor(80, 20);
    myGLCD.print(COLOR[c], 30, 80);
    myGLCD.setColor(255, 255, 255);
    myGLCD.setBackColor(0, 255, 0);
  }

  if (c == 2) {
    myGLCD.setTextSize(10);
    myGLCD.setTextColor(BLUE);
    myGLCD.setCursor(80, 20);
    myGLCD.print(COLOR[c], 40, 80);
  }
  if (c == 3) {
    myGLCD.setTextSize(9);
    myGLCD.setTextColor(GREEN);
    myGLCD.setCursor(80, 20);
    myGLCD.print(COLOR[c], 30, 80);
    myGLCD.setColor(255, 255, 255);
    myGLCD.setBackColor(0, 255, 0);
  }
  myGLCD.setColor(255, 255, 255);
  myGLCD.setBackColor(0, 255, 0);
  myGLCD.drawLine(15, 15, 15, 224);
  myGLCD.drawLine(300, 15, 15, 15);
  myGLCD.drawLine(300, 16, 15, 16);
  myGLCD.drawLine(15, 224, 300, 224);
  myGLCD.drawLine(15, 225, 300, 225);
  myGLCD.drawLine(300, 15, 300, 224);
  myGLCD.drawLine(16, 15, 16, 224);
  myGLCD.drawLine(301, 15, 301, 224);
  delay(1000);
}

