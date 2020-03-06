void secuencia(){

DateTime now = rtc.now();
lcd.clear();
   lcd.print("secuencia.....");
   sec.write(170);
   float d=EEPROM.read(dir_minuto) * 0.5;
   delay(d*1000); 
   sec.write(0);
   delay(100);
   digitalWrite(rl1,estatus);
   delay(1200);
   digitalWrite(rl1,!estatus);
  /* direccion.write(0);
   digitalWrite(rl1,estatus);
   delay(1200);
digitalWrite(rl1,!estatus);
lcd.clear();
   lcd.print("secuencia.....");
   sec.write(180);
   delay(d*1000); 
   sec.write(0);
   direccion.write(170);
   digitalWrite(rl1,estatus);
   delay(1200);
digitalWrite(rl1,!estatus);
direccion.write(0);
 */
   EEPROM.write(dir_ultima_hora,now.hour());
   EEPROM.write(dir_ultimo_min,now.minute());
   int h=EEPROM.read(dir_f);
   int s=EEPROM.read(dir_g);
   EEPROM.write(dir_dallas,h);
   EEPROM.write(dir_dht11,s);

   contador3 = 1;
   EEPROM.write(dir_contador,contador3);
}

