int motor1=11,motor2=10;
int add1,add2;
void setup() {
Serial.begin(9600);
pinMode(motor1,OUTPUT);
pinMode(motor2,OUTPUT);
}

void loop() {
add1=analogRead(A0);
add2=analogRead(A4);
add1=map(add1,0,1023,0,155);
add2=map(add2,0,1023,0,155);
analogWrite(motor1,add1);
analogWrite(motor2,add2); 
}






