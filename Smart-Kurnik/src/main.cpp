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
#include <ESPAsyncWebServer.h>


#define ssid "Mickiewicza 166 2.4GHz"
#define password "221662316"


//AsyncHTTPRequest async_request;
AsyncWebServer server(80);   //Port 80


long randomTemp = 0;

char indexHTML[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
  <title>Smart Domek</title>
  <meta charset="UTF-8" name="viewport" content="width=device-width, initial-scale=1">
  <script>
    function autoRefresh() {
    window.location = window.location.href;
    }
    setInterval('autoRefresh()', 2000);
  </script>
  </head><body bgcolor = "#434242">

  <div id="information" style="color:#22A39F; font-family: Georgia; font-size: 40px; margin: auto; text-align: center;">
  <h4>Smart Domek</h4>
  </div>

  <div id = "temperature" style="color:#22A39F; font-family: Georgia; font-size: 20px; margin: auto; text-align: center; margin-top: 30px;"> Temperatura wewnątrz domku: </div>  
  <div id = "temperatureReading" style="color:#F3EFE0; font-family: Georgia; font-size: 25px; margin: auto; text-align: center;"> %READINGS% </div>
  <br>
  <div id = "doorState" style="color:#22A39F; font-family: Georgia; font-size: 18px; margin: auto; text-align: center; margin-top: auto; margin-bottom: 10px;"> Aktualny stan drzwi: </div>  

  <form action='/get' method='GET'style="display: flex; align-items: center; justify-content: center;">
  <button type='button submit' name='OFF' value='1' style="font-family: Georgia; margin: 12px; margin-top: auto; padding: 14px; height:px; background-color: red; color: black; border: none; border-radius: 50px;font-size: 14px"><h4>Zamknięte</h4></button>
  </form>

  <br>
  <div id="xd" style="display: flex; margin: auto; text-align: center; ; justify-content: center; align-items: center;">
  <form action='/get' method='GET'>
  <button type='button submit' name='OPEN' value='1' style="font-family: Georgia; background-color:#22A39F; border: none;border-radius: 4px; text-align: center; padding: 15px; float: left;">Otwórz drzwi :)</button>
  <button type='button submit' name='CLOSE' value='1' style="font-family: Georgia; background-color:#22A39F; border: none;border-radius: 4px; margin-left: 50px; text-align: center; padding: 15px;float: auto">Zamknij drzwi :(</button>
  </form>   
  </div>
</body>
</html>
)rawliteral";




String processor(const String &var)
{

  if (var == "READINGS")
  {
    return String(randomTemp);
  }
     return String();
}

void setup()
{
    Serial.begin(921600);
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  // WiFi.softAPIP();
  //     delay(1000);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", indexHTML, processor);
  });


  server.begin();
}

void loop()
{
  randomTemp = random(-20,40);
  

//   AsyncClient client;   //Checking for incoming clients

//   if (client)                 
//   {                             
//     Serial.println("new client");        
//     String currentLine = "";                   //Storing the incoming data in the string
//     while (client.connected()) 
//     {            
//       if (client.available())                 //if there is some client data available
//       {                
//         char c = client.read();                //read a byte
//         Serial.print(c);
//           if (c == '\n')                      //check for newline character,
//           {                      
//            if (currentLine.length() == 0)      //if line is blank it means its the end of the client HTTP request
//            {     
//             client.print("<title>ESP32 Webserver</title>");
//             client.print("<body><h1>Hello World </h1>");
            
//             break;                            //Going out of the while loop
//            } 
//            else 
//            {   
//             currentLine = "";                //if you got a newline, then clear currentLine
//            }
//          } 
//          else if (c != '\r') 
//          {  
//           currentLine += c;                 //if you got anything else but a carriage return character,
//          }
//       }
//     }
//  }
    delay(1000);
}