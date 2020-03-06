#include <ESP8266WiFi.h>

// Wi-Fi Settings
const char* ssid = "juchani"; // your wireless network name (SSID)
const char* password = "kazeshini"; // your Wi-Fi network password

WiFiClient client;

// ThingSpeak Settings
const int channelID = 339816;
String writeAPIKey = "NN25TGYULMQU4Q7G"; // write API key for your ThingSpeak Channel
const char* server = "api.thingspeak.com";
const int postingInterval = 2 * 1000; // post data every 20 seconds

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void loop() {
  if (client.connect(server, 80)) {
    
    // Measure Signal Strength (RSSI) of Wi-Fi connection
    long rssi = WiFi.RSSI();

    // Construct API request body
    String body = "field1=";
           body += String(rssi);
    
    Serial.print("RSSI: ");
    Serial.println(rssi); 

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + writeAPIKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(body.length());
    client.print("\n\n");
    client.print(body);
    client.print("\n\n");

  }
  client.stop();

  // wait and then post again
  delay(postingInterval);
}
