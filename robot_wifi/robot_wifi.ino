#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

String command;             //String to store app command state.

const char* ssid = "MTM";
ESP8266WebServer server(80);
 
void setup() {
 
  Serial.begin(9600);
  
// Connecting WiFi

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid);

  IPAddress myIP = WiFi.softAPIP();
 
 // Starting WEB-server 
     server.on ( "/", HTTP_handleRoot );
     server.onNotFound ( HTTP_handleRoot );
     server.begin();    
}


void loop() {
    server.handleClient();
      command = server.arg("State");
      //Serial.println(command); 
      if (command == "F")Serial.println("a");
      else if (command == "B")Serial.println("r") ;
      else if (command == "L")Serial.println("i");
      else if (command == "R")Serial.println("d") ;
      else if (command == "S")Serial.println("s") ;
}

void HTTP_handleRoot(void) {

if( server.hasArg("State") ){
//Serial.println(server.arg("State"));
  }
  server.send ( 200, "text/html", "" );
  delay(1);
}
