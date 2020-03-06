#include <EEPROM.h>
#include <Servo.h>

Servo a;
Servo b;
int tiempo = 0;
int l;
int ll;
void setup() {
  Serial.begin(9600);
l=EEPROM.read(1);
ll=EEPROM.read(2);
  a.attach(5);
  b.attach(6);
  parar(l,ll);
  Serial.println(l);
  Serial.println(ll);
}

void adelante() {
  a.write(0);
  b.write(180);
}

void parar(int an,int sd) {
  a.write(an);
  // delay(150);
  b.write(sd);
  // delay(70);
}
void derecha() {
  b.write(180);
  a.write(180);
}
void izquierda() {
  b.write(0);
  a.write(0);
}
void atras() {
  a.write(180);
  b.write(0);
}

void loop() {

  if (Serial.available()) {
    char dato = Serial.read();
    if (dato == 'a')
    {
      adelante();
      tiempo = -100;

    }
    else if (dato == 'r')
    {
      atras();
      tiempo = 0;
      tiempo = -100;
    }
    else if (dato == 'd')
    {
      derecha();
      tiempo = 0;
    }
    else if (dato == 'i')
    {
      izquierda();
      tiempo = 0;
    }

    else if (dato == 'x')
    {
      l++;
      EEPROM.write(1, l);
Serial.println(l);
    }
    else if (dato == 'z')
    {
      l--;
      EEPROM.write(1, l);
   Serial.println(l);
    }
 else if (dato == 'b')
    {
      ll++;
      EEPROM.write(2, ll);
Serial.println(ll);
    }
    else if (dato == 'v')
    {
      ll--;
      EEPROM.write(2, ll);
   Serial.println(ll);
    }

  }
  if (tiempo < 1000) // 1000   cilcos de 1ms
  {
    tiempo = tiempo + 1;
  }
  else   //ya transcurrió 100ms (100ciclos)
  {
    parar(l,ll);
  }


  delay(1); //pasusa de 1ms por ciclo

}



