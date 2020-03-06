void setup() {
  Serial.begin(9600);
}

void loop() {
  int  se1 = analogRead(A0);
  int  se2 = analogRead(A1);
  //se1=map(se1,0,1024,0,20);
  //se2=map(se2,0,1024,0,20);
  Serial.print(se1);
  Serial.print('\t');
  Serial.println(se2);


}
