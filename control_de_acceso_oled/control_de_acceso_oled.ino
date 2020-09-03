//* es para validar la contraseña
//# es para resetear la contraseña

/////////////////////////////////////////////////////////////////
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Password.h>
#include <Keypad.h>
Password password = Password( "1234" );

const byte ROWS = 4; // Four rows
const byte COLS = 3; //  columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = { 2, 3, 4, 5 }; // Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 6, 7, 8}; // Connect keypad COL0, COL1 and COL2 to these Arduino pins.


// Create the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define buzzer A1
#define relay A0
String clave;
int k;
void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  Serial.begin(9600);
  keypad.addEventListener(keypadEvent); //add an event listener for this keypad
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

}

void loop() {

  keypad.getKey();
  display.clearDisplay();
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(15, 10);            // Start at top-left corner
  display.println("COLOQUE LA CLAVE");
  display.setTextSize(1);
  display.setCursor(40, 30);            // Start at top-left corner
  display.println(clave);
  display.display();
}


void keypadEvent(KeypadEvent eKey) {
  switch (keypad.getState()) {
    case PRESSED:
      //Serial.print("Pressed: ");
      //k=int(eKey);
      //Serial.println(char(k)); 
      bip();
      clave = clave + "*";
      switch (eKey) {
        case '*': checkPassword(); clave = ""; break;
        case '#': password.reset(); clave = "";digitalWrite(relay, HIGH); break;
        default: password.append(eKey);
      }
  }
}
