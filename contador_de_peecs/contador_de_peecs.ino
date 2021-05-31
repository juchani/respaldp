#include <TFT_eSPI.h>
#include <SPI.h>
#define boton 35
#define res 0
//-------------------OBJ
TFT_eSPI tft = TFT_eSPI();
int rf;
int t1, t2, t3, rst = 30;
int c1, c2, c3;
bool pausa = 1;
bool touch1 = false;
bool touch2 = false;
bool touch3 = false;
void setup()
{
  Serial.begin(9600);//

  pinMode(boton, INPUT);
  pinMode(res, INPUT);
  //  Wire.begin();
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  touchAttachInterrupt(T2, contador1, 40);
  touchAttachInterrupt(T3, contador2, 40);
  touchAttachInterrupt(T4, contador3, 40);




}

void loop()
{
  if (rf > 300) {
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(50, 20, 2);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextSize(1);
    tft.print("contador de peces ");
    tft.setCursor(10, 60, 2);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextSize(1);
    tft.print("canal 1");
    tft.setCursor(30, 80, 2);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.print(c1);
    //////////////////77
    tft.setCursor(100, 60, 2);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextSize(1);
    tft.print("canal 2");
    tft.setCursor(120, 80, 2);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.print(c2);
    ////////////////////////
    tft.setCursor(180, 60, 2);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextSize(1);
    tft.print("canal 3");
    tft.setCursor(200, 80, 2);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.print(c3);
    //////////////////////
    tft.setCursor(10, 110, 2);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextSize(1);
    tft.print("TOTAL = ");
    tft.print(c3 + c1 + c2);
    /////////////////77
    tft.setCursor(200, 110, 2);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextSize(1);
    tft.print("RESET ");
    ///////////////////
    tft.setCursor(190, 10, 2);
    if (pausa) {
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
    }
    else {
      tft.setTextColor(TFT_WHITE, TFT_RED);
      
    }
    tft.setTextSize(1);
    tft.print(" PAUSA");

    rf = 0;
  }
  if (t1 > rst && touch1 == true && pausa) {
    t1 = 0;
    c1++;
    touch1 = false;
    rf = 301;
  }
  if (t2 > rst && touch2 == true && pausa) {
    t2 = 0;
    c2++;
    touch2 = false;
    rf = 301;
  }
  if (t3 > rst && touch3 == true && pausa) {
    t3 = 0;
    c3++;
    touch3 = false;
    rf = 301;
  }
  if (!digitalRead(boton)) {
    pausa = !pausa;
    touch1 = false;
    touch2 = false;
    touch3 = false;
    delay(300);
  }
  if (!digitalRead(res)) {
    rf = 301;
    c1 = 0;
    c2 = 0;
    c3 = 0;
    delay(100);
  }
  Serial.print(digitalRead(boton));
  Serial.print('\t');
  Serial.print(c1);
  Serial.print('\t');
  Serial.print(c2);
  Serial.print('\t');
  Serial.println(c3);
  delay(1);
  rf++;
  t1++;
  t2++;
  t3++;
}
void contador1() {
  touch1 = true;
  t1 = 0;
}
void contador2() {
  touch2 = true;
  t2 = 0;
}

void contador3() {
  touch3 = true;
  t3 = 0;
}
