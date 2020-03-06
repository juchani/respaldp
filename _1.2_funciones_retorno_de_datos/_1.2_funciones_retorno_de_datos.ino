int r;
void setup() {
Serial.begin(9600);
}

void loop() {
r=u();
Serial.println(r);
}

int u(){
  int o=analogRead(A0);
  return o;
}

