
#include <Wire.h>
#include <Adafruit_SH1106.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
#define OLED_RESET 4
Adafruit_SH1106 display(OLED_RESET);

#if (SH1106_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SH1106.h!");
#endif

void setup()   {
  Serial.begin(9600);
  mlx.begin();
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.clearDisplay();

}


void loop() {
  // text display tests
  display.setCursor(0, 0);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.print("A: "); display.println(mlx.readAmbientTempC());
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.print("O: "); display.println(mlx.readObjectTempC());
  display.display();
  delay(2000);
  display.clearDisplay();

}
