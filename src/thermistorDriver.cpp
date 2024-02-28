#include "thermistorDriver.h"

ThermistorDriver::ThermistorDriver(float fixedResistorValue)
{
    this->fixedResistorValue = fixedResistorValue;
}

float ThermistorDriver::ReadKelvin(int analogValue)
{
    this->thermistorResistance = this->fixedResistorValue * (1023.0 / (float)analogValue - 1.0);
    this->logResistance = log(thermistorResistance);
    this->kelvinTemperature = 1.0 / (c1 + c2 * logResistance + c3 * pow(logResistance, 3));
    return this->kelvinTemperature;
}

float ThermistorDriver::ReadCelsius(int analogValue)
{
    return ReadKelvin(analogValue) - 273.15;
}