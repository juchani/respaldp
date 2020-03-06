void contado() {
  DateTime now = rtc.now();
  //  Serial.println(now.second(), DEC);

  contador=EEPROM.read(dir_contador);
  EEPROM.write(dir_new,now.second() );
  if (EEPROM.read(dir_new) != EEPROM.read(dir_old)) {
    EEPROM.write(dir_old, new_1);

    contador++ ;
    EEPROM.write(dir_contador,contador);
    Serial.println(contador);
  }
  if (EEPROM.read(dir_contador) == limite) {

    Serial.println("secuencia");
   
    contador = 0;
   EEPROM.write(dir_contador,contador);
  }
  delay(700);
}

