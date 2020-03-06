void contado() {
  DateTime now = rtc.now();
 
  contador3=EEPROM.read(dir_contador);
  EEPROM.write(dir_new,now.hour() );
  Serial.print(now.hour());
  Serial.print("  ");
   Serial.print(EEPROM.read(dir_old));
  Serial.print("  ");
  Serial.println(contador3);
  if (EEPROM.read(dir_new) != EEPROM.read(dir_old)) {
    EEPROM.write(dir_old,EEPROM.read(dir_new));
    contador3++ ;
    EEPROM.write(dir_contador,contador3);
    Serial.println(contador3);
  }
  if (EEPROM.read(dir_contador) >= EEPROM.read(dir_hora)) {

    Serial.println("secuencia");
   secuencia();
   delay(500);
    contador3 = 0;
   EEPROM.write(dir_contador,contador3);
  }
  delay(100);
}

