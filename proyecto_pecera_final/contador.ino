void contado() {
  DateTime now = rtc.now();
  //  Serial.println(now.second(), DEC);
limite=EEPROM.read(dir_limite);
  contador=EEPROM.read(dir_contador);
  new_1=now.minute();
  EEPROM.write(dir_new,new_1);
  Serial.print(EEPROM.read(dir_old));
  Serial.print('\t');
  Serial.print(EEPROM.read(dir_new));
  Serial.print('\t');
  Serial.println(contador);
  if (EEPROM.read(dir_new) != EEPROM.read(dir_old)) {
    EEPROM.write(dir_old, new_1);
    contador++ ;
    //delay(1000);
    EEPROM.write(dir_contador,contador);
    Serial.println(contador);
  }
  if (EEPROM.read(dir_contador) == limite) {

    Serial.println("secuencia");
lcd.clear();
lcd.setCursor(4,1);
     lcd.print(" INICIANDO.... ");
     lcd.setCursor(0,1);
   secuencia();
     
   contador = 0;
   EEPROM.write(dir_contador,contador);


  }
  delay(700);
}
<<<<<<< HEAD

=======

>>>>>>> 941ca59634530a6110725808d796cfe22c1cd89d
