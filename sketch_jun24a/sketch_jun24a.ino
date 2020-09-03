
String a="hola mundo";
char b='h';
float c=10;
int d=10;
bool e=false;

void setup() {
Serial.begin(9600);
}
void loop() {  
  c=c+0.01;
Serial.println(c);
  
}
