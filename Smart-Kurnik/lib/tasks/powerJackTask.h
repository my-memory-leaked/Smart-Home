/**
 * @file powerJackTask.h
 * @author Karol Pisarski(pisek.x@gmail.com)
 * @brief RTOS task file
 * @version 0.1
 * @date 2022-11-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <Arduino.h>
#include <globalSettings.h>

extern bool isDoorOpened;
extern bool openDoor;
extern bool closeDoor;

/// @brief Power Jack / Relay contolling RTOS task
/// @param parameters Parameters passed to RTOS task
void vPowerJackTask(void* parameters);