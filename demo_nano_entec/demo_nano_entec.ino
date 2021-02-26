
String texto, d, fecha, nombre, id, orden, lab, lot, sn;
String igg, igm, igg_t, igg_n, igm_t, igm_n;
String comp;
bool st = 0;
int c;
void setup()
{
  Serial.begin(9600);
  Serial3.begin(9600);
}

void loop()
{
  updateSerial();

  delay(20);
}

void updateSerial()
{
  if (Serial3.available())
  {

    Serial.print(0);
    Serial.print(" ");
    String cero[11] = Serial3.readStringUntil(':');
cero[0].remove(0,30);
cero[1].remove(0,1);
cero[3].remove(2,20);
cero[4].remove(cero[4].length()-8,cero[4].length());

Serial.print(0);
    Serial.print(" ");
    Serial.println(cero[0]);
    Serial.print(1);
    Serial.print(" ");
    Serial.println(cero[1]);
    Serial.print(2);
    Serial.print(" ");
    Serial.println(cero[2]);
    Serial.print(3);
    Serial.print(" ");
    Serial.println(cero[3]);
    Serial.print(4);
    Serial.print(" ");
    Serial.println(cero[4]);  
    Serial.print(5);
    Serial.print(" ");
    Serial.println(cero[5]);
    Serial.print(6);
    Serial.print(" ");
    Serial.println(cero[6]);
    Serial.print(7);
    Serial.print(" ");
    Serial.println(cero[7]);
    Serial.print(8);
    Serial.print(" ");
    Serial.println(cero[8]);
    Serial.print(9);
    Serial.print(" ");
    Serial.println(cero[9]);
    Serial.print(10);
    Serial.print(" ");
    Serial.println(cero[10]);
    Serial.print(11);
    Serial.print(" ");
    Serial.println(cero[11]);

    c++;
    if (c > 11) {
      c = 0;
    }
  }
}
