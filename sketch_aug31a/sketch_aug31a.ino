int lectura;
void setup() {
  Serial.begin(9600);
  pinMode(8,INPUT);

}

void loop() {
  lectura=pulseIn(8,LOW);
 Serial.print(0 ); 
 Serial.print("  "); 

 Serial.println(lectura); 

}
