#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

#define OLED_RESET     4
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
int volumen;
int pinecho = 7;
int pintrigger = 6;
int  led = 13;
float tiempo, distancia;

void setup() {

  Serial.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  pinMode(pinecho, INPUT);
  pinMode(pintrigger, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // ENVIAR PULSO DE DISPARO EN EL PIN "TRIGGER"
  digitalWrite(pintrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrigger, HIGH);
  // EL PULSO DURA AL MENOS 10 uS EN ESTADO ALTO
  delayMicroseconds(10);
  digitalWrite(pintrigger, LOW);

  // MEDIR EL TIEMPO EN ESTADO ALTO DEL PIN "ECHO" EL PULSO ES PROPORCIONAL A LA DISTANCIA MEDIDA
  tiempo = pulseIn(pinecho, HIGH);

  // LA VELOCIDAD DEL SONIDO ES DE 340 M/S O 29 MICROSEGUNDOS POR CENTIMETRO
  // DIVIDIMOS EL TIEMPO DEL PULSO ENTRE 58, TIEMPO QUE TARDA RECORRER IDA Y VUELTA UN CENTIMETRO LA ONDA SONORA
  distancia = (tiempo / 29) / 2;

  // ENVIAR EL RESULTADO AL MONITOR SERIAL

  volumen = 3.14159265359 * (5.5 * 5.5) * (10 - distancia);
  volumen=volumen+40;
  Serial.print(distancia);
  Serial.print(" cm ");
  Serial.print(volumen);
  Serial.println(" cm3");

  display.clearDisplay();
  display.setCursor(25, 10);
  display.setTextSize(1);             // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.println("bienvenido");
  display.setCursor(25, 20);
   display.print("victor");
  display.display();

  if (distancia <= 5) {
    digitalWrite(led, 1);

  }
  else {
    digitalWrite(led, 0);
  }

  delay(200);

}
