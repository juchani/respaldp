int PUL=4; //define Pulse pin
int DIR=3; //define Direction pin
int t=0;
void setup() {
  pinMode (PUL, OUTPUT);
  pinMode (DIR, OUTPUT);
digitalWrite(DIR,LOW);
Serial.begin(9600);
}

void loop() {
    Serial.println(t);
    digitalWrite(PUL,HIGH);
    delayMicroseconds(t);
    digitalWrite(PUL,LOW);
    delayMicroseconds(t);
  t++;
  delay(500);

  
 
 }
