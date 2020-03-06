#include <OneWire.h>
#include <DallasTemperature.h>
#define display_vcc 3
#define display_gnd 4
OneWire ourWire(2);                //Se establece el pin 2  como bus OneWire
#include <ShiftDisplay.h>
#include <Cronos.h>

Cronos M1(2500);
const int LATCH_PIN = 7;
const int CLOCK_PIN = 6;
const int DATA_PIN = 5;
const int DISPLAY_TYPE = COMMON_ANODE; // COMMON_CATHODE or COMMON_ANODE
const int DISPLAY_SIZE = 8; // number of digits on display
float temp1;
float temp2;
ShiftDisplay display(LATCH_PIN, CLOCK_PIN, DATA_PIN, DISPLAY_TYPE, DISPLAY_SIZE);

DallasTemperature sensors(&ourWire); //Se declara una variable u objeto para nuestro sensor

DeviceAddress address1 = {0x28, 0xFF, 0xD0, 0xD2, 0xA1, 0x16, 0x5, 0x34}; //dirección del sensor 1
DeviceAddress address2 = {0x28, 0xFF, 0x4F, 0xF8, 0x81, 0x17, 0x4, 0x89};//dirección del sensor 2


void setup() {
  delay(1000);
  Serial.begin(9600);
  sensors.begin();   //Se inicia el sensor
  pinMode(display_vcc, OUTPUT);
  pinMode(display_gnd, OUTPUT);
  digitalWrite(display_vcc, HIGH);
  digitalWrite(display_gnd, LOW);
}

void loop() {
  if (M1.Estado()) {
    sensors.requestTemperatures();   //envía el comando para obtener las temperaturas
    temp1 = sensors.getTempC(address1); //Se obtiene la temperatura en °C del sensor 1
    temp2 = sensors.getTempC(address2); //Se obtiene la temperatura en °C del sensor 2
  }
  display.show(temp1, 18, 1, ALIGN_LEFT);
  display.show(temp2, 18, 1, ALIGN_RIGHT);
<<<<<<< HEAD
}
=======
}
>>>>>>> 941ca59634530a6110725808d796cfe22c1cd89d
