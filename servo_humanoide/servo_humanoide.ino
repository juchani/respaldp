#include <Servo.h>
Servo pie1, pie2, rod1, rod2, cad1, cad2, hom1, hom2, bra1, bra2, man1, man2, cab;
void setup() {
  pie1.attach(2);
  pie2.attach(3);
  rod1.attach(4);
  rod2.attach(5);
  cad1.attach(6);
  cad2.attach(7);
  hom1.attach(8);
  hom2.attach(9);
  bra1.attach(10);
  bra2.attach(11);
  man1.attach(12);
  man2.attach(13);
  cab.attach(A0);
  parada();
  delay(3000);
  paso();
}

void loop() {


}
void parada () {
  pie1.write(110);
  pie2.write(90);
  rod1.write(90);
  rod2.write(90);
  cad1.write(80);
  cad2.write(100);
  hom1.write(160);
  hom2.write(0);
  bra1.write(100);
  bra2.write(70);
  man1.write(90);
  man2.write(90);
  cab.write(10);
  delay(15);
}
void venia() {
  pie1.write(110);
  pie2.write(90);
  rod1.write(90);
  rod2.write(90);
  cad1.write(90);//mas
  cad2.write(90);//menos
  delay(500);
  hom1.write(180);
  hom2.write(45);//mas
  delay(500);
  bra1.write(100);
  bra2.write(140);//mas
  delay(500);
  man1.write(90);
  man2.write(130);//mas
  cab.write(10);
  delay(15);
}
void paso() {
  //pie1.write(110);
  pie2.write(77);
  delay(500);
  cad1.write(130);//mas
  rod1.write(130);
  delay(500);
  pie2.write(90 );
  rod2.write(110);
  pie1.write(110);
  delay(500);
  //rod1.write(90);
  //cad1.write(80);
//////////////////parada
   pie1.write(110);
  pie2.write(90);
  rod1.write(90);
  rod2.write(90);
  cad1.write(70);//mas
  cad2.write(110);//menos
    delay(500); 
parada();
}

