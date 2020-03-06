void sub_menu0() {
  while (true) {
    contador, x_axis, boton = menu(120);
    if(contador==0){
      contador==1;
    }
    lcd.setCursor(0, 0);
    lcd.print("CAMBIAR SEGUNDOS");
    lcd.setCursor(2, 1);
    lcd.print("CADA ");
    lcd.print(contador*0.5);
    lcd.print(" SEG");
    delay(100);
    //lcd.clear();
    if (x_axis == 2) {
     delay(500);
      break;
    }
    if (boton == 0 || x_axis == 0) {

      EEPROM.write(dir_minuto, contador);
      lcd.clear();
      lcd.print(" GUARDADO.... ");
      lcd.setCursor(5, 1);
      lcd.print(contador*0.5);
      lcd.print(" SEG");
      delay(1000);
      //break;
    }
  }
}

void sub_menu1() {
  while (true) {
    contador, x_axis, boton = menu(12);
    if(contador==0){
      contador==1;
    }
    
    lcd.setCursor(2, 0);
    lcd.print("CAMBIAR HORA");
    lcd.setCursor(3, 1);
    lcd.print("CADA ");
    lcd.print(contador);
    lcd.print(" HRS");
    delay(100);
    //lcd.clear();
    if (x_axis == 2) {
     delay(250);
      break;
    }
    if (boton == 0 || x_axis == 0) {
//EEPROM.write(dir_m, contador);
      EEPROM.write(dir_hora, contador);
      lcd.clear();
      lcd.print(" GUARDANDO.....");
      lcd.setCursor(5, 1);
      lcd.print(contador);
      lcd.print(" HRS");
      delay(1000);
      //break;
    }
  }
}
void sub_menu2() {
  while (true) {
    contador, x_axis, boton = menu(15);
    //contador*=10;
    lcd.setCursor(0, 0);
    lcd.print("ENCENDER ALARMA ");
    lcd.setCursor(0, 1);
    lcd.print("MAYOR A  ");
    lcd.print(contador * 10);
    lcd.print(" CM   ");
    delay(100);
    //lcd.clear();
    if (x_axis == 2) {
      delay(250);
      break;
    }
    if (boton == 0 || x_axis == 0) {

      EEPROM.write(dir_ultra, contador * 10);
      lcd.clear();
      lcd.print(" GUARDANDO.....");
      lcd.setCursor(5, 1);
      lcd.print(contador * 10);
      lcd.print(" CM");
      delay(1000);
      //break;
    }
  }
}
void sub_menu3() {
  while (true) {
    contador, x_axis, boton = menu(15);
    //contador*=10;
    float dht_temp/*, dht_hum*/ = dht_11();
    float e = dallas_temperature();
    float f;
    float g;
    if (dht_temp > 5) {
      g = dht_temp;
    }
    if (e > 5) {
      f = e;
    }
    lcd.setCursor(0, 0);
    lcd.print("DHT 11 ");
    lcd.print(g);
    lcd.print(" C'");
    lcd.setCursor(0, 1);
    lcd.print("DALLAS ");
    lcd.print(f);
    EEPROM.write(dir_g,g);
    EEPROM.write(dir_f,f);
    lcd.print(" C'");
    //delay(1000);
   // lcd.clear();
   // lcd.setCursor(0, 0);
   // lcd.print("HUMEDAD ");
  //  lcd.print(dht_hum);
  //  lcd.print(" % ");
  //  delay(1000);
  //  lcd.clear();
    if (x_axis == 2) {
     delay(250);
      break;
    }
  }
}
void sub_menu4() {
  while (true) {
    contador, x_axis, boton = menu(2);
    if (contador==0){
      lcd.setCursor(0,0);
      lcd.print("ULTIMA SECUENCIA");
      lcd.setCursor(0,1);
      lcd.print(EEPROM.read(dir_ultima_hora));
      lcd.print(":");
      lcd.print(EEPROM.read(dir_ultimo_min));
      delay(250);
      lcd.clear();
    }
    if (contador==1){
      lcd.setCursor(0,0);
      lcd.print("DALLAS: ");
      lcd.print(EEPROM.read(dir_dallas));
      lcd.setCursor(0,1);
      lcd.print("DHT11: ");
      lcd.print(EEPROM.read(dir_dht11));
     delay(250);
      lcd.clear();
    }
    if (contador==2){
      lcd.setCursor(0,0);
      lcd.print("ultrasonico");
      lcd.setCursor(0,1);
      lcd.print("actual");
  delay(250);
      lcd.clear();
    }
    
    if (x_axis == 2) {
     delay(250);
      break;
    }
  }
}

