
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = " f340ae3514fa4a81b4d630009c0d98f8";
char ssid[] = "juchani";
char pass[] = "kazeshini";
int estado;
int bucle=0;
void setup() {

 Blynk.begin(auth, ssid, pass);
 
  Serial.begin(9600);//mlx.begin();  
}

void loop() {
  int t=WiFi.RSSI();
 Serial.println(t);


}
