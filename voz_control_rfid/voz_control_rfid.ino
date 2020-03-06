#include <SPI.h>
#include <MFRC522.h>
#include <SoftwareSerial.h>
#include "VoiceRecognitionV3.h"

#define RST_PIN  9    //Pin 9 para el reset del RC522
#define SS_PIN  10   //Pin 10 para el SS (SDA) del RC522
MFRC522 mfrc522(SS_PIN, RST_PIN); ///Creamos el objeto para el RC522


VR myVR(2, 3);   // 2:RX 3:TX, you can choose your favourite pins.

uint8_t records[7]; // save record
uint8_t buf[64];
bool e1=1,e2=1;
int led = 13;
int r1 = A0, r2 = A1,r3 = A2, r4 = A3;
#define onRecord    (0)
#define offRecord   (1)
byte ActualUID[7]; //almacenará el código del Tag leído
byte Usuario1[4] = {0x89, 0xBD, 0x3F, 0xA3} ; //código del usuario 1
byte Usuario2[4] = {0x92, 0x7D, 0x05, 0x1C} ; //código del usuario 2
byte Usuario3[7] = {0x04, 0x8D, 0xB5, 0x12, 0xE0, 0x64, 0x81} ; //código del usuario 2

void printSignature(uint8_t *buf, int len)
{
  int i;
  for (i = 0; i < len; i++) {
    if (buf[i] > 0x19 && buf[i] < 0x7F) {
      Serial.write(buf[i]);
    }
    else {
      Serial.print("[");
      Serial.print(buf[i], HEX);
      Serial.print("]");
    }
  }
}

void printVR(uint8_t *buf)
{
  Serial.println("VR Index\tGroup\tRecordNum\tSignature");

  Serial.print(buf[2], DEC);
  Serial.print("\t\t");

  if (buf[0] == 0xFF) {
    Serial.print("NONE");
  }
  else if (buf[0] & 0x80) {
    Serial.print("UG ");
    Serial.print(buf[0] & (~0x80), DEC);
  }
  else {
    Serial.print("SG ");
    Serial.print(buf[0], DEC);
  }
  Serial.print("\t");

  Serial.print(buf[1], DEC);
  Serial.print("\t\t");
  if (buf[3] > 0) {
    printSignature(buf + 4, buf[3]);
  }
  else {
    Serial.print("NONE");
  }
  Serial.println("\r\n");
}

void setup()
{
  myVR.begin(9600);

  Serial.begin(115200);
  Serial.println("Elechouse Voice Recognition V3 Module\r\nControl LED sample");
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
  if (myVR.clear() == 0) {
    Serial.println("Recognizer cleared.");
  } else {
    Serial.println("Not find VoiceRecognitionModule.");
    Serial.println("Please check connection and restart Arduino.");
    while (1);
  }

  if (myVR.load((uint8_t)onRecord) >= 0) {
    Serial.println("onRecord loaded");
  }

  if (myVR.load((uint8_t)offRecord) >= 0) {
    Serial.println("offRecord loaded");
  }
}

void loop()
{
  int ret;
  ret = myVR.recognize(buf, 50);
  if (ret > 0) {
    switch (buf[1]) {
      case onRecord:
        digitalWrite(r1, 0);
        delay(700);
        digitalWrite(r1, 1);
        digitalWrite(led, HIGH);
        break;
      case offRecord:
        digitalWrite(r2, 0);
        delay(700);
        digitalWrite(r2, 1);
        digitalWrite(led, LOW);
        break;
      default:
        Serial.println("Record function undefined");
        break;
    }
    /** voice recognized */
    printVR(buf);
  }
  if ( mfrc522.PICC_IsNewCardPresent())
  {
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
      if (compareArray(ActualUID, Usuario1)){
       Serial.println("Acceso concedido...");e1=!e1;digitalWrite(r3, e1);digitalWrite(r4, e1); 
      }
      else if (compareArray(ActualUID, Usuario2)){
       Serial.println("Acceso concedido...");e1=!e1;digitalWrite(r3, e1);digitalWrite(r4, e1); 
      }
      else{
        Serial.println("Acceso denegado...");
        digitalWrite(r3, 1);digitalWrite(r4, 1);
      }
        

      // Terminamos la lectura de la tarjeta tarjeta  actual
      mfrc522.PICC_HaltA();

    }

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
