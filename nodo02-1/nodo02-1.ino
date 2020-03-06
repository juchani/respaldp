/*
  Arduino Wireless Network - Multiple NRF24L01 Tutorial
        == Node 02 (Child of Master node 00) ==
*/

#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>
#include <Servo.h>

#define led 3
#define relay 4

int estado = 0;
RF24 radio(9, 10);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
const uint16_t this_node = 01;   // Address of our node in Octal format ( 04,031, etc)
const uint16_t master00 = 00;    // Address of the other node in Octal format

Servo myservo;  // create servo object to control a servo

void setup() {
  SPI.begin();
  radio.begin();
  network.begin(90, this_node); //(channel, node address)
  radio.setDataRate(RF24_2MBPS);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(relay, OUTPUT);
}

void loop() {
  network.update();
  //===== Receiving =====//
  if ( network.available() ) {     // Is there any incoming data?
    RF24NetworkHeader header;
    unsigned long incomingData;
    network.read(header, &incomingData, sizeof(incomingData)); // Read the incoming data
    if (header.from_node == 0) {   // If data comes from Node 012
      // digitalWrite(led, !incomingData);  // Turn on or off the LED 02

      estado = !incomingData;
      Serial.print(incomingData);
      if (incomingData == 7) {
        digitalWrite(led, HIGH);
        digitalWrite(relay, HIGH);

      }
      else  if (incomingData == 8) {
        digitalWrite(relay, LOW);
        digitalWrite(led, LOW);

      }
      delay(100);

    }
  }
  unsigned long buttonState = estado + 7;
  RF24NetworkHeader header8(master00);    // (Address where the data is going)
  bool ok = network.write(header8, &buttonState, sizeof(buttonState));
}
