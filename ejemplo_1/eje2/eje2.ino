/*este es un parrafo 
segundo ejemplo */
int w;
int s;
void setup() {
  Serial.begin(9600);
Serial.println("CURSO INICIAL DE ARDUINO ");
delay(1000);
}
void loop() {
 w = analogRead(A0);
s=analogRead(A3);


Serial.print(w);
Serial.print("     ");
Serial.println(s);

}
