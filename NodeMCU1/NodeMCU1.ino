
#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "f340ae3514fa4a81b4d630009c0d98f8";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "juchani";
char pass[] = "kazeshini";

void setup()
{
  // Debug console
  Serial.begin(9600);
mlx.begin();
  Blynk.begin(auth, ssid, pass);
  
}

void loop()
{
  Blynk.run();
  Blynk.virtualWrite(V1,mlx.readObjectTempC());
  Blynk.virtualWrite(V2,mlx.readAmbientTempC());
}
               
