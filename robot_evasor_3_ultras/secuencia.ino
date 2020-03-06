
void parar () {
  digitalWrite(M1_adelante, LOW);
  digitalWrite(M2_adelante, LOW);
  digitalWrite(M1_atras, LOW);
  digitalWrite(M2_atras, LOW);
}
void derecha(int tiempo){
  digitalWrite(M2_adelante, HIGH);
  digitalWrite(M1_atras, HIGH);
  delay(tiempo);
}
void izquierda(int tiempo){
  digitalWrite(M1_adelante, HIGH);
  digitalWrite(M2_atras, HIGH);
  delay(tiempo);
}
void adelante(){
  digitalWrite(M1_adelante, HIGH);
  digitalWrite(M2_adelante, HIGH);
}
void atras(){
  digitalWrite(M1_atras, HIGH);
  digitalWrite(M2_atras, HIGH);
}
