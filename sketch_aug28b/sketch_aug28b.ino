
int c=0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(c);

delay(1000);
c+=5;
if(c==30){
c=0;  
}



}
