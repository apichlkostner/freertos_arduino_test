#include <Arduino.h>
#include "Arduino_FreeRTOS.h"

// define two tasks for Blink & AnalogRead
static void TaskBlinkLED(void *pvParameters);
static void TaskWriteSerial(void *pvParameters);

// nr of pin for led
const int led = 13;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  
  while (!Serial) {
    ; // wait for serial port to connect.
  }

  
  xTaskCreate(TaskBlinkLED, (const portCHAR *)"Blink",  128,  NULL, 2, NULL);
  xTaskCreate(TaskWriteSerial, (const portCHAR *)"WriteSerial",  128,  NULL, 1, NULL);

  vTaskStartScheduler();
}

void loop() {}

static void TaskBlinkLED(void *pvParameters)
{
  (void) pvParameters;

  for (;;)
  {
    digitalWrite(led, LOW);
    vTaskDelay( 1000 / portTICK_PERIOD_MS );
    digitalWrite(led, HIGH);
    vTaskDelay( 100 / portTICK_PERIOD_MS);
  }
}

static void TaskWriteSerial(void *pvParameters)
{
  (void) pvParameters;

  int cnt = 0;

  for (;;)
  {    
    Serial.println(cnt++);
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}
