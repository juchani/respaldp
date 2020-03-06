#define ENC_A 2
#define ENC_B 3
#define ENC_PORT PINB
#define boton 6
#include <EEPROM.h>
int estado;
char read_encoder();                                    //Função para leitura de Rotary Encoder
int dir=0;

unsigned char enc_A_prev = 0x00,
              counter    = 0x00,
              ctn_T2     = 0x00,
              flag_enc   = 0x01;


ISR(TIMER2_OVF_vect)
{
    TCNT2=178;          //178 Reinicializa o registrador do Timer2

    static unsigned int counter = 0; //this variable will be changed by encoder input
    int tmpdata;
    tmpdata = read_encoder();
    if( tmpdata ) 
    {
     // Serial.println(counter);
    contador(counter);  
      counter += tmpdata;
    }
 
 
    
} 
void setup() 
{

     
     Serial.begin(250000);  
     
     pinMode(ENC_A, INPUT);
     pinMode(ENC_B, INPUT);
     pinMode(13, OUTPUT);
     pinMode(boton,INPUT_PULLUP);
  
     TCCR2A = 0x00;   //Timer operando em modo normal
     TCCR2B = 0x07;   //Prescaler 1:1024
     TCNT2  = 178;    //~~ 5 ms para o overflow
     TIMSK2 = 0x01;   //Habilita interrupção do Timer2

} 
void loop() 
{estado=digitalRead(boton);
if(estado==0){
 EEPROM.write(dir, 1);

}
else{
  EEPROM.write(dir, 0);
  
}
 
  

} 

