int proceso(){
  sensor3 = digitalRead(pull1);
   sensor4 = digitalRead(pull2);
   sensor1 = digitalRead(pull3);
   sensor2 = digitalRead(pull4);
 if (sensor1==LOW){
  contr=1;
  //bip();
 }
 if (sensor2==LOW){
  contr=2;
 // bip();
 }
 if (sensor3==LOW){
  contr=3;
 // bip();
 }
  if (sensor4==LOW){
  contr=4;
  //bip();
 }

 
 return contr;
  
 // contr=0;
 
}
int proceso1(){
  sensor3 = digitalRead(pull1);
   sensor4 = digitalRead(pull2);
   sensor1 = digitalRead(pull3);
   sensor2 = digitalRead(pull4);
 if (sensor1==LOW){
  contr=1;
 // bip();
 }
 if (sensor2==LOW){
  contr=2;
 //bip();
 }
 if (sensor3==LOW){
  contr=3;
 // bip();
 }
  if (sensor4==LOW){
  contr=4;
 // bip();
 }
 if(sensor1==HIGH && sensor2==HIGH && sensor3==HIGH && sensor4==HIGH){
 contr=0; 
 }
 
 return contr;
  
  contr=0;
 
}

