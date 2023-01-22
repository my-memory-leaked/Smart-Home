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
#include <powerJackTask.h>

/// @brief Number of animls inside smart house
uint32_t numberOfAnimalsInside = 0;

void setup() 
{
    Serial.begin(921600);

    xTaskCreate(vSensorsTask, SENSORS_TASK_NAME, SENSORS_TASK_STACK_SIZE,
                NULL, SENSORS_TASK_PRIORITY, NULL);

    xTaskCreate(vHttpTask, HTTP_TASK_NAME, HTTP_TASK_STACK_SIZE,
                NULL, HTTP_TASK_PRIORITY, NULL);

    xTaskCreate(vPowerJackTask, POWER_JACK_TASK_NAME, POWER_JACK_TASK_STACK_SIZE,
                NULL, POWER_JACK_TASK_PRIORITY, NULL);

}


void loop()
{
    delay(1000);
}