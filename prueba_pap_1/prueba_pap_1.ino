/*     Simple Stepper Motor Control Exaple Code
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
// defines pins numbers
const int stepPin = 21; 
const int dirPin = 20; 
 int bt1=8;
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(bt1,INPUT_PULLUP);
 
}
void loop() {
  if(digitalRead(bt1)==0){
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x <9500 ; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000);
  digitalWrite(dirPin,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x <9000 ; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500); 
  }  
  }
  
  
  delay(500);
} 
