#include <Arduino.h>
#include "displayDriver.h"
#include "thermistorDriver.h"
#define THERMISTOR_PIN A2

Adafruit_SSD1306* display = new Adafruit_SSD1306(128, 64);
DisplayDriver* displayDriver;
ThermistorDriver* thermistorDriver;

int analogThermistorValue;
float currentCelsius;
char celsiusBuffer[8];

void setup()
{
    Serial.begin(9600);



    displayDriver = new DisplayDriver(display);
    thermistorDriver = new ThermistorDriver(10000);
    displayDriver->InitDisplayDriver();
    displayDriver->ShowMessageMS("Termometro OmniCalor", 5000);
    displayDriver->ShowMessageMS("Dica: aperte o\ntermistor para medir \n temperatura corporal", 5000, 1);
    display->clearDisplay();
    delay(2000);
}

void loop()
{
    analogThermistorValue = analogRead(THERMISTOR_PIN);
    currentCelsius = thermistorDriver->ReadCelsius(analogThermistorValue);
    dtostrf(currentCelsius, 5, 2, celsiusBuffer);
    displayDriver->ShowMessage(String(celsiusBuffer) + " C", 3);
    delay(1000);
}