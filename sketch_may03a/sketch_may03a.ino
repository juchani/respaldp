char val;
int led=6;
void setup() {
 pinMode(led,OUTPUT);
 Serial.begin(9600);
}

void loop() {
while(Serial.available()){
  val=Serial.read();
}
 analogWrite(led,val);
}
