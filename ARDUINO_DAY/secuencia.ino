int secuencia(int tiempo,int tiempo2){
  digitalWrite(13,1);
  delay(tiempo);
  digitalWrite(13,0);
  delay(tiempo2);
valor=random(1,90);
EEPROM.write(direccion,valor);
return valor;
}

