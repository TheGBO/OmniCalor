#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define OLED_ADDR 0x3c

class DisplayDriver
{
private:
    Adafruit_SSD1306 display;
public:
    DisplayDriver(Adafruit_SSD1306 afDisplay);
    void InitDisplayDriver();
    void ShowMessageMS(String msg, int ms, int fontSize);
    void ShowMessage(String msg, int fontSize);
};