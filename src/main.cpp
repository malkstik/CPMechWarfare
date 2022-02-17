#include <Arduino.h>
#include <PrintStream.h>
#include <FreeRTOS.h>
#include "taskshare.h"         // Header for inter-task shared data
#include "taskqueue.h"         // Header for inter-task data queues
#include "shares.h"            // Header for shares used in this project
#include "AX12A.h"
#include <BleGamepad.h>
#include <NimBLEDevice.h>
// Pin Declarations
/*
#define TurretPin = 
*/

// Queue and Share Declarations
/*
/// @brief Zen Garden x position data
Queue<float> xref(50, "X Data");

/// @brief Zen Garden y position data
Queue<float> yref(50, "Y Data");          

/// @brief Array of mostly zeros with just a one at the end to signify all data has been sent
Queue<uint8_t> data_NOTavail(50, "Data"); 
*/

//Task Scheduler
/*
void setup () 
{
    // Start the serial port, wait a short time, then say hello. Use the
    // non-RTOS delay() function because the RTOS hasn't been started yet
    Serial.begin (115200);
    delay (2000);
    Serial << endl << endl << "Initializing Mech MACHINE" << endl;

    xTaskCreate (task_control,
                 "data",
                 4096,                            // Stack size
                 NULL,
                 1,                               // Priority
                 NULL);

    xTaskCreate (task_control,
                 "control",
                 2048,                            // Stack size
                 NULL,
                 2,                               // Priority
                 NULL);

    // If using an STM32, we need to call the scheduler startup function now;
    // if using an ESP32, it has already been called for us
    #if (defined STM32L4xx || defined STM32F4xx)
        vTaskStartScheduler ();
    #endif
}

void loop() {}
*/

BleGamepad bleGamepad;
#define numOfButtons 10

void setup() 
{
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleGamepad.begin();
  // The default bleGamepad.begin() above is the same as bleGamepad.begin(16, 1, true, true, true, true, true, true, true, true, false, false, false, false, false);
  // which enables a gamepad with 16 buttons, 1 hat switch, enabled x, y, z, rZ, rX, rY, slider 1, slider 2 and disabled rudder, throttle, accelerator, brake, steering
  // Auto reporting is enabled by default. 
  // Use bleGamepad.setAutoReport(false); to disable auto reporting, and then use bleGamepad.sendReport(); as needed
}

void loop() 
{
  if(bleGamepad.isConnected()) 
  {
    Serial.println("Press all buttons one by one");
    for(int i = 1 ; i <= numOfButtons ; i += 1)
    {
      bleGamepad.press(i);
      bleGamepad.sendReport();
      delay(100);
      bleGamepad.release(i);
      bleGamepad.sendReport();
      delay(25);
    }
  }
}
   