/**
 * @file httpTask.cpp
 * @author Karol Pisarski (pisek.x@gmail.com)
 * @brief RTOS task file
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "httpTask.h"
#include <WiFi.h>
#include <ESPAsyncWebServer.h>

//temporary
extern int16_t randomTemp;

char indexHTML[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
  <title>Smart Domek</title>
  <meta charset="UTF-8" name="viewport" content="width=device-width, initial-scale=1">
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


void vHttpTask(void* parameters)  {
  // Pin configuration
  Serial.println("Starting httpTask...");  

  //AsyncHTTPRequest async_request;
  AsyncWebServer server(80);   //Port 80

  WiFi.begin(NETWORK_SSID, NETWORK_PASSWORD);
  

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // Print ESP Local IP Address
  Serial.println(WiFi.localIP());


 // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", indexHTML, processor);
  });
 

  server.begin();
 

  for( ; ; ) {

    randomTemp = random(-20,40);



   
    vTaskDelay( 500 / portTICK_PERIOD_MS);    // 2 Hz
  } // for( ; ; )

} // vHttpTask


