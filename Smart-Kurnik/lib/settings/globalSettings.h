/**
 * @file globalSettings.h
 * @author Karol Pisarski(pisek.x@gmail.com)
 * @brief Global programme settings
 * @version 0.2
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once


#define NETWORK_SSID        "UPC7103205"
#define NETWORK_PASSWORD    "yvsmcjex8xGy"

// Uncomment to get logs on serial
//#define DEBUG_SENSORS

#define PIN_IR_FRONT_SENSOR     12
#define PIN_IR_REAR_SENSOR      14

// RTOS
#define SENSORS_TASK_NAME           "SensorsTask"
#define SENSORS_TASK_STACK_SIZE     4096
#define SENSORS_TASK_PRIORITY       2


#define HTTP_TASK_NAME              "HttpTask"
#define HTTP_TASK_STACK_SIZE        6144
#define HTTP_TASK_PRIORITY          1