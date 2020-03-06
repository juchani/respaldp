int ci;
int al;
void setup() {
Serial.begin(9600);
}

void loop() {
 ci=random(0,1024);
 Serial.print(ci);
 Serial.print('\t');
 al=map(ci,0,1024,0,256);
 Serial.print(al);
 Serial.print('\t');
 al=map(al,0,256,0,1024);
 Serial.println(al);
 delay(1000);
}
