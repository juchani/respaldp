#include <RotaryEncoder.h>

RotaryEncoder encoder(A2, A3);
int virus =3;
int bacterias=7;
int paracitos=11; 
int espa=13;
int esp=8;
int est_v;
int est_b;
int est_p;
int est_e;
int est_ee;
int n=0;
int rst=0;
int r=0;
void setup()
{
  Serial.begin(9600);
  //Serial.println("SimplePollRotator example for the RotaryEncoder library.");
pinMode(virus,INPUT_PULLUP);
pinMode(bacterias,INPUT_PULLUP);
pinMode(paracitos,INPUT_PULLUP);
pinMode(esp,INPUT_PULLUP);
  // You may have to modify the next 2 lines if using other pins than A2 and A3
  PCICR |= (1 << PCIE1);    // This enables Pin Change Interrupt 1 that covers the Analog input pins or Port C.
  PCMSK1 |= (1 << PCINT10) | (1 << PCINT11);  // This enables the interrupt for pin 2 and 3 of Port C.
} // setup()



// The Interrupt Service Routine for Pin Change Interrupt 1
// This routine will only be called on any signal change on A2 and A3: exactly where we need to check.
ISR(PCINT1_vect) {
  encoder.tick(); // just call tick() to check the state.
}


// Read the current position of the encoder and print out when changed.
void loop()
{
  static int pos = 0;
int l;
  int newPos = encoder.getPosition();
  if (pos != newPos) {
    l=newPos;
    
    pos = newPos;
 Serial.print(l);
     Serial.print(",");
    Serial.println(n);
    if (newPos == 300)
      delay(6600);
  }
est_v=digitalRead(virus);
est_b=digitalRead(bacterias);
est_p=digitalRead(paracitos);  
est_e=digitalRead(esp);
 
if (est_v==false){
 n=1;
 rst=0;
 sec(l,n);
}
if (est_b==false){
 n=2;
 rst=0;
sec(l,n);
}
if (est_p==false){
 n=3;
 rst=0;
 sec(l,n);
}
if (est_e==false && r==0){
 n=n*2;
 rst=0;
 sec(l,n);
 r=1;
}
if(rst>5000 && rst<5002){
  n=0;
  sec(l,n);
  r=0;
}
delay(1);
rst++;

} 
void sec(int a,int b){
  Serial.print(a);
     Serial.print(",");
    Serial.println(b);
}

