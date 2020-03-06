int ld1=12;
int ld2=11;
bool estatus=0;
void setup() {
  pinMode(ld1, OUTPUT);
   pinMode(ld2, OUTPUT);
}

void loop() {
 digitalWrite(ld1,estatus);
  digitalWrite(ld2,!estatus);
delay(100);
  estatus=!estatus;
}
