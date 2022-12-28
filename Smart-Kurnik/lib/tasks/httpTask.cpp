/**
 * @file httpTask.cpp
 * @author Karol Pisarski (pisek.x@gmail.com)
 * @brief RTOS task file
 * @version 0.2
 * @date 2022-12-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "httpTask.h"
#include <WiFi.h>
#include <ESPAsyncWebServer.h>

// AsyncHTTPRequest async_request;
AsyncWebServer server(80);   //Port 80

// While confiuring smart house the door needs to be closed
bool isDoorOpened = false;
bool openDoor = false;
bool closeDoor = false;


String sendHTML(){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<title>Smart Domek</title>\n";
  ptr +="<meta charset=\"UTF-8\" name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n";
  ptr +="</head><body bgcolor = \"#434242\">\n";
  ptr +="<div id=\"information\" style=\"color:#22A39F; font-family: Georgia; font-size: 40px; margin: auto; text-align: center;\">\n";
  ptr +="<h4>Smart Domek</h4>\n";
  ptr +="</div>\n";
  ptr +="<div id = \"temperature\" style=\"color:#22A39F; font-family: Georgia; font-size: 20px; margin: auto; text-align: center; margin-top: 30px;\"> Temperatura wewnątrz domku: </div>\n";
  ptr +="<div id = \"temperatureReading\" style=\"color:#F3EFE0; font-family: Georgia; font-size: 25px; margin: auto; text-align: center;\"><span id=\"temperatureValue\">0</span>&degC</div>\n";
  ptr +="<br>\n";
  ptr +="<form action='/get' method='GET'style=\"display: flex; align-items: center; justify-content: center;\">\n";

  isDoorOpened ? ptr +="<button type='button submit' name='OFF' value='1' style=\"font-family: Georgia; margin: 12px; margin-top: auto; padding: 14px; height:px; background-color: green; color: black; border: none; border-radius: 50px;font-size: 14px\"><h4>Drzwi otwarte</h4></button>\n"
               : ptr +="<button type='button submit' name='OFF' value='1' style=\"font-family: Georgia; margin: 12px; margin-top: auto; padding: 14px; height:px; background-color: red; color: black; border: none; border-radius: 50px;font-size: 14px\"><h4>Drzwi zamknięte</h4></button>\n";
  
  ptr +="</form>\n";
  ptr += "<br>\n";
  ptr += "<div id=\"xd\" style=\"display: flex; margin: auto; text-align: center; ; justify-content: center; align-items: center;\">\n";
  ptr += "<form action='/get' method='GET'>\n";
  ptr += "<button type='button submit' name='OPEN' value='1' style=\"font-family: Georgia; background-color:#22A39F; border: none;border-radius: 4px; text-align: center; padding: 15px; float: left;\">Otwórz drzwi :)</button>\n";
  ptr += "<button type='button submit' name='CLOSE' value='1' style=\"font-family: Georgia; background-color:#22A39F; border: none;border-radius: 4px; margin-left: 50px; text-align: center; padding: 15px;float: auto\">Zamknij drzwi :(</button>\n";
  ptr += "</form>\n";
  ptr += "</div>\n";

  // <-------------------------JavaScrip------------------------->
  ptr+= "<script>setInterval(function() {getSensorData();}, 10);function getSensorData() {var xhttp = new XMLHttpRequest();xhttp.onreadystatechange = function() {if (this.readyState == 4 && this.status == 200) {document.getElementById(\"temperatureValue\").innerHTML = this.responseText;} }; xhttp.open(\"GET\", \"temperatureReading\", true); xhttp.send();}</script>";
  
  ptr += "</body>\n";
  ptr += "</html>\n";

  return ptr;
}

String processor(const String &var)
{
    // Can add there readings to display
    return String();
}

void notFound(AsyncWebServerRequest *request)
{
  request->send(404, "text/plain", "Not found");
}


void vHttpTask(void* parameters)  
{
  // Pin configuration
  Serial.println("Starting httpTask...");  
  WiFi.mode(WIFI_STA);
  WiFi.begin(NETWORK_SSID, NETWORK_PASSWORD);
  
  while (WiFi.status() != WL_CONNECTED) 
  {

    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // Print ESP Local IP Address
  Serial.println(WiFi.localIP());

  server.on("/temperatureReading", [](AsyncWebServerRequest *request)
  { 
    request->send(200, "text/plain", String(temperatureReadingC)); //Send sensor reading when there's a client ajax request
  }); 

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send_P(200, "text/html", sendHTML().c_str() , processor);
  });
 
  server.on("/get", HTTP_GET, [](AsyncWebServerRequest *request)
  { 

    if (request->hasParam("OPEN"))
    {
      Serial.println("Http request to Open Door!");
      openDoor = true;
      isDoorOpened = true;
    }
    else if (request->hasParam("CLOSE")) 
    {
      Serial.println("Http request to Close Door!");
      closeDoor = true;
      isDoorOpened = false;
    }
    request->redirect("/");
    //request->send_P(200, "text/html", sendHTML().c_str());
  });
 
  server.onNotFound(notFound);
  server.begin();
 

  for( ; ; ) 
  {

  

    vTaskDelay( 500 / portTICK_PERIOD_MS);    // 2 Hz
  } // for( ; ; )

} // vHttpTask
