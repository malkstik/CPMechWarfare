#include <Arduino.h>
#include <PrintStream.h>
#include <FreeRTOS.h>
#include "taskshare.h"         // Header for inter-task shared data
#include "taskqueue.h"         // Header for inter-task data queues
#include "shares.h"            // Header for shares used in this project

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
