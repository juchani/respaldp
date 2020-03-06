#include <Adafruit_GFX.h>
#include <UTFTGLUE.h>              // class methods are in here
UTFTGLUE myGLCD(0x0154,A2,A1,A3,A4,A0);

//#if !defined(SmallFont)
extern uint8_t SmallFont[20];    //.kbv GLUE defines as GFXFont ref
//#endif
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
int contador =0;
int hora,minuto,segundo;
int tiempo=100;
String reloj[]={};
void setup()
{
  randomSeed(analogRead(5));   //.kbv Due does not like A0
    pinMode(A0, OUTPUT);       //.kbv mcufriend have RD on A0
    digitalWrite(A0, HIGH);
  
// Setup the LCD
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
}

void loop()
{
  
  
  myGLCD.setRotation(1);
    int width = myGLCD.width();
    int height = myGLCD.height();
    myGLCD.fillScreen(GRAY);
//    myGLCD.drawRect(0, 0, width, height, WHITE);
    //tft.drawRect(31, 32, width - 64, height - 64, WHITE);
    numero=contador;
    myGLCD.setTextSize(7);
    myGLCD.setTextColor(WHITE);
    myGLCD.print(numero,22,6);
    myGLCD.setTextColor(WHITE);
    myGLCD.print(":",100,7);
    myGLCD.setTextColor(WHITE);
    myGLCD.print(numero,127,6);
        myGLCD.setTextColor(WHITE);
    myGLCD.print(":",200,7);
    myGLCD.setTextColor(WHITE);
    myGLCD.print(numero,227,6);
      myGLCD.setTextSize(2);
    myGLCD.setTextColor(WHITE);
    myGLCD.print("MIE",22,60);
    myGLCD.setTextSize(0); 
    myGLCD.print(".,",60,70);
    myGLCD.setTextSize(2);
    myGLCD.print("DIC.",75,60);
        delay(500);
    contador++;
  if (contador>99){
    contador=0;
  }
}

