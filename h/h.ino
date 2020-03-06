int a,b,c;
void setup() {
Serial.begin(9600);
Serial.setTimeout(5000);
}

void loop() {
if(Serial.available()>0){
a=Serial.parseInt();
b=Serial.parseInt();
c=Serial.parseInt();  
Serial.print(a);
Serial.print('\t');
Serial.print(b);
Serial.print('\t');
Serial.println(c);

}
 }



