#include <Wire.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
volatile int contador = 0;   // Variable entera que se almacena en la RAM del Micro
int bt1 = 9;
void setup()   {
  attachInterrupt(0, interrupcion0, FALLING); // Interrupcion 0 (pin2)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  pinMode(bt1, INPUT);


}


void loop() {
  delay(999);               // retardo de casi 1 segundo
  display.clearDisplay();
  if (digitalRead(bt1)) {
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(10, 10);
    display.println("RPM:" + String(contador * 60));
  }

  display.display();
  contador = 0;
}


void interrupcion0()    // Funcion que se ejecuta durante cada interrupion
{
  contador++;           // Se incrementa en uno el contador

}



