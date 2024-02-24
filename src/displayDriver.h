#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <SPI.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4

class DisplayDriver
{
private:
    Adafruit_SSD1306 display;
public:
    DisplayDriver(Adafruit_SSD1306 afDisplay);
    void InitDisplayDriver(int address = 0x3c);
    void ShowMessageForMS(String msg, int ms);
};