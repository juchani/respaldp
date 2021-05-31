#include <SoftwareSerial.h>
#include <HTTPClient.h>
#include <WebServer.h>
#include <TFT_eSPI.h>
#include <EEPROM.h>
#include <WiFi.h>
#include <SPI.h>
#define boton 35
//-------------------OBJ
TFT_eSPI tft = TFT_eSPI();
SoftwareSerial rs232(26, 27);//rx-tx
WiFiClient espClient;
WebServer server(80);
//-------------------VARIABLES GLOBALES
String url = "http://clinica.solucionespymes.com/apic/savedata?list=FREND";
unsigned long lastTime = 0;
unsigned long timerDelay = 5000;
String texto = "", E;
String item_code, test_result, test_unit, ref_max, ref_min, date_time, ver = "1.0.0.0";
String total[8] = {E, item_code, test_result, test_unit, ref_max, ref_min, date_time, ver};
int buzzer = 12, led = 13;
int vacio = 0, limite = 0;
String fecha;
bool error = 0;
//-----------EEPROM--------------
int contconexion = 0;
unsigned long previousMillis = 0;
int cargando;
char ssid[50];
char pass[50];

const char *ssidConf = "FREND";
const char *passConf = "12345678";

String mensaje = "";
//---------------------------------
//-----------CODIGO HTML PAGINA DE CONFIGURACION---------------
String pagina = "<!DOCTYPE html>"
                "<html>"
                "<head>"
                "<title>NanoEntek</title>"
                "<meta charset='UTF-8'>"
                "</head>"
                "<body>"
                "</form>"
                "<form action='guardar_conf' method='get'>"
                "SSID:<br><br>"
                "<input class='input1' name='ssid' type='text'><br>"
                "PASSWORD:<br><br>"
                "<input class='input1' name='pass' type='password'><br><br>"
                "<input class='boton' type='submit' value='GUARDAR'/><br><br>"
                "</form>"
                "<a href='escanear'><button class='boton'>ESCANEAR</button></a><br><br>";

String paginafin = "</body>"
                   "</html>";
void setup()
{
  Serial.begin(9600);//
  rs232.begin(9600);//RS232
  pinMode(13, OUTPUT); // D7
  //  Wire.begin();
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  delay(1000);
  // Inicia Serial
  Serial.begin(9600);
  Serial.println("");

  EEPROM.begin(512);

  pinMode(35, INPUT);


  leer(0).toCharArray(ssid, 50);
  leer(50).toCharArray(pass, 50);
  bt();
  setup_wifi();

}

void loop()
{
  res();
  updateSerial();
  Serial.println(rs232.available());
  delay(10);
  
}
void bt() {
  if (digitalRead(35) == 0) {

    modoconf();
  }
}
void res() {
  if (digitalRead(35) == 0) {
    ESP.restart();
  }
}

String li(bool n, String l) {
  l.trim();
  if (n == 0) {
    l = l + "|";
  }
  else {
    l = "|" + l + "|";
  }
  return l;
}
