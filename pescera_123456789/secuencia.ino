void secuencia(){
  myservo.write(0);
  delay(500);
  digitalWrite(motor,HIGH);
  espera=EEPROM.read(dur);
  delay(espera*1000);
  digitalWrite(motor,LOW);
  delay(500);
  myservo.write(170);
  
}
<<<<<<< HEAD

=======

>>>>>>> 941ca59634530a6110725808d796cfe22c1cd89d
