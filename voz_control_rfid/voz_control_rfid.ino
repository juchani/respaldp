#include <SPI.h>
#include <MFRC522.h>
#include <SoftwareSerial.h>
#include <SoftwareSerial.h>
#include <EEPROM.h>
#define RST_PIN  9    //Pin 9 para el reset del RC522
#define SS_PIN  10   //Pin 10 para el SS (SDA) del RC522
MFRC522 mfrc522(SS_PIN, RST_PIN); ///Creamos el objeto para el RC522
SoftwareSerial bt(5, 4); //SIM800L Tx & Rx is connected to Arduino #3 & #2
String texto = "";
String mensaje;
bool e1 = 1, e2 = 1;
int led = 13;
int r1 = A0, r2 = A1, r3 = A2, r4 = A3;

byte ActualUID[7]; //almacenará el código del Tag leído
byte Usuario1[4] = {0x89, 0xBD, 0x3F, 0xA3} ; //código del usuario 1
byte Usuario2[4] = {0x92, 0x7D, 0x05, 0x1C} ; //código del usuario 2
byte Usuario3[7] = {0x04, 0x15, 0xB6, 0x12, 0xE0, 0x64, 0x81} ; //código del usuario 3
byte Usuario4[7] = {0x04, 0x7C, 0xB4, 0x12, 0xE0, 0x64, 0x81} ; //código del usuario 4
byte Usuario5[7] = {0x04, 0x11, 0xB6, 0x12, 0xE0, 0x64, 0x81} ; //código del usuario 5
byte Usuario6[7] = {0x04, 0x7F, 0xB5, 0x12, 0xE0, 0x64, 0x81} ; //código del usuario 6
bool tg1 = 0, tg2 = 0, tg3 = 0, tg4 = 0, tg5 = 0, tg6 = 0;
int c = 0, st = 0;
void setup()
{
  tg1 = EEPROM.read(1);
  tg2 = EEPROM.read(2);
  tg3 = EEPROM.read(3);
  tg4 = EEPROM.read(4);
  tg5 = EEPROM.read(5);
  tg6 = EEPROM.read(6);
  Serial.begin(9600);
  bt.begin(9600);
  SPI.begin();        //Iniciamos el Bus SPI
  mfrc522.PCD_Init(); // Iniciamos el MFRC522
  pinMode(led, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);
  digitalWrite(r1, 1);
  digitalWrite(r2, 1);
  digitalWrite(r3, e1);
  digitalWrite(r4, e2);
}

void loop()
{
  bluet();
  if ( mfrc522.PICC_IsNewCardPresent()) {
    //Seleccionamos una tarjeta
    if ( mfrc522.PICC_ReadCardSerial())
    {
      // Enviamos serialemente su UID
      Serial.print(F("Card UID:"));
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(mfrc522.uid.uidByte[i], HEX);
        ActualUID[i] = mfrc522.uid.uidByte[i];
      }
      Serial.print("     ");
      //comparamos los UID para determinar si es uno de nuestros usuarios
      if (compareArray(ActualUID, Usuario1) && tg1 == 1) {
        puerta();
      }
      else if (compareArray(ActualUID, Usuario2) && tg2 == 1) {

        c = 0;
        st++;
        delay(100);
      }
      else if (compareArray(ActualUID, Usuario3) && tg3) {
        puerta();
      }
      else if (compareArray(ActualUID, Usuario4) && tg4) {
        puerta();
      }
      else if (compareArray(ActualUID, Usuario5) && tg5) {
        puerta();
      }
      else if (compareArray(ActualUID, Usuario6) && tg6) {
        puerta();
      }
      else {
        Serial.println("Acceso denegado...");
        digitalWrite(r3, 1); digitalWrite(r4, 1);
      }


      mfrc522.PICC_HaltA();

    }

  }
  
  if(st>2){
    st=0;
  }
  if (st == 2) {
    arranque(1);
    st = 0;
  }
  if (c > 20) {
    c = 0;
    if (st == 1) {
      puerta();
      st = 0;
    }
    
  }
  Serial.println(c);
  c++;

}


void puerta() {
  Serial.println("Acceso concedido...");
  e1 = !e1;
  digitalWrite(r3, e1);
  digitalWrite(r4, e1);
}
void arranque(bool st) {
  if (st) {
    digitalWrite(r1, 0);
    delay(700);
    digitalWrite(r1, 1);
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(r2, 0);
    delay(700);
    digitalWrite(r2, 1);
    digitalWrite(led, LOW);
  }
}

boolean compareArray(byte array1[], byte array2[])
{
  if (array1[0] != array2[0])return (false);
  if (array1[1] != array2[1])return (false);
  if (array1[2] != array2[2])return (false);
  if (array1[3] != array2[3])return (false);
  return (true);
}

void bluet()
{

  delay(50);
  Serial.println(texto);


  while (bt.available() > 0)
  {
    texto += (char)bt.read();
    //Serial.println(texto);
    if (texto.indexOf("bloquear tarjeta uno") > -1) {
      tg1 = !tg1;

      EEPROM.write(1, tg1);

      texto = "";

    }
    if (texto.indexOf("bloquear tarjeta 2") > -1) {
      tg2 = !tg2;
      EEPROM.write(2, tg2);
      texto = "";

    }
    if (texto.indexOf("bloquear tarjeta 3") > -1) {
      tg3 = !tg3;
      EEPROM.write(3, tg3);
      texto = "";

    }
    if (texto.indexOf("bloquear tarjeta 4") > -1) {
      tg4 = !tg4;
      EEPROM.write(4, tg4);
      texto = "";

    }
    if (texto.indexOf("bloquear tarjeta 5") > -1) {
      tg5 = !tg5;
      EEPROM.write(5, tg5);
      texto = "";

    }
    if (texto.indexOf("bloquear tarjeta 6") > -1) {
      tg6 = !tg6;
      EEPROM.write(6, tg6);
      texto = "";

    }
    if (texto.indexOf("bloquear todas las tarjetas") > -1) {
      tg1 = 0;
      tg2 = 0;
      tg3 = 0;
      tg4 = 0;
      tg5 = 0;
      tg6 = 0;
      EEPROM.write(1, tg1);
      EEPROM.write(2, tg2);
      EEPROM.write(3, tg3);
      EEPROM.write(4, tg4);
      EEPROM.write(5, tg5);
      EEPROM.write(6, tg6);
      texto = "";

    } if (texto.indexOf("desbloquear todas las tarjetas") > -1) {
      tg1 = 1;
      tg2 = 1;
      tg3 = 1;
      tg4 = 1;
      tg5 = 1;
      tg6 = 1;
      texto = "";

    }
    if (texto.indexOf("arrancar") > -1) {
      arranque(1);
      texto = "";

    }


    Serial.println();
  }




}
