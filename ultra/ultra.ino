int trig=3,echo=2;
void setup() {
Serial.begin(9600);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
digitalWrite(trig,LOW);
}

void loop() {
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
int tiempo=pulseIn(echo,HIGH);
int d=tiempo/59;
if(d>3){
Serial.println(d);  
}

delay(100);
 
}
