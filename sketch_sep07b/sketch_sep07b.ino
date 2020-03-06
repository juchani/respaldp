int mia=6;
int mib=5;
int mda=11;
int mdb=10;
int sensor1=9;
int sensor2=8;
int sensor3=7;
int buzzer=2;
int valor1;
int valor2;
int valor3;
int st=1;
int vel=200;
int y;
void setup() {
// put your setup code here, to run once:
pinMode(mia,OUTPUT);
pinMode(mib,OUTPUT);
pinMode(mda,OUTPUT);
pinMode(mdb,OUTPUT); 
pinMode(buzzer,OUTPUT);
pinMode(sensor1,INPUT);
pinMode(sensor2,INPUT); 
pinMode(sensor3,INPUT);
pinMode(12,INPUT);
y=vel;


digitalWrite(buzzer,1);
delay(1000);
digitalWrite(buzzer,0);
}

void loop() {
valor1=digitalRead(sensor1);
valor2=digitalRead(sensor2);
valor3=digitalRead(sensor3);
if(valor1==LOW && valor2==HIGH && valor3==LOW){
analogWrite(mia,vel);
analogWrite(mib,0);
analogWrite(mda,vel);
analogWrite(mdb,0);
//digitalWrite(buzzer,0);
}
if(valor1==HIGH && valor2==HIGH && valor3==LOW){

//parar();
analogWrite(mia,0);
analogWrite(mib,60);
analogWrite(mda,120);
analogWrite(mdb,0);
//delay(80);
//digitalWrite(buzzer,1);
}
if(valor1==HIGH && valor2==LOW && valor3==LOW){

//parar();
analogWrite(mia,0);
analogWrite(mib,60);
analogWrite(mda,130);
analogWrite(mdb,0);
//delay(80);
//digitalWrite(buzzer,1);
}
if(valor1==LOW && valor2==HIGH && valor3==HIGH){
//parar();
analogWrite(mia,130);
analogWrite(mib,0);
analogWrite(mda,0);
analogWrite(mdb,60);
//delay(80);
//digitalWrite(buzzer,1);
}
if(valor1==LOW && valor2==LOW && valor3==HIGH){
//parar();
analogWrite(mia,130);
analogWrite(mib,0);
analogWrite(mda,0);
analogWrite(mdb,60);
//delay(80);
//digitalWrite(buzzer,1);
}
}



void bip(){
  digitalWrite(buzzer,1);
delay(10);
digitalWrite(buzzer,0);
}
void parar(){
analogWrite(mia,0);
analogWrite(mib,1);
analogWrite(mda,0);
analogWrite(mdb,1);

}
