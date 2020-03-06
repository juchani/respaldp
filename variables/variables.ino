byte variable;
bool variable_1;
void setup() {
 Serial.begin(9600);
}

void loop() {
  //Serial.print(variable);
  Serial.print(" ");
  variable=variable +1;
  Serial.println(variable_1);
  //Serial.print("");
  variable_1++;
  delay(500);
}
