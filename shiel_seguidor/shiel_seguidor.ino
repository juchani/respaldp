int buzzer=12;
int estado=0;
int l=0;
void setup() {
  
    pinMode(buzzer,INPUT);
 
  Serial.begin(9600);
}

void loop() {
l=digitalRead(buzzer);
Serial.print(estado);
Serial.print('\t');
Serial.println(l);
delay(250);


}
