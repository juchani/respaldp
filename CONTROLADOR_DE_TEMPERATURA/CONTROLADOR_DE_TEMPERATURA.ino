int cooler =8;
int peltiel =9;
void setup() {
pinMode(cooler,OUTPUT);
pinMode(peltiel,OUTPUT);
digitalWrite(peltiel,1);
  digitalWrite(cooler,1);
}

void loop() {
  digitalWrite(peltiel,0);
  delay(30000);
  digitalWrite(cooler,0);
 delay(60000);
  digitalWrite(peltiel,1);
delay(30000);  
  digitalWrite(cooler,1);

} 
