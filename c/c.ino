#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  mlx.begin();
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print("Ambiente ");
  lcd.print(mlx.readAmbientTempC());
  lcd.print(" C");
 lcd.setCursor(0, 0);

  lcd.print("Objecto ");
  lcd.print(mlx.readObjectTempC());

  lcd.print(" C");
}

