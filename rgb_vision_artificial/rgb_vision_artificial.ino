int rgb[] = {3, 5, 6};
void setup() {
  pinMode(rgb[0], OUTPUT);
  pinMode(rgb[1], OUTPUT);
  pinMode(rgb[2], OUTPUT);
}

void loop() {
analogWrite(rgb[0],255);
analogWrite(rgb[1],0);
analogWrite(rgb[2],0);
}
