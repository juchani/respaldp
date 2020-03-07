/*******************************************************************
 *  this is a basic example of how to program a Telegram Bot       *
 *  using ESP8266TelegramBOT library                               *
 *                                                                 *
 *  open a conversation with the bot, he will echo your messages   *
 *                                                                 *
 *  written by Giacarlo Bacchio                                    *
 *******************************************************************/


#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266TelegramBOT.h>


ESP8266WiFiMulti wifiMulti;


// Initialize Telegram BOT
#define BOTtoken "77330665:AAEIHv4RJxPnygoKD8nZqLnlpmd4hq7iR7s"  //token of TestBOT
#define BOTname "EchoBot"
#define BOTusername "EchoBot_bot"
ESP8266TelegramBOT bot(BOTtoken, BOTname, BOTusername);


int Bot_mtbs=1000; //mean time between scan messages
long Bot_lasttime; //last time a scan of messages has been done
int Cook_mtbr = 20 * 60000; // time between Cookies refresh
long Cook_lasttime; //last time Cokies have been refreshed


void setup() {
  
    Serial.begin(115200);
    delay(2000);
  
    wifiMulti.addAP("xxxxxxxxxxxxxxxx", "xxxxxxxxxx");   //write here your ssid and password

	  Serial.println("Connecting Wifi");
    while (wifiMulti.run() != WL_CONNECTED) {
        Serial.print(".");
        delay(1000);
    }
    if(wifiMulti.run() == WL_CONNECTED) {
        Serial.println("");
        Serial.println("WiFi connected");
        Serial.println("IP address: ");
        Serial.println(WiFi.localIP());
    }

    bot.begin();      // launch Bot functionalities
}

void loop() {
   
 if (millis() > Bot_lasttime + Bot_mtbs)  {
    Serial.println("GetUpdates");
    bot.getUpdates(bot.message[0][1]);
    Bot_EchoMessages();
    Bot_lasttime = millis();
  }

  // Cookies need to be refreshed sometimes
  if (millis() > Cook_lasttime + Cook_mtbr)  {
    Serial.println("GetCookies");
    if (!bot.getCookies()) bot.getCookies(); 
    Cook_lasttime = millis();
  }
}


/********************************************
 * EchoMessages - function to Echo messages *
 ********************************************/   

void Bot_EchoMessages() {

  for (int i=1; i<bot.message[0][0].toInt()+1; i++)      {
          bot.sendMessage(bot.message[i][4], bot.message[i][5],"");
  }
  bot.message[0][0]="";     // stop analize messages
}






