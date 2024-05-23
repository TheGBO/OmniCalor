#include <Arduino.h>
#include "displayDriver.h"
#include "thermistorDriver.h"

#define THERMISTOR_PIN A2
#define ACTION_BTN_PIN 2

#define TEMPERATURE_REFRESH_MS 1000

void DisplayTemperature();
void ChangeTemperatureScale();