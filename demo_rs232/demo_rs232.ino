
void setup() {
  Serial3.begin(9600);
  Serial.begin(9600);
}

void loop() {
  if (Serial3.available()) {
     char dato= Serial3.read();
     Serial.print(dato);
     if(dato=='$')
     {
      Serial.println("inicio");
     }
     else if(dato=='@')
     { Serial.println("dato");
      
     }
     else if(dato==0)
     { 
     Serial.println("contenido");
     }
     else if(dato==127)
     { 
     Serial.println("final");
      Serial3.write(0x24);
      Serial3.write(0x40);
      Serial3.write(0x00);
      Serial3.write(0x01);
      Serial3.write(0x01);
      Serial3.write(0x42);
      Serial3.write(0x7F);
     } 
     else if(dato=='y'){
     
     }
   else if(dato=='x'){
     
      }
       else if(dato=='m'){
      
     }
   else if(dato=='n'){
      
     }

  }

  delay(1); //pasusa de 1ms por ciclo
  
}
