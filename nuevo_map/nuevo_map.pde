//ejemplo arduino -processing 
//desarrollado para MAKE IT YOURSELF por Juchani
//EL DOMINIO DE  ESTE CODIGO ES PUBLICO
// mas informacion en https://www.youtube.com/c/Juchani

import processing.serial.*;
Serial puerto;
int n=2;
float c;
float[] data = new float[n];
void setup() {
  puerto=new Serial(this, "COM12", 9600);// el puerto COM del arduino
  puerto.bufferUntil('\n');
  size(800, 600);
}

void draw() {
  background(0); 
  eje();
  //stroke(150, 0, 0, 0);
   noFill();
  strokeWeight(20);
stroke(255,0,0,100);
   arc(300,300,200,200,0,c);
   strokeWeight(10);
stroke(255,0,0,200);

   arc(300,300,200,200,0,c);
fill(255,0,0,100);
textSize(20);
text(int(data[0]),270,300);
    text("arc(x,y,x1,y1,inicio,fin)", 500, 400);
}



void serialEvent(Serial puerto) {
  String a=puerto.readString();
  data=float(split(a, ','));
  println(data[0]); 
 c=map(data[0],0,1023,0,PI*2); 
}