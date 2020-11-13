#include <Wire.h>
#include <ESP8266WiFi.h>
#include "MAX30100_PulseOximeter.h"
#define REPORTING_PERIOD_MS     1000
#include "ThingSpeak.h"
#include "secrets.h"


char ssid[] = SECRET_SSID;   // your network SSID (name)
char pass[] = SECRET_PASS;   // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)
WiFiClient  client;
String myStatus = "";
unsigned long myChannelNumber = SECRET_CH_ID;
const char * myWriteAPIKey = SECRET_WRITE_APIKEY;
PulseOximeter pox;

uint32_t tsLastReport = 0;
void onBeatDetected()
{
  Serial.println("Beat!");
}

void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);  // Initialize ThingSpeak
  Serial.print("Initializing pulse oximeter..");

  if (!pox.begin()) {
    Serial.println("FAILED");
    for (;;);
  } else {
    Serial.println("SUCCESS");
  }


  pox.setOnBeatDetectedCallback(onBeatDetected);
    if (WiFi.status() != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(SECRET_SSID);
    while (WiFi.status() != WL_CONNECTED) {
      WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected.");
  }
}

void loop()
{

  //  ThingSpeak.setField(3, number3);

  pox.update();
  if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
    Serial.print("Heart rate:");
    Serial.println(pox.getHeartRate());


    tsLastReport = millis();
  }


}

void estado() {
  ThingSpeak.setStatus(myStatus);

  // write to the ThingSpeak channel
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if (x == 200) {
    Serial.println("Channel update successful.");
  }
  else {
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
  ThingSpeak.setField(2, pox.getHeartRate());




  // delay(2000); // Wait 20 seconds to update the channel again


}
