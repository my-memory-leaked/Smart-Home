/**
 * @file main.cpp
 * @author Karol Pisarski (pisek.x@gmail.com)
 * @brief 
 * @version 0.2
 * @date 2022-11-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <Arduino.h>
#include "globalSettings.h"
#include <sensorsTask.h>
#include <httpTask.h>

int16_t randomTemp = 0;

void setup()
{
    Serial.begin(921600);
 
    xTaskCreate(vHttpTask, HTTP_TASK_NAME, HTTP_TASK_STACK_SIZE,
                NULL, HTTP_TASK_PRIORITY, NULL);

}

void loop()
{
 
  
  
    delay(1000);
}