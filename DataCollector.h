/*
  DataCollector.h - Library for reading various sensors.
*/

#ifndef DataCollector_h
#define DataCollector_h

#include "Arduino.h"
#include "Adafruit_Si7021.h"

enum TemperatureFormat
{
  TEMP_C,
  TEMP_F
};

class DataCollector_LDR
{
    public:
    void begin(int pin, int res = 10000);
    int readRaw();
    float readLux();

    private:
    int _pin;
    int _res;
};

class DataCollector_Thermistor
{
  public:
  void begin(int pin, int res = 10000);
  int readRaw();
  float readTemp(TemperatureFormat format = TEMP_C);

  private:
  int _pin;
  int _res;
};

class DataCollector_Si7021
{
  public:
  int begin();
  float readTemp(TemperatureFormat format = TEMP_C);
  float readHum();
  // int enableHeater(bool state);

  private:
    Adafruit_Si7021 _sensor = Adafruit_Si7021();
};

#endif