#include <Adafruit_GFX.h>
#include <UTFTGLUE.h>
#include "SingleEMAFilterLib.h"
SingleEMAFilter<int> singleEMAFilter(6.9);
UTFTGLUE myGLCD(0x0154, A2, A1, A3, A4, A0);
#if !defined(SmallFont)
extern uint8_t SmallFont[];    //.kbv GLUE defines as GFXFont ref
#endif
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define GRAY    0x8410
String numero;
int contador = 0,c1=0;
int tiempo = 100;
int sensor;
void setup()
{
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
Serial.begin(9600);
}

void loop()
{
   sensor = analogRead(A8);
  singleEMAFilter.AddValue(sensor);
  Serial.println(sensor);
  if(sensor>400){
    c1++;
  }
  if(contador<1000){
  contador++;
  }
  else{
    pantalla();
 contador=0;
  }
    delay(1);
  
}
void pantalla(){
myGLCD.setRotation(1);
  int width = myGLCD.width();
  int height = myGLCD.height();
  myGLCD.fillScreen(RED);
  myGLCD.setTextSize(10);
  myGLCD.setTextColor(WHITE);
  myGLCD.setCursor(30, 20);
  myGLCD.print(String(c1), 32, 60);
  
}

