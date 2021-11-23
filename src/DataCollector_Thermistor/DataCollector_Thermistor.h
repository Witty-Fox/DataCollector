#include "Constants.h"
#include "Arduino.h"
#include "TypesDefines.h"

class DataCollector_Thermistor
{
public:
    void begin(int pin, int res = DEFAULT_THERM_RES_VALUE);
    void begin(int pin, int res, int maxAdc, int voltage);
    void setMaxAdc(int maxAdc);
    void setRefVoltage(int voltage);
    int readRaw();
    float readTemperature(TemperatureFormat format = TEMP_C);

private:
    int _pin;
    int _res;
    int _maxAdc;
    int _refVoltage;
};