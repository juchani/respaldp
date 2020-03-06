int r,g,b;
void setup() {
pinMode(r,OUTPUT);
pinMode(g,OUTPUT);
pinMode(b,OUTPUT);
}

void loop() {
color(2,8,9);
}
void color(int a,int b ,int c){
  analogWrite(r,a);
   analogWrite(g,b);
    analogWrite(b,c);
}

void color(int a,int b){
   analogWrite(r,a);
   analogWrite(g,b);
}
void color(int a){
   analogWrite(r,a);
}
