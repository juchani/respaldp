#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>
#define button1 2
#define button2 3
#define buzzer 7
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27);
RF24 radio(9, 10);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
const uint16_t this_node = 00;   // Address of this node in Octal format ( 04,031, etc)
const uint16_t node01 = 01;      // Address of the other node in Octal format
const uint16_t node012 = 012;
int tiempo = 0, tiempo2 = 0;
String estado1[] = {"on", "off"};
String estado2[] = {"on", "off"};
bool estatus1 = 1, estatus2 = 1;
int error;
int t_rastreo = 100;
bool d, e;
void setup() {
  Serial.begin(9600);
  SPI.begin();
  radio.begin();
  network.begin(90, this_node);  //(channel, node address)
  radio.setDataRate(RF24_2MBPS);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  Wire.begin();
  Wire.beginTransmission(0x27);
  error = Wire.endTransmission();
  Serial.print("Error: ");
  Serial.print(error);


  lcd.begin(16, 2); // initialize the lcd

  lcd.setBacklight(255);
}

void loop() {
  network.update();
  //===== Receiving =====//
  if ( network.available() ) {     // Is there any incoming data?
    RF24NetworkHeader header;
    unsigned long incomingData;
    network.read(header, &incomingData, sizeof(incomingData)); // Read the incoming data
    if (header.from_node == 1) {   // If data comes from Node 02
      Serial.println("nodo 1 conectado");
      tiempo = 0;
      estatus1 = 0;
      d = incomingData;
Serial.println(d);
    }
    if (header.from_node == 12) {    // If data comes from Node 02
      Serial.println("nodo 2 conectado");
      estatus2 = 0;
      tiempo2 = 0;
      e = incomingData;
Serial.println(e);
    }
  }
  //===== Sending =====//
  // Servo control at Node 01
  if (digitalRead(button1) == 0) {
    unsigned long buttonState1 = digitalRead(button1);
    RF24NetworkHeader header2(node01);     // (Address where the data is going)
    bool ok = network.write(header2, &buttonState1, sizeof(buttonState1)); // Send the data


  }
  if (digitalRead(button1) == 1 && d == 1) {
    unsigned long buttonState1 = digitalRead(button1);
    RF24NetworkHeader header2(node01);     // (Address where the data is going)
    bool ok = network.write(header2, &buttonState1, sizeof(buttonState1)); // Send the data

  }
  // LED Control at Node 012
  
  if (digitalRead(button2) == 0) {
  unsigned long buttonState = digitalRead(button2);
  RF24NetworkHeader header4(node012);    // (Address where the data is going)
  bool ok3 = network.write(header4, &buttonState, sizeof(buttonState)); // Send the data

  }
  if (digitalRead(button2) == 1 && e == 1) {
unsigned long buttonState = digitalRead(button2);
  RF24NetworkHeader header4(node012);    // (Address where the data is going)
  bool ok3 = network.write(header4, &buttonState, sizeof(buttonState)); // Send the data
  }
  
  if (tiempo < t_rastreo) // 1000   cilcos de 1ms
  {
    tiempo = tiempo + 1;
    //Serial.println(tiempo);
  }
  else   //ya transcurrió 100ms (100ciclos)
  {
    digitalWrite(buzzer, 1);
    delay(500);
    digitalWrite(buzzer, 0);
    Serial.println("nodo 1 desconectado");
    tiempo = 0;
    estatus1 = 1;
    lcd.clear();
  }
  if (tiempo2 < t_rastreo) // 1000   cilcos de 1ms
  {
    tiempo2 = tiempo2 + 1;
    //Serial.println(tiempo2);
  }
  else   //ya transcurrió 100ms (100ciclos)
  {
    digitalWrite(buzzer, 1);
    delay(500);
    digitalWrite(buzzer, 0);
    delay(500);
    Serial.println("nodo 2 desconectado");
    tiempo2 = 0;
    estatus2 = 1;
    lcd.clear();
  }
  lcd.setCursor(0, 0);
  lcd.print("nodo 1:" + estado1[estatus1]);
  lcd.setCursor(0, 1);
  lcd.print("nodo 2:" + estado2[estatus2]);
  Serial.println(d)  ;
}
