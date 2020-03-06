import processing.serial.*;
import interfascia.*;
GUIController i;
IFButton b1, b2, a1, a2;
IFLabel l;
Serial puerto;
int n=3, s=100, t, c,sp1=30,sp2=30,a=0;

float[] data = new float[n];
void setup() {
  puerto=new Serial(this, "COM12", 9600);// el puerto COM del arduino
  puerto.bufferUntil('\n');
  size(800, 600);
  i = new GUIController (this);
  b1 = new IFButton ("+", 730, 500, 30, 30);
  b2 = new IFButton ("-", 680, 500, 30, 30);
  a1 = new IFButton ("+", 90, 500, 30, 30);
  a2 = new IFButton ("-", 40, 500, 30, 30);
  a1.addActionListener(this);
  a2.addActionListener(this);
  b1.addActionListener(this);
  b2.addActionListener(this);
  i.add (b1);
  i.add (b2);
  i.add (a1);
  i.add (a2);
}
void draw() {
  background(0);
  eje();
  noFill();
  stroke(250,250,250,150);
  strokeWeight(25);
  arc(380, 400, 300, 300, PI, map(data[0], 0, 40, PI, PI*2));
  stroke(250, 0, 0,200);
  strokeWeight(25);
  arc(380, 400, 285, 285, PI, map(data[1], 0, 40, PI, PI*2));
  textSize(17);
  stroke(255,255,255,100);
  fill(255);
  text("Ambiente "+int(data[0])+" °C", 350, 400);
  text("Objeto "+int(data[1])+" °C", 350, 420);
  strokeWeight(15);
  point(335, 395);
   stroke(255,0,0,200);
  point(335, 413);  
textSize(12);
stroke(255,255,255);
text("SETPOINT t.ambiente "+sp2+" C°", 640, 490);
text("SETPOINT t.objeto "+sp1+" C°", 40, 490);
if(((sp1<int(data[1]))||(sp2<int(data[0])))&&(a==0)){
  saveFrame("cap-######.png");
 background(255);
 delay(1000);
 
 a=1;
}
if(((sp1>int(data[1]))&&(sp2>int(data[0])))){
a=0;
}
}

void serialEvent(Serial puerto) {
  String a=puerto.readString();
  data=float(split(a, ','));
}
void actionPerformed (GUIEvent i) {
  if (i.getSource() == a1) {
sp1++;
  } 
  if (i.getSource() == a2) {
  sp1--;
  }
  if (i.getSource() == b2) {
  sp2--;
  }
  if (i.getSource() == b1) {
  sp2++;
  }
}