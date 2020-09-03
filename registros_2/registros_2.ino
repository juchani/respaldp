#define led 13

void setup() {
pinMode(led,OUTPUT);
Serial.begin(9600);
TCCR1A=0;
TCCR1B=0;
TCCR1B=5;//|=(1<<CS10)|(1<<CS12);
Serial.println(TCCR1B);

TCNT1=0xC2F7;
TIMSK1|=(1<<TOIE1);
}

void loop() {
  // put your main code here, to run repeatedly:

}

ISR(TIMER1_OVF_vect){
  TCNT1=0xC2F7;
  digitalWrite(led,!digitalRead(led));
}
