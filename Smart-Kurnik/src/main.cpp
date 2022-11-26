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


uint32_t numberOfAnimalsInside = 0;

void setup() {
  Serial.begin(921600);

  xTaskCreate(vSensorsTask, SENSORS_TASK_NAME, SENSORS_TASK_STACK_SIZE,
              NULL, SENSORS_TASK_PRIORITY, NULL);

 

}

void loop() {

}