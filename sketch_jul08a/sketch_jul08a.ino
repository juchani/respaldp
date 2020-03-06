int var;
void setup() {
Serial.begin(9600);
pinMode(4,OUTPUT);
}

void loop() {
var=analogRead(A1);
var=map(var,0,1023,1023,0);
Serial.println(var);
if(var>100){
digitalWrite(4,0);  
}
if(var<100){
  digitalWrite(4,1);
}
}
