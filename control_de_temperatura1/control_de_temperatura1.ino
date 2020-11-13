#include <LiquidCrystal_PCF8574.h>
#include <OneWire.h>
#include <Wire.h>

OneWire  ds(9);  // on pin 10 (a 4.7K resistor is necessary)

LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display
float temp, def = 0;
int t_ini = 20, st, duracion, minutos = 5;
int b1 = 6, b2 = 5, b3 = 7, buzzer = 12, sp = t_ini, tiempo, tiempo1, sp1 = t_ini;
int pwm = 3, relay = 4, salida;
void setup()
{
  int error;

  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(pwm, OUTPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  Wire.begin();
  Wire.beginTransmission(0x27);

  lcd.begin(16, 2); // initialize the lcd

} // setup()

void loop()
{
  if (!digitalRead(b1)) {
    sp++;
    tiempo1 = 0;
    delay(300);
    // bip();
  }
  if (!digitalRead(b2)) {
    sp--;
    tiempo1 = 0;
    delay(300);
    // bip();
  }
  if (!digitalRead(b3)) {
    sp1 = sp;
    tiempo1 = 0;
    bip();
    def = 1;
    delay(10);
    st = 1;

  }
  if (tiempo < 100) // 1000   cilcos de 1ms
  {
    tiempo = tiempo + 1;
  }
  else   //ya transcurrió 100ms (100ciclos)
  {
    temp = ds18b20();
    lcd.setBacklight(255);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp= ");
    lcd.print(temp);
    lcd.print(" C");
    lcd.setCursor(0, 1);
    lcd.print("Set Point= ");
    lcd.print(sp);
    lcd.print(" C");
    tiempo = 0;
  }

  if (tiempo1 < 3000) // 1000   cilcos de 1ms
  {
    tiempo1 = tiempo1 + 1;
  }
  else   //ya transcurrió 100ms (100ciclos)
  {
    sp = sp1;
    tiempo1 = 0;
  }
  if (temp < sp1 - 8) {
    digitalWrite(relay, LOW);
  }
  else {
    digitalWrite(relay, HIGH);
   
  }
duracion++;
Serial.println(duracion/100);
  delay(1);
}

float ds18b20() {
  byte i;
  byte present = 0;
  byte type_s;
  byte data[12];
  byte addr[8];
  float celsius, fahrenheit;

  if ( !ds.search(addr)) {
    // Serial.println("No more addresses.");
    //Serial.println();
    ds.reset_search();
    //delay(250);
    return;
  }

  //Serial.print("ROM =");
  for ( i = 0; i < 8; i++) {
    // Serial.write(' ');
    // Serial.print(addr[i], HEX);
  }

  if (OneWire::crc8(addr, 7) != addr[7]) {
    // Serial.println("CRC is not valid!");
    return;
  }
  // Serial.println();

  // the first ROM byte indicates which chip
  switch (addr[0]) {
    case 0x10:
      //   Serial.println("  Chip = DS18S20");  // or old DS1820
      type_s = 1;
      break;
    case 0x28:
      //    Serial.println("  Chip = DS18B20");
      type_s = 0;
      break;
    case 0x22:
      //  Serial.println("  Chip = DS1822");
      type_s = 0;
      break;
    default:
      //    Serial.println("Device is not a DS18x20 family device.");
      return;
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44, 1);        // start conversion, with parasite power on at the end

  //delay(750);     // maybe 750ms is enough, maybe not
  // we might do a ds.depower() here, but the reset will take care of it.

  present = ds.reset();
  ds.select(addr);
  ds.write(0xBE);         // Read Scratchpad

  for ( i = 0; i < 9; i++) {           // we need 9 bytes
    data[i] = ds.read();
  }

  int16_t raw = (data[1] << 8) | data[0];
  if (type_s) {
    raw = raw << 3; // 9 bit resolution default
    if (data[7] == 0x10) {
      // "count remain" gives full 12 bit resolution
      raw = (raw & 0xFFF0) + 12 - data[6];
    }
  } else {
    byte cfg = (data[4] & 0x60);
    // at lower res, the low bits are undefined, so let's zero them
    if (cfg == 0x00) raw = raw & ~7;  // 9 bit resolution, 93.75 ms
    else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
    else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
    //// default is 12 bit resolution, 750 ms conversion time
  }
  celsius = (float)raw / 16.0;
  fahrenheit = celsius * 1.8 + 32.0;

  return celsius;
}
void bip() {
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
}
