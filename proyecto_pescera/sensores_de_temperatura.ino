void tmp36(){

 int value = analogRead(sensor1);
  float millivolts = (value / 1023.0) * 5000;
  float celsius = millivolts / 10; 
lcd.setCursor(0,1);
lcd.print("S1: "); 
lcd.print(celsius); 
lcd.print(" C°"); 
  
}
