#include <GPRS_Shield_Arduino.h>
#include <SoftwareSerial.h>
#define PIN_TX    7
#define PIN_RX    8
#define BAUDRATE  9600
#define NUMERO "71066743"
#define NUMERO1 "63528608"
#define PIN_ESTATUS 9
#define SENSOR 12
#define LED 13
GPRS gprs(PIN_TX, PIN_RX, BAUDRATE); //RX,TX,PWR,BaudRate
char in_number[16] = {0};
int contador = 0;
int contador1 = 0;
int pin1 = A0, pin2 = A1, pin3 = A2, pin4 = A3;
bool estado = 0;
char n[16] = {'7', '1', '0', '6', '6', '7', '4', '3'};
char n1[16] = {'6', '3', '5', '2', '8', '6', '0', '8'};
void setup() {
  gprs.checkPowerUp();
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(PIN_ESTATUS, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(SENSOR, INPUT_PULLUP);
  Serial.begin(9600);
  while (!gprs.init()) {
    delay(1000);
    Serial.println("INICIO FALLIDO");
  }
  digitalWrite(LED, 1);
  Serial.println("gprs initialize done");

}

void loop() {
  if (digitalRead(SENSOR) == 0 && estado == 1 ) {
    while (estado == 1) {
      llamada();
      for (int t = 0; t < 50; t++) {
        activacion();
      }
    }
  }
  activacion();
  Serial.println(estado);
}




void llamada() {
  Serial.println("iniciando llamada ...");
  gprs.callUp(NUMERO);
  delay(10000);
  Serial.println("llamada finalizada..");
  gprs.hangup();
  delay(1000);
  Serial.println("iniciando llamada ...");
  gprs.callUp(NUMERO1);
  delay(10000);
  Serial.println("llamada finalizada..");
  gprs.hangup();
  delay(1000);
}
void activacion() {
  bool act;
  char receptor[16] = {0};
  act = gprs.isCallActive(receptor);
  Serial.print("estado : ");
  Serial.println(estado);
  if (act) {
    Serial.print("numero: ");
    Serial.println(receptor);
    for (int i = 0; i < 7; i++) {
      if (n1[i] == receptor[i]) {
        contador1++;
      }
      if (n[i] == receptor[i]) {
        contador++;
      }
    }
    Serial.print("coincidencias ");
    Serial.println(contador);

    if (contador == 7 || contador1 == 7) {
      Serial.println("aprobado");
      delay(15000);
      gprs.hangup();
      estado = !estado;
      digitalWrite(pin1,!estado);
      digitalWrite(pin2,!estado);
      digitalWrite(pin3,!estado);
      digitalWrite(pin4,!estado);
    }
    contador = 0;
    contador1 = 0;
  }
  // return estado;
  delay(1000);
}
