#include <USBComposite.h>

USBHID HID;
HIDKeyboard Keyboard(HID);
int a, b, c, d, cont = 0,tiempo=0,en=0;
void setup() {
 // Serial.begin(9600);
 HID.begin(HID_KEYBOARD);
  Keyboard.begin();
  pinMode(PB12, INPUT);
  pinMode(PB13, INPUT);
  pinMode(PB14, INPUT);
  pinMode(PB15, INPUT);
}

void loop() {
re();
  //Serial.print(a);
 // Serial.print('\t');
  //Serial.print(b);
  //Serial.print('\t');
  //Serial.print(c);
  //Serial.print('\t');
  //Serial.print(d);
  //Serial.print('\t');
  //Serial.println(cont);0
  

}
void re(){
  a = digitalRead(PB12);
  b = digitalRead(PB13);
  c = digitalRead(PB14);
  d = digitalRead(PB15);
 
  if (a==1) {
cont=1;
 en=0;
 tiempo=0;
Keyboard.println(cont);
  }
 if (b==1) {
cont=3;
  en=0;
  tiempo=0;
  Keyboard.println(cont);
  }
   if (c==1) {
cont=5;
en=0;
tiempo=0;
Keyboard.println(cont);
  }
   if (d==1&& en==0) {
cont*=2;
en=1;
tiempo=0;
Keyboard.println(cont);
  }
  
if (tiempo>5000){
tiempo=0;    
en=0;
cont=0;
Keyboard.println(cont);
}
delay(1);  
tiempo++;
}

