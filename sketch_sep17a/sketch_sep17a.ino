#include <Ultrasonic.h>

#include <QTRSensors.h>
#define NUM_SENSORS 5 // number of sensors used
#define NUM_SAMPLES_PER_SENSOR 4 // average 4 analog samples per sensor reading
#define EMITTER_PIN QTR_NO_EMITTER_PIN
#define m_i 9
#define m_d 10
#define pin_pwm_i 6
#define pin_pwm_d 11
Ultrasonic sensor1(5,8);
Ultrasonic sensor2(7,4);
QTRSensorsAnalog qtra((unsigned char[]) {3,4,5,6,7}, 
NUM_SENSORS, NUM_SAMPLES_PER_SENSOR, EMITTER_PIN);
unsigned int sensorValues[NUM_SENSORS];
unsigned int position=0;

int distancia1;
int distancia2;

int PinColorDerecha = 13;
int SalidaColorDERECHA = 0;
int VpromedioDerecha=0;

int PinColorIzquierda = 13;
int SalidaColorIzquierda = 0;
int VpromedioIzquierda=0;

int boton=12;
int valor_boton=0;
int buzzer=2;
int derivativo=0, proporcional=0,integral=0;
int salida_pwm=0,proporcional_pasado=0;
int velocidad=250;
float Kp=0.31, Kd=3, Ki=0.0001;
int linea=0;
void setup() {
// put your setup code here, to run once:
pinMode (boton,INPUT);
pinMode(buzzer,OUTPUT);
pinMode(m_i, OUTPUT);
pinMode(m_d, OUTPUT);
pinMode(pin_pwm_i , OUTPUT);
pinMode(pin_pwm_d, OUTPUT);
pinMode(PinColorDerecha, INPUT);
pinMode(PinColorIzquierda,INPUT);
for(int i=0; i< 40; i++){
digitalWrite(buzzer,HIGH);
delay(20);
qtra.calibrate();
digitalWrite(buzzer,LOW);
delay(20);
}
digitalWrite(buzzer,LOW);
delay(2000);
Serial.begin(9600);

for (int i=1; i<=40; i++){
SalidaColorDERECHA = pulseIn(PinColorDerecha, LOW);
SalidaColorIzquierda = pulseIn(PinColorIzquierda, LOW);
digitalWrite (buzzer,150);
delay (40);
digitalWrite (buzzer,0);
delay (40);
VpromedioDerecha=VpromedioDerecha+SalidaColorDERECHA;
VpromedioIzquierda=VpromedioIzquierda+SalidaColorIzquierda;
}

VpromedioDerecha=VpromedioDerecha/100;
VpromedioIzquierda=VpromedioIzquierda/100;
while (true){
int x=digitalRead(boton);
delay (100);
if (x==1){
analogWrite (buzzer,150);
delay(300);
analogWrite (buzzer,0);
delay(100);
break;
}
}
}

void loop() {
pid(linea, velocidad, Kp, Ki, Kd);
distancia1=sensor1.Ranging(CM);
distancia2=sensor2.Ranging(CM);
SalidaColorDERECHA = pulseIn(PinColorDerecha, LOW);
SalidaColorIzquierda = pulseIn(PinColorIzquierda, LOW);
if (VpromedioIzquierda+2 >= SalidaColorIzquierda && VpromedioIzquierda-2<= SalidaColorIzquierda){
motores(30,120);
delay(500);
}
else {
Serial.print("No Verde I");
Serial.println(" ");
}

if (VpromedioDerecha+2 >= SalidaColorDERECHA && VpromedioDerecha-2 <= SalidaColorDERECHA){
motores(120,30);
delay(500);
}
else {
Serial.print("No Verde d");
Serial.println(" ");
}

if(distancia2<15){
analogWrite(pin_pwm_i,0);
analogWrite(m_i,20);
analogWrite(pin_pwm_d,0);
analogWrite(m_d,20);
delay(1000);

while(distancia1>30){
//digitalWrite(buzzer,HIGH);
analogWrite(pin_pwm_i,0);
analogWrite(m_i,0);
analogWrite(pin_pwm_d,30);
analogWrite(m_d,0);
}
//digitalWrite(buzzer,LOW);
analogWrite(pin_pwm_i,30);
analogWrite(m_i,0);
analogWrite(pin_pwm_d,30);
analogWrite(m_d,0);
delay(500);
while(true){

if(distancia1>12){
analogWrite(pin_pwm_i,20);
analogWrite(m_i,0);
analogWrite(pin_pwm_d,0);
analogWrite(m_d,20);
}
if(distancia1<12){
analogWrite(pin_pwm_i,20);
analogWrite(m_i,0);
analogWrite(pin_pwm_d,20);
analogWrite(m_d,0);
}
qtra.readLine(sensorValues);
if(sensorValues[0]>700 || sensorValues[1]>700 || sensorValues[2]>700 || sensorValues[3]>700 || sensorValues[4]>700 ){
break;
}
}}

}
void pid(int linea, int velocidad, float Kp, float Ki, float Kd){

position = qtra.readLine(sensorValues);
Serial.println(position);
proporcional=(position) - 3500;
integral=integral + proporcional;
derivativo=(proporcional-proporcional_pasado);
if(integral>1000) integral=1000;
if(integral<-1000) integral=-1000;
salida_pwm =(proporcional*Kp) + (derivativo*Kd) + (integral*Ki);
if(salida_pwm>velocidad)salida_pwm = velocidad;
if(salida_pwm<-velocidad)salida_pwm=-velocidad;

if(salida_pwm<0){
motores(velocidad+salida_pwm, velocidad);
}
if(salida_pwm>0){
motores(velocidad, velocidad-salida_pwm);
}
proporcional_pasado=proporcional;
}
void motores(int motor_izq, int motor_der){
if(motor_izq >= 0){
digitalWrite(m_i,LOW);
analogWrite(pin_pwm_i,255-motor_izq);
}
else{
digitalWrite(m_i,LOW);
motor_izq = motor_izq*(-1);
analogWrite(pin_pwm_i,motor_izq);
}
if(motor_der >= 0){
digitalWrite(m_d,LOW);
analogWrite(pin_pwm_d,255-motor_der);
}
else{
digitalWrite(m_d,LOW);
motor_der = motor_der*(-1);
analogWrite(pin_pwm_d,motor_der);
}
}
