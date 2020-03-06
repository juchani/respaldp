#include <Wire.h>
#include <Adafruit_MLX90614.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = " f340ae3514fa4a81b4d630009c0d98f8";
char ssid[] = "juchani";
char pass[] = "kazeshini";
int estado;
int bucle=0;
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
void setup() {

 Blynk.begin(auth, ssid, pass);
  mlx.begin();  
  pinMode(D0,INPUT);
}

void loop() {
  Blynk.run();
  Blynk.virtualWrite(V1,mlx.readObjectTempC());
  Blynk.virtualWrite(V2,mlx.readAmbientTempC());
 // Blynk.virtualWrite(V3,estado);
 estado=digitalRead(D0);
  if (estado==HIGH){
    if (bucle==0){
    Blynk.notify("hola mundo");  
    bucle=1;
    }
    }
    else{
      bucle=0;
    }
 
 }




