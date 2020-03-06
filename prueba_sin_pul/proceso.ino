int proceso(){
  sensor3 = digitalRead(pull1);
   sensor4 = digitalRead(pull2);
   sensor1 = digitalRead(pull3);
   sensor2 = digitalRead(pull4);
 if (sensor1==LOW){
  contr=1;
 }
 if (sensor2==LOW){
  contr=2;
 }
 if (sensor3==LOW){
  contr=3;
 }
  if (sensor4==LOW){
  contr=4;
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
 }
 if (sensor2==LOW){
  contr=2;
 }
 if (sensor3==LOW){
  contr=3;
 }
  if (sensor4==LOW){
  contr=4;
 }
 if(sensor1==HIGH && sensor2==HIGH && sensor3==HIGH && sensor4==HIGH){
 contr=0; 
 }
 
 return contr;
  
  contr=0;
 
}

