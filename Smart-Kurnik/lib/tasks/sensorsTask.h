/**
 * @file sensorsTask.h
 * @author Karol Pisarski (pisek.x@gmail.com)
 * @brief RTOS task file
 * @version 0.2
 * @date 2022-11-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include <Arduino.h>
#include <globalSettings.h>


// IR encodement
#define CODE_FRONT_IR   0x00
#define CODE_REAR_IR    0x01

/// @brief IR front sensor reading
static uint32_t frontIRSensorState;
/// @brief IR rear sensor reading
static uint32_t rearIRSensorState;
/// @brief Number of animls inside smart house
extern uint32_t numberOfAnimalsInside;

/// @brief RTOS task responsible for controlling the interruptions
/// @param parameters Parameters passed to RTOS task
void vSensorsTask(void* parameters);