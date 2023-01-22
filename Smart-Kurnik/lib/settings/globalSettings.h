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



#define NETWORK_SSID        "Pisek"
#define NETWORK_PASSWORD    "12345678"

// Time in seconds 
#define DOOR_OPEN_CLOSE_TIME        5

/********************************************/ 
// IR && TEMP

// Uncomment to get logs on serial
 #define DEBUG_SENSORS

#define PIN_DS18B20_TEMPERATURE_SENSOR      4

#define PIN_IR_FRONT_SENSOR     12
#define PIN_IR_REAR_SENSOR      14
/********************************************/ 
/********************************************/ 
// Power Jack

#define PIN_PWR_JACK_OPEN      17   // D1
#define PIN_PWR_JACK_CLOSE     16   // D0

/********************************************/ 
/********************************************/ 
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

/********************************************/ 
// Door sensors
#define PIN_FRONT_DOOR_SENSOR      27   
#define PIN_BACK_DOOR_SENSOR       26   


#define RECONNECT_TRIES             10  // Watch out uint8!!!!