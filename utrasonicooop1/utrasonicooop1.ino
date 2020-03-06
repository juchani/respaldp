class ultrasonico{
 private:
 int t,e;
 float tiempo,distancia,velocidad=343.2;  
 public:
 float ultra();
 estatus(int trig, int echo);
};
 float ultrasonico::ultra(){
  digitalWrite(t,0);
  delayMicroseconds(2);
  digitalWrite(t,1);
  delayMicroseconds(10);
  digitalWrite(t,0);
  tiempo=pulseIn(e,HIGH)/2;
  distancia=velocidad*(tiempo/1000000)*100;
  if(distancia<180 && distancia>2){
  
  return distancia;}
  
}
 ultrasonico:: estatus( int trig ,int echo){
  t=trig;
  e=echo;
  pinMode(t,OUTPUT);
   pinMode(e,INPUT);
}

ultrasonico s1;
void setup() {
s1.estatus(3,2);///trig,echo
Serial.begin(9600);
pinMode(13,OUTPUT);
}

void loop() {
int se=s1.ultra();
Serial.println(se);
if (se<45){
  digitalWrite(13,1);
}
else
{
  digitalWrite(13,0);
}
  
}

