/**
 * @file powerJackTask.cpp
 * @author Karol Pisarski(pisek.x@gmail.com)
 * @brief RTOS task file
 * @version 0.1
 * @date 2022-11-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <powerJackTask.h>



bool doorError = false;

void vPowerJackTask(void* parameters)  {
  Serial.println("Starting powerJackTask...");  
  // Pin configuration
  pinMode(PIN_PWR_JACK_OPEN, OUTPUT);  
  pinMode(PIN_PWR_JACK_CLOSE, OUTPUT);    
  digitalWrite(PIN_PWR_JACK_OPEN, LOW); 
  digitalWrite(PIN_PWR_JACK_CLOSE, LOW);


  for( ; ; ) {

    if (openDoor)
    {
      digitalWrite(PIN_PWR_JACK_OPEN, HIGH);
      for (uint16_t i = 0; i < DOOR_OPEN_CLOSE_TIME; i++)
      {
        Serial.println("Opening Doors!!!");
        delay(1000);
      }
      digitalWrite(PIN_PWR_JACK_OPEN, LOW);
      openDoor = false;
      closeDoor = false;
      isDoorOpened = true;
      frontDoorSensor ? doorError = true : doorError = false;
    }
    else if (closeDoor) 
    {
      digitalWrite(PIN_PWR_JACK_CLOSE, HIGH);
      for (uint16_t i = 0; i < DOOR_OPEN_CLOSE_TIME; i++)
      {
        Serial.println("Closing Doors!!!");
        delay(1000);
      }
      digitalWrite(PIN_PWR_JACK_CLOSE, LOW);
      isDoorOpened = false;
      openDoor = false;
      closeDoor = false;
      backDoorSensor ? doorError = true : doorError = false;
    }
   
    vTaskDelay( 1000 / portTICK_PERIOD_MS);
  } // for( ; ; )

} // vPowerJackTask