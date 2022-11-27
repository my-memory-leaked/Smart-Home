/**
 * @file main.cpp
 * @author Karol Pisarski(pisek.x@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <Arduino.h>
#include "globalSettings.h"
#include <sensorsTask.h>

#include <WiFi.h>

#define wifi_name "SSID"
#define wifi_pass "PASSWORD"

WiFiServer server(80);       //Port 80

void setup()
{
    Serial.begin(921600);
    // Let's connect to wifi network 
    Serial.print("Connecting to ");
    Serial.print(wifi_name);
    WiFi.begin(wifi_name, wifi_pass);       //Connecting to wifi network

    while (WiFi.status() != WL_CONNECTED) { //Waiting for the responce of wifi network
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("Connection Successful");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());         //Getting the IP address at which our webserver will be created
    Serial.println("Put the above IP address into a browser search bar");
    server.begin();                         //Starting the server
}

void loop()
{
 WiFiClient client = server.available();   //Checking for incoming clients

  if (client)                 
  {                             
    Serial.println("new client");        
    String currentLine = "";                   //Storing the incoming data in the string
    while (client.connected()) 
    {            
      if (client.available())                 //if there is some client data available
      {                
        char c = client.read();                //read a byte
        Serial.print(c);
          if (c == '\n')                      //check for newline character,
          {                      
           if (currentLine.length() == 0)      //if line is blank it means its the end of the client HTTP request
           {     
            client.print("<title>ESP32 Webserver</title>");
            client.print("<body><h1>Hello World </h1>");
            
            break;                            //Going out of the while loop
           } 
           else 
           {   
            currentLine = "";                //if you got a newline, then clear currentLine
           }
         } 
         else if (c != '\r') 
         {  
          currentLine += c;                 //if you got anything else but a carriage return character,
         }
      }
    }
 }
    delay(1000);
}