
/*
  Copyright (c) 2015 Giancarlo Bacchio. All right reserved.

  ESP8266TelegramBot - Library to create your own Telegram Bot using ESP8266.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
  */


#include "ESP8266TelegramBOT.h"


ESP8266TelegramBOT::ESP8266TelegramBOT(String token, String name, String username)	{
	_token=token;
	_name=name;
  _username=username;
}


void ESP8266TelegramBOT::begin(void)	{
	  message[0][0]="0";   // setup new messages
	  message[1][0]="";
	  getCookies();   // achieve the cookies necessary for communication with proxyssl
	  delay(3000);
}




/*********************************************************************************
 * GetCookie - function to achieve cookies from proxyssl                         *
 * (once per session you need a new set of cookies to communicate with proxyssl) *
 *********************************************************************************/

bool ESP8266TelegramBOT::getCookies(void)  { 

  Serial.println("GET Cookies");
  long now;
  bool avail;

  //Connect with www.proxyssl.org
 
  if (client.connect("174.127.102.163", 80)) {
  Serial.println(".... connected to server");
  

    String a ;
    char c;
    int ch_count=0;

    //First step: demand connection to www.proxyssl.org
    client.println("GET / HTTP/1.1\r\nHost: www.proxyssl.org\r\nConnection: keep-alive\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: it-IT,it;q=0.8,en-US;q=0.6,en;q=0.4\r\nCache-Control: max-age=0\r\nOrigin: http://www.proxyssl.org\r\nReferer: http://www.proxyssl.org/\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/44.0.2403.125 Safari/537.36\r\n\r\n");

    
    //Second step: receive the reply with the new Cookies
    a="";
    ch_count=0;
    sslCookies="";
    now=millis();
        avail=false;
        while (millis()-now<1500) {   // was 3000
            while (client.available()) {
                ch_count ++;
                c =  client.read();
                //Serial.write(c);
                a=a+c;
                if (ch_count>1) {
                  if (a.substring(ch_count-18)=="Set-Cookie: token="){
                    a="token=";
                    ch_count=5;
                  }
                }
                
                if (ch_count>1) {
                  if (a.substring(ch_count-14)=="Set-Cookie: s="){
                    a="; s=";
                    ch_count=3;
                  }
                }
                if (ch_count>5) {
                  if (a.substring(ch_count)==";") {
                  sslCookies=sslCookies+a.substring(0, ch_count);
                     a="";
                     ch_count=0;
                  }
                }
                avail=true;
            }
            if (avail) break;
        }
  }
  if (sslCookies!="") {
      Serial.print("sslCookies: ");
      Serial.println(sslCookies);
      Serial.println();
      return true;
  }
  else return false;
}




/**************************************************************************************************
 * ConnecToProxyssl - function to achieve connection to Proxyssl.org and send command to telegram *
 * (Argument to pass: command)                                                                    *
 **************************************************************************************************/

