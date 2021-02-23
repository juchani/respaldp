#include <SoftwareSerial.h>
SoftwareSerial SIM800L(9, 8); //SIM800L Tx & Rx is connected to Arduino #3 & #2

String texto, d, fecha, nombre, id, orden, lab, lot, sn;
String igg, igm, igg_t, igg_n, igm_t, igm_n;
String comp;
bool st = 0;
int c;
void setup()
{
  Serial.begin(9600);
  SIM800L.begin(9600);
}

void loop()
{
  updateSerial();
  comp = "";
  Serial.print(nombre);
  Serial.print("|");
  Serial.print(orden);
  Serial.print("|");
  Serial.print(lab);
  Serial.print("|");
  Serial.print(lot);
  Serial.print("|");
  Serial.print(sn);
  Serial.print("|");
  Serial.print(fecha);
  Serial.print("|");
  Serial.print(igg_t);
  Serial.print("|");
  Serial.print(igm_t);
  Serial.print("|");
  Serial.print(igg_n);
  Serial.print("|");
  Serial.println(igm_n);
  delay(20);
}

void updateSerial()
{
  while (SIM800L.available())
  {
    texto += (char)SIM800L.read();

    if (texto.indexOf('\r') > -1) {
      d = texto;
      if (c > 0) {
        d.remove(0, 1);
      }
      if (c == 11) {
        c = 0;
      }
      if (c == 0 && texto.indexOf("Date/Time")) {
        fecha = d;
        fecha.remove(0, 12);
        fecha.replace(" ", "%20");
        d = "";
        Serial.println(fecha);
      }
      if (c == 1&& texto.indexOf("Patient ID")) {
        nombre = d;
        nombre.remove(0, 13);
        nombre.replace(" ", "%20");
        d = "";
        Serial.println(nombre);
      }
      if (c == 2) {
        id = d;
        id.remove(0, 11);
        d = "";
        Serial.println(id);
      }
      if (c == 3) {
        orden = d;
        orden.remove(0, 12);
        d = "";
        Serial.println(orden);
      }
      if (c == 4) {
        lab = d;
        lab.remove(0, 9);
        d = "";
        Serial.println(lab);
      }
      if (c == 5) {
        lot = d;
        lot.remove(0, 12);
        d = "";
        Serial.println(lot);
      }
      if (c == 6) {
        sn = d;
        sn.remove(0, 4);
        d = "";
        Serial.println(sn);
      }
      if (c == 8) {
        igg = d;
        igg.remove(0, 15);
        igg_t = igg;
        igg_t.remove(8, -1);
        igg_n = igg;
        igg_n.remove(0, 8);
        d = "";
        Serial.println(igg);
        Serial.println(igg_t);
        Serial.println(igg_n);
      }
      if (c == 9) {
        igm = d;
        igm.remove(0, 15);
        igm_t = igm;
        igm_t.remove(8, -1);
        igm_n = igm;
        igm_n.remove(0, 8);
        d = "";
        Serial.println(igm);
        Serial.println(igm_t);
        Serial.println(igm_n);
      }
      Serial.print(nombre);
      Serial.print(orden);
      Serial.print(lab);
      Serial.print(lot);
      Serial.print(sn);
      Serial.print(fecha);
      Serial.print(igg_t);
      Serial.print(igm_t);
      Serial.print(igg_n);
      Serial.print(igm_n);
      //FREND|CRISTIANROJAS|45678|SCZ-MELENDRES|250|SERIALOMAC|2020-02-02%2016:48:52|POSITIVO|NEGATIVO|1.2|0.6
      //comp="FREND";
      // comp+="|"+nombre+"|"+orden+"|"+lab+"|"+lot+"|"+sn+"|"+fecha+"|"+igg_t+"|"+igm_t+"|"+igg_n+"|"+igm_n;
      // Serial.println(comp);
      /* Serial.print(c);
        Serial.print(" ");
        Serial.println(d);*/
      c++;
      texto = "";

    }
  }




}
