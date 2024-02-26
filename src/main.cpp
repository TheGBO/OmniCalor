#include <Arduino.h>
#include "displayDriver.h"

Adafruit_SSD1306* display = new Adafruit_SSD1306(128, 64);
DisplayDriver* displayDriver;

void setup()
{
    Serial.begin(9600);


    displayDriver = new DisplayDriver(display);
    displayDriver->InitDisplayDriver();
    displayDriver->ShowMessageMS("Hello, World!", 2000);
    display->clearDisplay();
    display->drawLine(0,0,90, 30, WHITE);
    display->display();
    delay(2000);
}

void loop()
{
    
}