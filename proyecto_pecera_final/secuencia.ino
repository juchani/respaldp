void secuencia(){
t=EEPROM.read(dir_relay);
  t=t*1000;
  digitalWrite(buzzer,1);
  digitalWrite(motor,0);
  delay(t);
  digitalWrite(buzzer,0);
 digitalWrite(motor,1);
}

