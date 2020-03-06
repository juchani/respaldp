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

ultrasonico s1,s2,s3;
void setup() {
s1.estatus(8,9);///trig,echo
s2.estatus(10,11);///trig,echo
s3.estatus(5,6);///trig,echo
Serial.begin(9600);
}

void loop() {
Serial.print(s1.ultra());
Serial.print('\t');
Serial.print(s2.ultra());
Serial.print('\t');
Serial.println(s3.ultra());
}
