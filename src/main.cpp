#include <Arduino.h>
#include "displayDriver.h"

Adafruit_SSD1306 displayInstance(OLED_RESET);
DisplayDriver* displayDriver;

void setup()
{
    Serial.begin(9600);

    displayDriver = new DisplayDriver(displayInstance);
    displayDriver->InitDisplayDriver();
    displayDriver->ShowMessageForMS("Ola mundo!", 1000);
}

void loop()
{

}