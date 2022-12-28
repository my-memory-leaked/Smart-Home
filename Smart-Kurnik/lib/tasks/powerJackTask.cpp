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


void vPowerJackTask(void* parameters)  {
  Serial.println("Starting powerJackTask...");  
  // Pin configuration

  for( ; ; ) {

    if (openDoor)
    {
      for (uint16_t i = 0; i < DOOR_OPEN_CLOSE_TIME; i++)
      {
        Serial.println("Opening Doors!!!");
        delay(1000);
      }
      openDoor = false;
      closeDoor = false;
      isDoorOpened = true;
    }
    else if (closeDoor) 
    {
      for (uint16_t i = 0; i < DOOR_OPEN_CLOSE_TIME; i++)
      {
        Serial.println("Closing Doors!!!");
        delay(1000);
      }
      isDoorOpened = false;
      openDoor = false;
      closeDoor = false;
    }

   
    vTaskDelay( 1000 / portTICK_PERIOD_MS);
  } // for( ; ; )

} // vPowerJackTask