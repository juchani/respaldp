float t;
void setup() {
Serial.begin(9600);
pinMode(8,OUTPUT);
}
void loop(){
t=temperatura();
if(t>50){
    digitalWrite(8,LOW);
}
if(t<35){
  digitalWrite(8,HIGH);
}
}
float  temperatura() {
  int value = analogRead(A0);
  float millivolts = (value / 1023.0) * 5000;
  float celsius = millivolts / 10; 
    Serial.println(celsius);
 return celsius; 
   delay(100);
}
