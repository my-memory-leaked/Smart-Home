/**
 * @file httpTask.h
 * @author Karol Pisarski (pisek.x@gmail.com)
 * @brief RTOS task file
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <Arduino.h>
#include <globalSettings.h>

/// Temperature inside smart house
extern int16_t randomTemp;

/// @brief RTOS task responsible for controlling the interruptions
/// @param parameters Parameters passed to RTOS task
void vHttpTask(void* parameters);