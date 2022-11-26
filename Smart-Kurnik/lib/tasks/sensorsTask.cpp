/**
 * @file sensorsTask.cpp
 * @author Karol Pisarski(pisek.x@gmail.com)
 * @brief RTOS task file
 * @version 0.1
 * @date 2022-11-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "sensorsTask.h"

void vSensorsTask(void* parameters)  {
  // Pin configuration
  Serial.println("Starting SensorsTask...");  
  pinMode(PIN_IR_FRONT_SENSOR, INPUT);     
  digitalWrite(PIN_IR_FRONT_SENSOR, HIGH);    // Pull-up resistor

  #ifdef DEBUG_SENSORS
  Serial.printf("[%u] Configured GPIO: %i\n", xTaskGetTickCount, PIN_IR_FRONT_SENSOR);
  #endif

  pinMode(PIN_IR_REAR_SENSOR, INPUT);     
  digitalWrite(PIN_IR_REAR_SENSOR, HIGH);    // Pull-up resistor

  #ifdef DEBUG_SENSORS
  Serial.printf("[%u] Configured GPIO: %i\n", xTaskGetTickCount, PIN_IR_REAR_SENSOR);
  #endif

  for( ; ; ) {

    frontIRSensorState = digitalRead(PIN_IR_FRONT_SENSOR);
    rearIRSensorState = digitalRead(PIN_IR_REAR_SENSOR);
    
    #ifdef DEBUG_SENSORS
    frontIRSensorState ? Serial.printf("[] Front IR Sensor unbroken state: %u\n", frontIRSensorState) :
                         Serial.printf("[] Front IR Sensor broken state %u\n" , frontIRSensorState);
    #endif

    
    vTaskDelay( 500 / portTICK_PERIOD_MS);
  } // for( ; ; )

} // vSensorsTask