String ESP8266TelegramBOT::connectToProxyssl(String command)  {

    int tlength=command.length()+2;
    String textlength=String(tlength);
    String Location;
    String mess="";
    long now;
    bool avail;
    //Serial.println();
    //Serial.println(command);
    
    // Connect with www.proxyssl.org       
    if (client.connect("174.127.102.163", 80)) {
       // Serial.println(".... connected to server");
      
        String a="";
        char c;
        int ch_count=0;
    
        //First step: send telegram package to www.proxyssl.org
        client.print("POST /?do=search HTTP/1.1 \r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\nAccept-Encoding: gzip, deflate\r\nAccept-Language: it-IT,it;q=0.8,en-US;q=0.6,en;q=0.4\r\nCache-Control: max-age=0\r\nConnection: keep-alive\r\nContent-Length: "+textlength+"\r\nContent-Type: application/x-www-form-urlencoded\r\nCookie: "+sslCookies+"\r\nHost: www.proxyssl.org\r\nOrigin: http://www.proxyssl.org\r\nReferer: http://www.proxyssl.org/\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/44.0.2403.125 Safari/537.36\r\n\r\n");
        client.println("f="+command);

        //Second step: receive the reply with the address for message launch
        now=millis();
        avail=false;
        
        while (millis()-now<100) {  
            while (client.available()) {
                ch_count ++;
                c =  client.read();
                //Serial.write(c);
                a=a+c;
                if (ch_count>10) {
                    if (a.substring(ch_count-23)=="http://www.proxyssl.org"){
                        a="";
                        ch_count=0;
                    }
                }
                if (ch_count>14) {
                    if (a.substring(ch_count-14)=="Content-Length") {
                        Location=a.substring(0, ch_count-18);
                    }
                }
                avail=true;
            }
            if (avail) break;
        }
    }
  
    if (client.connect("174.127.102.163", 80)) {
        //Third step: launch the message through proxyssl and receive reply
        client.print("GET "+Location+" HTTP/1.1 \r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\nAccept-Encoding: gzip, deflate, sdch\r\nAccept-Language: it-IT,it;q=0.8,en-US;q=0.6,en;q=0.4\r\nCache-Control: max-age=0\r\nConnection: keep-alive\r\nCookie: "+sslCookies+"\r\nHost: www.proxyssl.org\r\nReferer: http://www.proxyssl.org/\r\nUpgrade-Insecure-Requests: 1\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/44.0.2403.125 Safari/537.36\r\n\r\n");
        now=millis();
        avail=false;
        while (millis()-now<1500) {   // was 3000
            while (client.available()) {
              char c = client.read();
              //Serial.write(c);
              mess=mess+c;
              avail=true;
            }
            if (avail) break;
        }
    }
    return mess;
}
  



/***********************************************************************
 * SendMessage - function to send message to telegram                  *
 * (arguments to pass: chat_id, text to transmit and markup(optional)) *
 ***********************************************************************/

void ESP8266TelegramBOT::sendMessage(String chat_id, String text, String reply_markup)  {

    bool sent=false;
  //  Serial.print("SEND Message ");
    long sttime=millis();
    while (millis()<sttime+8000) {    // loop for a while to send the message
        String command="https%3A%2F%2Fapi.telegram.org%2Fbot"+_token+"%2FsendMessage%3Fchat_id%3D"+chat_id+"%26text%3D"+text+"%26reply_markup%3D"+reply_markup;
        String mess=connectToProxyssl(command);
        int messageLenght=mess.length();
        for (int m=12; m<messageLenght+1; m++)      {
            if (mess.substring(m-10,m)=="{\"ok\":true")     {
                sent=true;
            }
        }
        if (sent==true)   {
          Serial.println("Message delivred");
          break;
        }
       
    }
    if (sent==false) Serial.println("Message not delivered");
}



/*******************************************************
 * SendMessage - function to send photo to telegram    *
 * (arguments: chat_id and photo url)                  *
 *******************************************************/

void ESP8266TelegramBOT::sendPhoto(String chat_id, String photo)  {

    bool sent=false;
    Serial.print("SEND Photo ");
    long sttime=millis();
    while (millis()<sttime+8000) {    // loop for a while to send the message
        String command="https%3A%2F%2Fapi.telegram.org%2Fbot"+_token+"%2FsendPhoto%3Fchat_id%3D"+chat_id+"%26photo%3D"+photo;
        String mess=connectToProxyssl(command);
        int messageLenght=mess.length();
        for (int m=12; m<messageLenght+1; m++)      {
            if (mess.substring(m-10,m)=="{\"ok\":true")     {
                sent=true;
            }
        }
        if (sent==true)   {
            Serial.println("Photo delivered");
            break;
        }
    }
    if (sent==false) Serial.println("Photo not delivered");
}
  



/***************************************************************
 * GetUpdates - function to receive all messages from telegram *
 * (argoument to pass: the last+1 message to read)             *
 ***************************************************************/

