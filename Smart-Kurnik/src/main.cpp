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
#include <sensorsTask.h>
#include <powerJackTask.h>

#include "globalSettings.h"

#include <WiFi.h>

/// @brief Number of animls inside smart house
uint32_t numberOfAnimalsInside = 0;

void setup() {
  Serial.begin(921600);

  xTaskCreate(vSensorsTask, SENSORS_TASK_NAME, SENSORS_TASK_STACK_SIZE,
              NULL, SENSORS_TASK_PRIORITY, NULL);


  xTaskCreate(vPowerJackTask, POWER_JACK_TASK_NAME, POWER_JACK_TASK_STACK_SIZE,
              NULL, POWER_JACK_TASK_PRIORITY, NULL);


}

void loop() {

  
}