void control(){
  int conta1=ultrasonic.Ranging(CM);
  int conta2=ultrasonic1.Ranging(CM);
  if(contador<1){
    contador=1;
  }
  if(contador>15){
    contador=15;
  }
  
  if (conta1>20){
    ds=0;}
  
  if(conta1<=20){
    ds=1;
    contador--;
    
    Serial.print(contador);
    Serial.print(",");
    Serial.println("3");
 delay(2000);
  }
  if (conta2>20){
    ds1=0;
  }
  if(conta2<=20){
    ds1=1;
    contador++;
  
    Serial.print(contador);
    Serial.print(",");
    Serial.println("3");
  delay(2000);
  }
/*Serial.print(ds);
Serial.print("       ");
Serial.println(ds1);*/
}

