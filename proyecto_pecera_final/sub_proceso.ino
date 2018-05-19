int sub_proceso(){
  int var1=proceso1();
  delay (150);
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("SELECCIONAR");
  lcd.setCursor(9,1);
  lcd.print(define_cont);
  lcd.setCursor(5,2);
  lcd.print("3 HORA");
  lcd.setCursor(5,3);
  lcd.print("4 DURACION");
  if(var1==2){
    define_cont=define_cont+1;
  bip();
  a=2;
  return a;

  }
  if(var1==1){
    define_cont=define_cont-1;
  bip();
  a=1;
  return a;
  }
  if(define_cont<1){
    define_cont=1;
    }
  if(var1==3){
    EEPROM.write(dir_limite,define_cont);
    EEPROM.write(dir_contador,0);
    define_cont=0;
    a=5;
    return a;
  }
  if(var1==4){
    EEPROM.write(dir_relay,define_cont );
    EEPROM.write(dir_contador,0);
    define_cont=1;
    a=5;
    return a;
  }
  
  
Serial.println(define_cont);
}

