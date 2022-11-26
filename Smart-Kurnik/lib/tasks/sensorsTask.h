/**
 * @file sensorsTask.h
 * @author Karol Pisarski(pisek.x@gmail.com)
 * @brief RTOS task file
 * @version 0.1
 * @date 2022-11-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include <Arduino.h>
#include <globalSettings.h>

/// @brief IR front sensor reading
static uint32_t frontIRSensorState;
/// @brief IR rear sensor reading
static uint32_t rearIRSensorState;

/// @brief RTOS task responsible for controlling the interruptions
/// @param parameters Parameters passed to RTOS task
void vSensorsTask(void* parameters);