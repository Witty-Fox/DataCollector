#include "Constants.h"
#include "Arduino.h"

class DataCollector_LDR
{
public:
    void begin(int pin, int res = DEFAULT_LDR_RES_VALUE);
    void begin(int pin, int res, int maxAdc, int voltage, int scalar, int exp);
    void setMaxAdc(int maxAdc);
    void setRefVoltage(int voltage);
    void setLuxCalcScalar(int scalar);
    void setLuxCalcExp(int exp);
    int readRaw();
    float readLux();

private:
    int _pin;
    int _res;
    int _maxAdc;
    int _refVoltage;
    int _luxCalcScalar;
    int _luxCalcExp;
};