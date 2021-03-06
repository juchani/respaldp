#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>
SoftwareSerial rs232(0, 2);


// Sustituir por los datos de vuestro WiFi
const char* ssid = "Insertec-AP";
const char* password = "INSERTEC2016.";
String url = "http://clinica.solucionespymes.com/apic/savedata?list=FREND";
bool st=0;
void setup()
{
  Serial.begin(9600);
  rs232.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
    delay(500);
}

void loop()
{
  updateSerial();

  delay(20);
}

void updateSerial()
{
  if (rs232.available())
  {

    String cero[12] = rs232.readStringUntil(':');
    cero[0].remove(0, 30);
    cero[1].remove(0, 1);
    cero[1].replace(" ", "|");
    cero[1].replace("-", "");
    cero[3].remove(2, 20);
    cero[4].remove(0, 1);
    cero[4].remove(cero[4].length() - 8, cero[4].length());
    cero[4].replace(" ", "%20");
    cero[5].remove(cero[5].length() - 9, cero[5].length());
    cero[5].replace(" ", "");
    cero[6].remove(cero[6].length() - 9, cero[6].length());
    cero[6].replace(" ", "");
    cero[7].remove(cero[7].length() - 10, cero[7].length());
    cero[7].replace(" ", "");
    cero[8].remove(cero[8].length() - 4, cero[8].length());
    cero[8].replace(" ", "");
    if(cero[9].indexOf("COVID-19 IgG")>-1){
     st=1; 
    }
    cero[9].remove(cero[9].length() - 16, cero[9].length());
    cero[9].replace(" ", "");
    cero[10].remove(cero[10].length() - 14, cero[10].length());
    cero[10].replace(" ", "");
    /*    Serial.print(0);
        Serial.print(" ");
        Serial.println(cero[0]);
        Serial.print(1);
        Serial.print(" ");
        Serial.println(cero[1]);
        Serial.print(2);
        Serial.print(" ");
        Serial.println(cero[2]);
        Serial.print(3);
        Serial.print(" ");
        Serial.println(cero[3]);
        Serial.print(4);
        Serial.print(" ");
        Serial.println(cero[4]);
        Serial.print(5);
        Serial.print(" ");
        Serial.println(cero[5]);
        Serial.print(6);
        Serial.print(" ");
        Serial.println(cero[6]);
        Serial.print(7);
        Serial.print(" ");
        Serial.println(cero[7]);
        Serial.print(8);
        Serial.print(" ");
        Serial.println(cero[8]);
        Serial.print(9);
        Serial.print(" ");
        Serial.println(cero[9]);
        Serial.print(10);
        Serial.print(" ");
        Serial.println(cero[10]);
        Serial.print(11);
        Serial.print(" ");
        Serial.println(cero[11]);
        Serial.print(12);
        Serial.print(" ");
        Serial.println(cero[12]);*/
    String lista = '|' + cero[4] + '|' + cero[5] + '|' + cero[6] + '|' + cero[7] + '|' + cero[8] + '|' + "COVID-19 igG$COVID-19 igM" + '|' + cero[10] + '$' + cero[11] + '|' + '|' + '|' + '|'  + cero[1] + cero[2] + cero[3] + '|' + "1.0.0";
    lista.replace("\n", "");
    lista.replace(" ", "");
    lista.replace("\r", "");
    enviar(lista,st);
  }
}




void enviar(String d,bool l) {
  if(l==1){
  HTTPClient http;
  WiFiClient client;
  d = url + d;
  Serial.println(d);
  if (http.begin(client, d)) //Iniciar conexión
  {
    Serial.print("[HTTP] GET...\n");
    int httpCode = http.GET();  // Realizar petición

    if (httpCode > 0) {
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);

      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        String payload = http.getString();   // Obtener respuesta
        Serial.println(payload);   // Mostrar respuesta por serial
        st=0;
      }
    }
    else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }
  else {
    Serial.printf("[HTTP} Unable to connect\n");
  }  
  }
  
}
