#include <Wire.h>
#include "RTClib.h"
 
const int outputPin = LED_BUILTIN;
bool state = false;
 
// RTC_DS1307 rtc;
RTC_DS3231 rtc;
 
void setup() {
   Serial.begin(9600);
   delay(1000);
 
   if (!rtc.begin()) {
      Serial.println(F("Couldn't find RTC"));
      while (1);
   }
 
   if (rtc.lostPower()) {
      rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
   }
}
 
// Comprobar si esta programado el encendido
bool isScheduledON(DateTime date)
{
   int weekDay = date.dayOfTheWeek();
   float hours = date.hour() + date.minute() / 60.0;
 
   // De 09:30 a 11:30 y de 21:00 a 23:00
   bool hourCondition = (hours > 9.50 && hours < 11.50) || (hours > 21.00 && hours < 23.00);
 
   // Miercoles, Sabado o Domingo
   bool dayCondition = (weekDay == 3 || weekDay == 6 || weekDay == 0); 
   if (hourCondition && dayCondition)
   {
      return true;
   }
   return false;
}
 
void loop() {
   DateTime now = rtc.now();
 
   if (state == false && isScheduledON(now))      // Apagado y debería estar encendido
   {
      digitalWrite(outputPin, HIGH);
      state = true;
      Serial.print("Activado");
   }
   else if (state == true && !isScheduledON(now))  // Encendido y deberia estar apagado
   {
      digitalWrite(outputPin, LOW);
      state = false;
      Serial.print("Desactivar");
   }
 
   delay(3000);
}
