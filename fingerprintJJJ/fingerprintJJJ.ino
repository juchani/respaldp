#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 32 

#define OLED_RESET     4 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
int getFingerprintIDez();
bool estado=0;

SoftwareSerial mySerial(2, 3);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
void setup()  
{
 pinMode(13,OUTPUT);
  Serial.begin(9600);
 

  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    
  } else {
    
    while (1);
  }
  
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
  
    for(;;); 
  }
}

void loop()                     
{
  getFingerprintIDez();
  display.clearDisplay();
  display.setTextSize(1); 
  display.setTextColor(WHITE);
  display.setCursor(10, 10);
  display.println(F("coloque su huella"));
  display.display();      
  delay(10);
    
}


int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  Serial.print("huella encontrada "); Serial.println(finger.fingerID);
  display.clearDisplay();
  display.setTextSize(1); 
  display.setTextColor(WHITE);
  display.setCursor(20, 10);
  display.println(F("identificado"));
  display.display();
  estado=!estado;
  digitalWrite(13,estado);      
  delay(2000); 

  return finger.fingerID; 
}
