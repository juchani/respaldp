#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = " f340ae3514fa4a81b4d630009c0d98f8";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "juchani";
char pass[] = "kazeshini";
int estado;
void setup()
{
  // Debug console
  Serial.begin(9600);
pinMode(5,INPUT);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);
}

void loop()
{
  Blynk.run();
  estado=digitalRead(5);
  if (estado==HIGH){
    Blynk.notify("hola mundo");
  }
  
}

