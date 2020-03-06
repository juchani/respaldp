#include "DigiKeyboard.h"
int var=0;
int cont=0;
int limite=14;
int est=0;
void setup() {
 est=random(10,1000);
  while(cont<est){
    var=random(59,70);
 cont++;
  }
  cont=0;
}


void loop() {
  

  
  var=random(59,70);
  DigiKeyboard.println(var);
   
  DigiKeyboard.delay(50);
 DigiKeyboard.sendKeyStroke(0);
 /* cont++;
  if (cont>limite){
    DigiKeyboard.delay(5000);
    cont=0;
  }*/
}

