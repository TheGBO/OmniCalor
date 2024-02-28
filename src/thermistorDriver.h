#pragma once
#include <Arduino.h>

#define c1 1.009249522e-03
#define c2 2.378405444e-04
#define c3 2.019202697e-07

/**
 * Warning:
 * The principle behind this code is not mine, it's based on the steinhart-hart equation
 * and on https://www.circuitbasics.com/arduino-thermistor-temperature-sensor-tutorial/
 */

class ThermistorDriver
{
private:
    //values that should be on the constructor
    float fixedResistorValue;
    //values that are used to calculate temperature
    float logResistance;
    float thermistorResistance;
    float kelvinTemperature;

public:
    ThermistorDriver(float fixedResistorValue);
    float ReadKelvin(int analogValue);
    float ReadCelsius(int analogValue);
};
