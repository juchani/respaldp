int M1_adelante = 8;
int M1_atras = 9;
int M2_adelante = 12;
int M2_atras = 11;
int giro_normal=580;
int medio_giro=1160;
const int pinecho1 = 5;
const int pintrigger1 = 4;
const int pinecho2 = 7;
const int pintrigger2 = 6;
const int pinecho3 = 3;
const int pintrigger3 = 2;
unsigned int tiempo1, distancia1,tiempo2, distancia2,tiempo3, distancia3;
int d3;
int d2;
int d1;
void setup() {
  pinMode(M1_adelante, OUTPUT);
  pinMode(M2_adelante, OUTPUT);
  pinMode(M1_atras, OUTPUT);
  pinMode(M2_atras, OUTPUT);
pinMode(pinecho1, INPUT);
  pinMode(pintrigger1, OUTPUT);
  pinMode(pinecho2, INPUT);
  pinMode(pintrigger2, OUTPUT);
  pinMode(pinecho3, INPUT);
  pinMode(pintrigger3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // ENVIAR PULSO DE DISPARO EN EL PIN "TRIGGER"
  digitalWrite(pintrigger1, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrigger1, HIGH);
  // EL PULSO DURA AL MENOS 10 uS EN ESTADO ALTO
  delayMicroseconds(10);
  digitalWrite(pintrigger1, LOW);

  // MEDIR EL TIEMPO EN ESTADO ALTO DEL PIN "ECHO" EL PULSO ES PROPORCIONAL A LA DISTANCIA MEDIDA
  tiempo1 = pulseIn(pinecho1, HIGH);

  // LA VELOCIDAD DEL SONIDO ES DE 340 M/S O 29 MICROSEGUNDOS POR CENTIMETRO
  // DIVIDIMOS EL TIEMPO DEL PULSO ENTRE 58, TIEMPO QUE TARDA RECORRER IDA Y VUELTA UN CENTIMETRO LA ONDA SONORA
  distancia1 = tiempo1 / 58;
  // ENVIAR PULSO DE DISPARO EN EL PIN "TRIGGER"
  digitalWrite(pintrigger2, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrigger2, HIGH);
  // EL PULSO DURA AL MENOS 10 uS EN ESTADO ALTO
  delayMicroseconds(10);
  digitalWrite(pintrigger2, LOW);

  // MEDIR EL TIEMPO EN ESTADO ALTO DEL PIN "ECHO" EL PULSO ES PROPORCIONAL A LA DISTANCIA MEDIDA
  tiempo2 = pulseIn(pinecho2, HIGH);

  // LA VELOCIDAD DEL SONIDO ES DE 340 M/S O 29 MICROSEGUNDOS POR CENTIMETRO
  // DIVIDIMOS EL TIEMPO DEL PULSO ENTRE 58, TIEMPO QUE TARDA RECORRER IDA Y VUELTA UN CENTIMETRO LA ONDA SONORA
  distancia2 = tiempo2 / 58;
  // ENVIAR PULSO DE DISPARO EN EL PIN "TRIGGER"
  digitalWrite(pintrigger3, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrigger3, HIGH);
  // EL PULSO DURA AL MENOS 10 uS EN ESTADO ALTO
  delayMicroseconds(10);
  digitalWrite(pintrigger3, LOW);

  // MEDIR EL TIEMPO EN ESTADO ALTO DEL PIN "ECHO" EL PULSO ES PROPORCIONAL A LA DISTANCIA MEDIDA
  tiempo3 = pulseIn(pinecho3, HIGH);

  // LA VELOCIDAD DEL SONIDO ES DE 340 M/S O 29 MICROSEGUNDOS POR CENTIMETRO
  // DIVIDIMOS EL TIEMPO DEL PULSO ENTRE 58, TIEMPO QUE TARDA RECORRER IDA Y VUELTA UN CENTIMETRO LA ONDA SONORA
  distancia3 = tiempo3 / 58;
  if (distancia1<200&&distancia1>1){
 d1=distancia1;
  }
  else{
    d1=200;
  }
   if (distancia2<200&&distancia2>1){
 d2=distancia2;
  }
  else{
     d2=200;
  }
   if (distancia3<200&&distancia3>1){
 d3=distancia3;
  }
  else{
    d3=200;
  }
   Serial.print(d3);
  Serial.print('\t');
  Serial.print(d2);
  Serial.print('\t');
  Serial.println(d1);
  secuencias(d1,d2, d3);
}


