void menu_principal(){
   DateTime now = rtc.now();
    lcd.setCursor(0,0);
    lcd.print(diasdelasemana[now.dayOfTheWeek()]);
    lcd.setCursor(10,0);
    lcd.print(' ');
    /*lcd.print(now.day());
    lcd.print("/");
    lcd.print(now.month());
    lcd.print("/");
   lcd.print(now.year());
lcd.setCursor(12,1);*/
    lcd.print(now.hour());
    lcd.print(':');
    lcd.print(now.minute());
    lcd.print(':');
    lcd.print(now.second());
    lcd.setCursor(0,1);
lcd.print("ALARMA CADA: ");
lcd.print(EEPROM.read(hor));
lcd.print(" HRS ");
lcd.setCursor(0,2);
lcd.print("DURACION: ");
lcd.print(EEPROM.read(dur));
lcd.print(" SEG ");
lcd.setCursor(0,3);
float f;   
float sensor=dallas_temperature();
lcd.print("SENSOR: ");
if(sensor>0 ||sensor<-0.1){
  f=sensor;
  lcd.print(f);
 lcd.print(" C");
  est=1;
  while(est1==1){
digitalWrite(buzzer,1);
delay(250);
digitalWrite(buzzer,0);
est1=0;  
}
}
else{
  lcd.print("DESCONECTADO");
while(est==1){
digitalWrite(buzzer,1);
delay(500);
digitalWrite(buzzer,0);
est=0;  
}
est1=1;
}
//f=0;
sensor=0;
}
<<<<<<< HEAD

=======

>>>>>>> 941ca59634530a6110725808d796cfe22c1cd89d
