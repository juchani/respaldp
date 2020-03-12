/*  ----------------------------------------------------------------
    Proyecto introduccion clave
    por teclado matricial con LCD I2C
    
    Funciones de teclas:
    * Borra clave introducida y resetea
    # enciende o apaga la pantalla
    
    por Suso
    22/11/2015
    --------------------------------------------------------------------  
*/
  #include <Wire.h>
  /* Funcion de configuracion
    de pines del modulo LCD/I2C (Direccion,en,rw,rs,d4,d5,d6,d7,backlight,polaridad)*/
 
 
#include <Keypad.h>

const byte Filas = 4;     //Cuatro filas
const byte Cols = 4;    //Cuatro columnas

byte Pins_Filas[] = {9,8,7,6};   //Pines Arduino a los que contamos las filas.
byte Pins_Cols[] = {5,4,3,2};   // Pines Arduino a los que contamos las columnas.
//no utilizar los pines 1 y 0 para no interferir en Rx y Tx

char Teclas [ Filas ][ Cols ] = 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
char codigoSecreto[4] = {'2','2','5','5'}; // Aqui va el codigo secreto
// Para cambiar el tamaño de la clave, solo hay que cambiar el tamaño del array

int posicion=0; // necesaria para la clave
int clave=0; // para el LCD
int luz=0;  // para el LCD
int tiempo=0;  // para el LCD
int ledVerde=11; // pin para el LED verde
int ledRojo=12;  // pin para el LED rojo
int buzzer=10;  // pin altavoz

Keypad Teclado1 = Keypad(makeKeymap(Teclas), Pins_Filas, Pins_Cols, Filas, Cols);

void setup(){
Serial.begin(9600) ;
pinMode (ledVerde,OUTPUT);
pinMode (ledRojo, OUTPUT);
pinMode (buzzer, OUTPUT);
digitalWrite(ledRojo,HIGH);  // encendemos el LED rojo
digitalWrite(ledVerde, LOW);  // apagamos el verde

}

  
void loop(){
  
char pulsacion = Teclado1.getKey() ;  // leemos pulsacion
if (pulsacion != 0){  // Si el valor es 0 es que no se ha pulsado ninguna tecla

if (pulsacion != '#' && pulsacion != '*' && clave==0){  // descartamos almohadilla y asterisco
  
    Serial.print(pulsacion);  // imprimimos pulsacion
    tone(buzzer,350);  // tono de pulsacion
    delay(200);
    noTone(buzzer);
    
//--- Condicionales para comprobar la clave introducida -----------

if (pulsacion == codigoSecreto[posicion]){ // comparamos entrada con cada uno de los digitos, uno a uno
      posicion ++;  // aumentamos en uno el contador de posicion si es correcto el digito  

      }
      
if (posicion == 4){ // comprobamos que se han introducido los 4 correctamente
        
      digitalWrite (13,HIGH);  // encendemos LED
    ///  lcd.setCursor(0,0); // situamos el cursor el la posición 0 de la linea 0.
      //lcd.print("Clave correcta  "); // escribimos en LCD
      
      delay(200); // tono de clave correcta
      tone(buzzer,500);
      delay(100);
      noTone(buzzer);
      tone(buzzer,600);
      delay(100);
      noTone(buzzer);
      tone(buzzer,800);
      delay(100);
      noTone(buzzer);
      
//      lcd.setCursor(5,1); // cursor en la posicion 5, linea 1
      clave=1;  // indicamos que se ha introducido la clave
      digitalWrite(ledRojo,LOW);  // apagamos el LED rojo
      digitalWrite(ledVerde, HIGH);  // encendemos el verde 
        
      }

    if(clave==0){           // comprobamos que no hemos acertado
      tone(buzzer,70,500);  // para generar
      delay(250);           // tono de error
      noTone(buzzer);
      }
      }
    
    }
    }
//--- Condicionales para encender o apagar el LCD --------------

//---------------------------------------------------------------

//--- Condicionales para resetear clave introducida -------------  


