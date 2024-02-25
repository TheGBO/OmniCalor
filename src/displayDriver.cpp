#include "displayDriver.h"

DisplayDriver::DisplayDriver(Adafruit_SSD1306 afDisplay)
{
    display = afDisplay;
}

void DisplayDriver::ShowMessageMS(String msg, int ms, int fontSize)
{
    ShowMessage(msg, fontSize);
    delay(ms);
    display.clearDisplay();
    display.display();
}

void DisplayDriver::ShowMessage(String msg, int fontSize)
{
    display.clearDisplay();
    display.setTextSize(fontSize);
    display.setCursor(0,8);
    display.println(msg);
    display.display();
}

void DisplayDriver::InitDisplayDriver()
{
    display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
    display.clearDisplay();
    display.display();
    display.setTextColor(WHITE);
}