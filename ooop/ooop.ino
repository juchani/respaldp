class led {
  private:
    int e;
  public:
    parp(int t);
    est(int w);
};
led::parp(int t){
  digitalWrite(e, HIGH);
  delay(t);
  digitalWrite(e, LOW);
  delay(t);
}
led::est(int w){
    e = w;
  pinMode(e, OUTPUT);
}
led e;
void setup() {
  e.est(2);

}

void loop() {
  e.parp(100);
}
