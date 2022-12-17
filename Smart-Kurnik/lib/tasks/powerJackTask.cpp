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
  // Pin configuration
  //pinMode(PIN_RELAY_MODULE, OUTPUT);

  for( ; ; ) {

    // There will be added steering power jack via relay
    // digitalWrite(PIN_RELAY_MODULE, HIGH);   // Turn on relay
    // digitalWrite(PIN_RELAY_MODULE, LOW);    // Turn off relay
   
  } // for( ; ; )

} // vPowerJackTask