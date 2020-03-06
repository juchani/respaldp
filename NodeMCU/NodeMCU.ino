#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "9cf604458e1b4973a78316dd8ece650d";
char ssid[] = "juchani";
char pass[] = "12345678";
WidgetLCD lcd (V3);
int contador;
int cont;
int mint;
int minuto;
void setup()
{
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

}

void loop()
{
  Blynk.run();
  lcd.print(0,0,contador);
  lcd.print(2,0,"HORAS");
  lcd.print(0,1,minuto);
  lcd.print(2,1,"MINUTOS");
}
BLYNK_WRITE(V0){
  switch(param.asInt())
  {
    case 1:
      cont=1;
      lcd.clear();
      break;
    case 2:
      cont=2;
      lcd.clear();
      break;
    case 3:
      cont=3;
      lcd.clear();
      break;
    case 4:
      cont=4;
      lcd.clear();
      break;
  }
}
BLYNK_WRITE(V1){
  switch(param.asInt())
  {
    case 1:
      mint=1;
      lcd.clear();
      break;
    case 2:
      mint=2;
      lcd.clear();
      break;
    case 3:
      mint=3;
      lcd.clear();
      break;
    case 4:
      mint=4;
      lcd.clear();
      break;
    case 5:
      mint=5;
      lcd.clear();
      break;  
  }
}
BLYNK_WRITE(V2){
  int botton=param.asInt();
  if(botton==1){
    contador=cont;
    minuto=mint;
    lcd.clear();
    Blynk.notify("REGISTRO COMPLETO");
  }

}


