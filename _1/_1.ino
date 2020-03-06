int co = 0;
void setup() {
  Serial.begin(9600);


}

void loop() {
  delay(1000);
  co++;
  if (co < 5) {
    Serial.println(co);
  }
else if(co>=5)  {
    Serial.println(co * 10);
  }
else if(co>=5)  {
    Serial.println(co * 10);

  }
}
