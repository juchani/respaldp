int sub_proceso(){
  int var1=proceso1();
  delay (250);
  if(var1==2){
    define_cont=define_cont+1;
  a=2;
  return a;

  }
  if(var1==1){
    define_cont=define_cont-1;
  a=1;
  return a;
  }
  if(define_cont<1){
    define_cont=1;
    }
  if(var1==3){
    a=5;
    return a;
  }
  if(var1==4){
    a=5;
    return a;
  }
  
  
Serial.println(define_cont);
}

