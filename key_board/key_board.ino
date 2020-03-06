#include <USBComposite.h>
USBHID HID;
HIDKeyboard Keyboard(HID);

void setup() {
  HID.begin(HID_KEYBOARD);
pinMode(PB12,INPUT);
pinMode(PB13,INPUT);
pinMode(PB14,INPUT);
pinMode(PB15,INPUT);
  Keyboard.begin(); 
  delay(1000);
}

void loop() {
if(digitalRead(PB12)==1){
  Keyboard.println("1");
  delay(5000);
  Keyboard.println("0");
  delay(500);
}
if(digitalRead(PB13)==1){
  Keyboard.println("3");
  delay(5000);
  Keyboard.println("0");
  delay(500);
}
if(digitalRead(PB14)==1){
  Keyboard.println("5");
  delay(5000);
  Keyboard.println("0");
  delay(500);
}
  
  
}
