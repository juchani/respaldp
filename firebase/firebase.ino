#include <ArduinoJson.h>
#include <ESP8266WiFi.h>  
#include <FirebaseArduino.h>

// Firebase

#define FIREBASE_HOST "monitoreo-9a024.firebaseio.com"

#define FIREBASE_AUTH "hFUsPGZAaFttvFhpYdvjxK6CrCOo1GUw6g62u2lT"

// Wifi

#define WIFI_SSID "juchani"

#define WIFI_PASSWORD "kazeshini"


void setup()

{

Serial.begin(115200); //inicializa el puerto de salida a 115200

pinMode(LED_BUILTIN, OUTPUT);   //configurar el puerto interno como salida 
digitalWrite(LED_BUILTIN, HIGH);   //enciende el led interno

// conectando a la red wifi.

WiFi.begin(WIFI_SSID, WIFI_PASSWORD);  //conexión a la red wifi

delay(2000);   //espera la  conexión

Serial.println("Conectando…"); 

while (WiFi.status() != WL_CONNECTED)  //bucle para esperar la conexión

{

Serial.println(".");  //mientras pintamos un puntito que sacamos por consola

delay(3000);

}

Serial.println("Conectado");   // ya hemos conseguido conectar por wifi

Serial.println(WiFi.localIP());   // pintamos la ip asignada 

 

// Configurando conexión a firebase

Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);  //intentamos conectarnos a la base de datos Firebase con nuestras credenciales

//fin configuración

}

 

void loop()  //bucle principal

{

//leer estado en Firebase el valor del registro led  y observar que el valor recuperado al ser booleano se asigna directamente a la variables es booleana

bool isLedOn = Firebase.getBool("led"); // recuperamos el valor del objeto led de la sesión firebase

 

if (isLedOn)   // condicional  para decidir en función del valor recuperado de firebase si se enciende o no el led

{

digitalWrite(LED_BUILTIN, HIGH);  //encendemos el led 
Serial.println("LED ON "); 
delay(2000);

}

else

{

digitalWrite(LED_BUILTIN, LOW);    //apagamos el  led 
Serial.println("LED OFF");
delay(2000);

}

 

}
