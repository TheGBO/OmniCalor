#include "displayDriver.h"

DisplayDriver::DisplayDriver(Adafruit_SSD1306 afDisplay)
{
    display = afDisplay;
}

void DisplayDriver::ShowMessageForMS(String msg, int ms)
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0,8);
    display.println(msg);
    display.display();
    delay(ms);
}

void DisplayDriver::InitDisplayDriver(int address)
{
    display.begin(SSD1306_SWITCHCAPVCC, address);
    display.clearDisplay();
    display.setTextColor(WHITE);
}