
int tiempo;
void setup() {
  Serial.begin(9600);
  pinMode(9, INPUT);
 
}

void loop() {

 tiempo = pulseIn(9, HIGH);

  Serial.println(tiempo);
  delay(100);
  
}
