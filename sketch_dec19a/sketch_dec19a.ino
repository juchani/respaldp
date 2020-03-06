
int c;

void setup() {
Serial.begin(9600);
attachInterrupt(0,contador,FALLING);
}

void loop() {
delay(1000); 
Serial.println(c);
c=0;
}
void contador(){
  c++;
}

