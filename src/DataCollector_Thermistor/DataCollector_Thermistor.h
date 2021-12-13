#ifndef DataCollector_Thermistor_h
#define DataCollector_Thermistor_h

#include "Constants.h"
#include "Arduino.h"
#include "TypeDefines.h"
#include "DataCollector_base.h"

class DataCollector_Thermistor : public DataCollector_base
{
public:
    void begin(int pin, int res = DEFAULT_THERM_RES_VALUE);
    void begin(int pin, int res, int maxAdc, int voltage);
    void setMaxAdc(int maxAdc);
    void setRefVoltage(int voltage);
    int readRaw();
    float readTemperature();
    void setTemperatureFormat(TemperatureFormat format);
    float publish();
    String prettyPublish();

private:
    int _pin;
    int _res;
    int _maxAdc;
    int _refVoltage;
    TemperatureFormat _temperatureFormat = TEMP_RAW;
};

#endif