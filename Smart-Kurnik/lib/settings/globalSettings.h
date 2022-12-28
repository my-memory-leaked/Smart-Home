/**
 * @file globalSettings.h
 * @author Karol Pisarski (pisek.x@gmail.com)
 * @brief Global programme settings
 * @version 0.3
 * @date 2022-12-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once


#define NETWORK_SSID        "Mickiewicza 166 2.4GHz"
#define NETWORK_PASSWORD    "221662316"

// Time in seconds 
#define DOOR_OPEN_CLOSE_TIME        5

/********************************************/ 
// IR && TEMP

/********************************************/ 
// IR

// Uncomment to get logs on serial
//#define DEBUG_SENSORS

#define PIN_DS18B20_TEMPERATURE_SENSOR      4

#define PIN_IR_FRONT_SENSOR     12
#define PIN_IR_REAR_SENSOR      14

// RTOS
#define SENSORS_TASK_NAME           "SensorsTask"
#define SENSORS_TASK_STACK_SIZE     4096
#define SENSORS_TASK_PRIORITY       2

/********************************************/ 
// Power jack

// RTOS
#define POWER_JACK_TASK_NAME           "PowerJackTask"
#define POWER_JACK_TASK_STACK_SIZE     2048
#define POWER_JACK_TASK_PRIORITY       2

/********************************************/ 
// Http
#define HTTP_TASK_NAME              "HttpTask"
#define HTTP_TASK_STACK_SIZE        6144
#define HTTP_TASK_PRIORITY          1

