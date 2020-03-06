class led {
  private:
    int e;

  public:
    parpadeo(int t);
    estatus(int w);
};
led::parpadeo (int t)
{
  digitalWrite(e, HIGH);
  delay(t);
  digitalWrite(e, LOW);
  delay(t);
}
led::estatus(int w) {
  e = w;
  pinMode(e, OUTPUT);
}
