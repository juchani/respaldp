void rest(){
  DateTime now = rtc.now();
  if(EEPROM.read(dir_new)<now.hour()){
  int resque=EEPROM.read(dir_contador);
  resque=resque+(EEPROM.read(dir_new)-now.hour());
  EEPROM.write(dir_contador,resque+1);}
 else{
  new_1=now.hour();
  old_1=now.hour();
  EEPROM.write(dir_new,new_1 );
  EEPROM.write(dir_old,old_1 );
}}

