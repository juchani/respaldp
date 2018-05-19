void bluetooth(){
  if (BT1.available() > 0) {
    int reg = BT1.parseInt();
    int dato = BT1.parseInt();
    lcd.clear();
    if (reg > 0 && reg < 10 && dato > 0 && dato < 1000) {
     digitalWrite(5,HIGH);
     delay(500);
     digitalWrite(5,LOW);
     if(reg==1){
      lcd.setCursor(5,1);
      lcd.print("REGISTRANDO ");
     lcd.setCursor(6,2);
      lcd.print(dato);
      lcd.print(" HORA");
      EEPROM.write(dir_limite, dato);
     contador = 0;
   EEPROM.write(dir_contador,contador);
     }
     
     if(reg==2){
   lcd.setCursor(5,1);
   lcd.print("REGISTRANDO ");
   lcd.setCursor(5,2);
   lcd.print(dato);
   lcd.print(" SEGUNDOS");
      EEPROM.write(dir_relay, dato);
     }
     if(reg==3){
      lcd.setCursor(0,0);
      lcd.print("registrando");
      lcd.setCursor(0,1);
      lcd.print(dato);
      lcd.print(" minutos");
     }
     if(reg==4){
     lcd.setCursor(4,1);
     lcd.print(" INICIANDO.... ");
     lcd.setCursor(0,1);
      secuencia();
      contador = 0;
   EEPROM.write(dir_contador,contador);
     }
      Serial.print(reg);
      Serial.print('\t');
      Serial.println(dato);
    
    
    }
    else {
      Serial.println("ERROR");
      reg = 0;
      dato = 0;
    }
 delay(500);
  }

}

