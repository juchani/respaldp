void checkPassword() {
  if (password.evaluate()) {
    display.clearDisplay();
    display.setTextColor( WHITE); // Draw 'inverse' text
    display.setTextSize(1);             // Normal 1:1 pixel scale
    display.setCursor(30, 20);            // Start at top-left corner
    display.println("CLAVE CORRECTA");
    display.display();
    bip2();
    delay(500);
    digitalWrite(relay, LOW);
  }
  else {
    display.clearDisplay();
    display.setTextColor(WHITE); // Draw 'inverse' text
    display.setTextSize(1);             // Normal 1:1 pixel scale
    display.setCursor(20, 20);            // Start at top-left corner
    display.println("CLAVE INCORRECTA");
    display.display();
    digitalWrite(relay, HIGH);
    bip1();
    bip1();
    delay(500);
    password.reset();
  }

}
