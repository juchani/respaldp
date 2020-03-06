// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"
#include <EEPROM.h>
RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int dir_new=100;
int dir_old=101;
int dir_contador=102;
int new_1=0;
int old_1=0;
int contador=0;
int limite=10;
void setup () {
  while (!Serial); // for Leonardo/Micro/Zero

  Serial.begin(9600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    
  }
  DateTime now = rtc.now();
  if(EEPROM.read(dir_new)<now.second()){
  int resque=EEPROM.read(dir_contador);
  resque=resque+(EEPROM.read(dir_new)-now.second());
  EEPROM.write(dir_contador,resque);}
 else{
  new_1=now.second();
  old_1=now.second();
  EEPROM.write(dir_new,new_1 );
  EEPROM.write(dir_old,old_1 );
}

}

void loop () {
  
    contado();
}