void ESP8266TelegramBOT::getUpdates(String offset)  {
    
    Serial.println("GET Update Messages ");
    String command="https%3A%2F%2Fapi.telegram.org%2Fbot"+_token+"%2FgetUpdates%3Foffset%3D"+offset;

      //recieve the final reply from telegram through proxyssl
    String mess=connectToProxyssl(command);
    int i=0;
    if (mess!="") {
            Serial.print("Sent Update request up to message: ");
            Serial.println(offset);
            String a="";
            int ch_count=0;
            String c;
            for (int n=1; n<mess.length()+1; n++) {
	              ch_count ++;
	              c =  mess.substring(n-1,n);
	              //Serial.print(c);
	              a=a+c;
	              if (ch_count>8) {
	                   if (a.substring(ch_count-9)=="update_id")  {
	                       message[i][0]=a.substring(0, ch_count-11);
	                       a=a.substring(ch_count-11);
	                       if (i>19) break;
	                       i ++;
	                       ch_count=11;
	                   }
	              }
            }
            message[i][0]=a.substring(0, ch_count);
    } 
    if (mess=="") {
        Serial.print("fialed to update");
        return;
    } 
    if (i==0) {
        Serial.println("no new messages");
        Serial.println();
        message[0][0]="0";  //returns how many valid messages are in the array 
    }
    else {
        message[0][0]=String(i);   //returns how many messages are in the array
        for (int b=1; b<i+1; b++)  {
          Serial.println(message[b][0]);
        }
        Serial.println();
        analizeMessages();
      //  Bot_replyMessages();
    }
} 




/******************************************************************************
 * AnalizeMessage - function to achieve message parameter from json structure *
 ******************************************************************************/

void ESP8266TelegramBOT::analizeMessages(void)     {

//(update_id, name_id, name, lastname, chat_id, text)
  int rif[6]= {0,0,0,0,0,0};

  for (int i=1; i<message[0][0].toInt()+1; i++)      {
    
    int messageLenght=message[i][0].length();
    String a=message[i][0];
    for (int m=12; m<messageLenght+1; m++)             {
        if (a.substring(m-12,m)=="\"update_id\":")     {
          rif[0]=m;
        }
        if (a.substring(m-13,m)=="\"from\":{\"id\":")  {
          rif[1]=m;
        }
        if (a.substring(m-14,m)=="\"first_name\":\"")  {
          rif[2]=m;
        }
        if (a.substring(m-13,m)=="\"last_name\":\"")   {
          rif[3]=m;
        }
        if (a.substring(m-13,m)=="\"chat\":{\"id\":")  {
          rif[4]=m;
        }
        if (a.substring(m-8,m)=="\"text\":\"")         {
          rif[5]=m;
        }
        for (int n=0; n<2; n++)     {
            if (a.substring(m-1,m)==",")  {
                if (rif[n]!=0)  {
                  message[i][n]=a.substring(rif[n],m-1);
                }
            rif[n]=0;
            }
        }
        if (a.substring(m-1,m)==",")  {
              if (rif[2]!=0)  {
                message[i][2]=a.substring(rif[2],m-2);
              }
          rif[2]=0;
        }
        if (a.substring(m-1,m)==",")  {
              if (rif[3]!=0)  {
                message[i][3]=a.substring(rif[3],m-3);
              }
          rif[3]=0;
        }
        if (a.substring(m-1,m)==",")  {
              if (rif[4]!=0)  {
                message[i][4]=a.substring(rif[4],m-1);
              }
          rif[4]=0;
        }
        if (a.substring(m-2,m)=="\"}")  {
            if (rif[5]!=0)  {
              message[i][5]=a.substring(rif[5],m-2);
            }
          rif[5]=0;
        }
    }
    int id=message[message[0][0].toInt()][0].toInt()+1;
    message[0][1]=id;
  }
}


