
bool estado; 
void setup() {
pinMode(13,OUTPUT);

}

void loop() {
estado=!estado;  
digitalWrite(13,estado);
delay(1000);
}
