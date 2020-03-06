void menu() {
  int temp1 = analogRead(A7);
  temp1 = map(temp1, 0, 1023, 0, 12);
    int temp2 = analogRead(A6);
   temp2 = map(temp2, 0, 1023, -5,31 );
  boton1 = digitalRead(s1);
  boton2=digitalRead(s2);
lcd.setCursor(0,0);
lcd.print (temp1);
lcd.setCursor(5,1);
lcd.print (temp2);
  if (boton1 == HIGH) {
estado1=temp1;
limite=estado1;
lcd.setCursor(0,1);
lcd.print ("grabado....");
  }
  if(boton2==HIGH){
    estado2=temp2;
    lcd.print ("grabado....");
  }
}

