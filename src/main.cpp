#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <SPI.h>
#include <Adafruit_SSD1306.h>
#include "thermistor.h"



#define OLED_RESET 4
#define THERMISTOR_PIN A2

THERMISTOR thermistor(THERMISTOR_PIN, 100000, 3950, 100000);
Adafruit_SSD1306 display(OLED_RESET);

void ShowMessageForMS(String msg, int ms)
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,8);
  display.println(msg);
  display.display();
  delay(ms);
}


void setup()
{
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);
  
  ShowMessageForMS("Inicializando\nTermometro...", 1000);
  ShowMessageForMS("Capaz de medir\ntemperatura corporal e ambiente!", 5000);
  
  
}

void ThermistorFeedbackLoop()
{
  double temperature = thermistor.read() / 10;
  display.clearDisplay();
  display.setTextSize(3);
  display.setCursor(0,8);
  Serial.println(temperature);
  display.println(String(temperature) + " C");
  display.display();
  delay(500);
}

void loop()
{
  ThermistorFeedbackLoop();
}