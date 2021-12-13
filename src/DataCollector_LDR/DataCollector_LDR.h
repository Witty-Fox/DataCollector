#ifndef DataCollector_LDR_h
#define DataCollector_LDR_h

#include "Arduino.h"
#include "Constants.h"
#include "TypeDefines.h"
#include "DataCollector_base.h"

class DataCollector_LDR : public DataCollector_base
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
    void setPublishMode(LightFormat format);
    float publish();
    String prettyPublish();

private:
    int _pin;
    int _res;
    int _maxAdc;
    int _refVoltage;
    int _luxCalcScalar;
    int _luxCalcExp;
    LightFormat _publishFormat;
};

#endif