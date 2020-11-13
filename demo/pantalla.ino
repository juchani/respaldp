
void pantalla() {
  if (ds18b20() < 10) {
    temp = ds18b20();
  }

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
