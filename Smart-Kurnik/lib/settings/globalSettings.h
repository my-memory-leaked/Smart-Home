/**
 * @file globalSettings.h
 * @author Karol Pisarski(pisek.x@gmail.com)
 * @brief Global programme settings
 * @version 0.1
 * @date 2022-11-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

// Uncomment to get logs on serial
//#define DEBUG_SENSORS

#define PIN_IR_FRONT_SENSOR     12
#define PIN_IR_REAR_SENSOR      14

// RTOS
#define SENSORS_TASK_NAME           "SensorsTask"
#define SENSORS_TASK_STACK_SIZE     4096
#define SENSORS_TASK_PRIORITY       1