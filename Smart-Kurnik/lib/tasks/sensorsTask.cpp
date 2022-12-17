/**
 * @file sensorsTask.cpp
 * @author Karol Pisarski (pisek.x@gmail.com)
 * @brief RTOS task file
 * @version 0.2
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
  Serial.printf("[%u] Configured IR Reciever GPIO: %i\n", xTaskGetTickCount, PIN_IR_FRONT_SENSOR);
  #endif

  pinMode(PIN_IR_REAR_SENSOR, INPUT);     
  digitalWrite(PIN_IR_REAR_SENSOR, HIGH);    // Pull-up resistor

  #ifdef DEBUG_SENSORS
  Serial.printf("[%u] Configured IR Reciever GPIO: %i\n", xTaskGetTickCount, PIN_IR_REAR_SENSOR);
  #endif

  // States 00 if front 01 if rear
  uint8_t previousInterrupt = -1; 
  bool wentThrough = true;

  for( ; ; ) {

    frontIRSensorState = digitalRead(PIN_IR_FRONT_SENSOR);
    rearIRSensorState  = digitalRead(PIN_IR_REAR_SENSOR);

    if (frontIRSensorState)
        previousInterrupt = CODE_FRONT_IR;
    
    if (rearIRSensorState)
        previousInterrupt = CODE_REAR_IR;

    switch (previousInterrupt) {
      case CODE_FRONT_IR:
            // waits until animal crosses rear IR 
            while(!rearIRSensorState) { rearIRSensorState = digitalRead(PIN_IR_REAR_SENSOR); }
            previousInterrupt = -1;
            numberOfAnimalsInside++;
        break;
      case CODE_REAR_IR:
            // waits until animal crosses front IR 
            while(!frontIRSensorState) { frontIRSensorState = digitalRead(PIN_IR_FRONT_SENSOR); }
            previousInterrupt = -1;
            (numberOfAnimalsInside == 0) ? : numberOfAnimalsInside--;
        break;
      default:
        break;
    } // switch (previousInterrupt)

    
    #ifdef DEBUG_SENSORS
      frontIRSensorState ? Serial.printf("[] Front IR Sensor unbroken state: %u\n", frontIRSensorState) :
                           Serial.printf("[] Front IR Sensor broken state %u\n" , frontIRSensorState);
  
      rearIRSensorState ? Serial.printf("[] Rear IR Sensor unbroken state: %u\n", rearIRSensorState) :
                          Serial.printf("[] Rear IR Sensor broken state %u\n" , rearIRSensorState);
  
      Serial.printf("Animal counter: %u\n", numberOfAnimalsInside);
    #endif

    vTaskDelay( 500 / portTICK_PERIOD_MS);    // 2 Hz
  } // for( ; ; )

} // vSensorsTask