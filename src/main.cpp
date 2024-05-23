#include "main.h"

Adafruit_SSD1306* display = new Adafruit_SSD1306(128, 64);
DisplayDriver* displayDriver;
ThermistorDriver* thermistorDriver;

int analogThermistorValue;
unsigned int temperatureScale = 0;
float currentTemperature;
char temperatureBuffer[8];
char temperatureSymbol[3] = {'C', 'K', 'F'};

unsigned long currentTime = 0;
unsigned long previousTime = 0;

void setup()
{
    Serial.begin(9600);
    //set up digital ports
    pinMode(ACTION_BTN_PIN, INPUT);

    //set up the drivers
    displayDriver = new DisplayDriver(display);
    thermistorDriver = new ThermistorDriver(10000);
    displayDriver->InitDisplayDriver();
    displayDriver->ShowMessageMS("Termometro OmniCalor", 1000);
    displayDriver->ShowMessageMS("Dica: aperte o\ntermistor para medir \n temperatura corporal", 5000, 1);
    display->clearDisplay();
    delay(2000);
}

void loop()
{
    if(digitalRead(ACTION_BTN_PIN) == HIGH)
    {
        ChangeTemperatureScale();
        Serial.println("button pressed.");
    }

    //Calculate time for display refresh delay
    currentTime = millis();
    if(currentTime - previousTime >= TEMPERATURE_REFRESH_MS)
    {
        DisplayTemperature();
        previousTime = currentTime;
    }
       
}

void DisplayTemperature()
{
    analogThermistorValue = analogRead(THERMISTOR_PIN);
    switch (temperatureScale)
    {
    case 0:
        currentTemperature = thermistorDriver->ReadCelsius(analogThermistorValue);
        break;

    case 1:
        currentTemperature = thermistorDriver->ReadKelvin(analogThermistorValue);
        break;

    case 2:
        currentTemperature = thermistorDriver->ReadFahrenheit(analogThermistorValue);
        break;
    }
    dtostrf(currentTemperature, 5, 1, temperatureBuffer);
    displayDriver->ShowMessage(String(temperatureBuffer) + " " + temperatureSymbol[temperatureScale], 3);
}

void ChangeTemperatureScale()
{
    temperatureScale++;
    if(temperatureScale > 2){
        temperatureScale = 0;
    }
}