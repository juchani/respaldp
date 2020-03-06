void mensaje (){

       digitalWrite(13, 1);
     delay (1000);
     digitalWrite(rl[0], LOW);
     digitalWrite(rl[1],LOW);
      Serial.println("AT+CMGF=1");                 // Activamos la funcion de envio de SMS
 delay(100);                                    // Pequeña pausa
// Serial.println("AT+CMGS=\"76388541\"");  // Definimos el numero del destinatario en formato internacional
 Serial.println("AT+CMGS=\"73647252\"");
 delay(100);                                    // Pequeña pausa
 Serial.print("Alarma Activada");                 // Definimos el cuerpo del mensaje
 delay(500);                                    // Pequeña pausa
 Serial.print(char(26));                      // Enviamos el equivalente a Control+Z 
 delay(100);                                    // Pequeña pausa
 Serial.println("");                          // Enviamos un fin de linea
 delay(100);   
     delay (1000);
     digitalWrite(rl[2],LOW); 
     delay (2000);
        
  //   inicio:
     digitalWrite(rl[0], LOW);
     digitalWrite(rl[1],LOW);
     digitalWrite(rl[2],LOW); 
     digitalWrite(rl[3],LOW); 
     delay (1000);
//     goto 1nicio;
    
  

}

