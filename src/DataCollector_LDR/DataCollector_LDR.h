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
    void begin(int pin, int res, int maxAdc, int voltage, float scalar, float exp);
    void setMaxAdc(int maxAdc);
    void setRefVoltage(int voltage);
    void setLuxCalcScalar(float scalar);
    void setLuxCalcExp(float exp);
    int readRaw();
    float readLux();
    void setPublishMode(LightFormat format);
    float publish();
    String prettyPublish();

private:
    int _pin;
    int _res;
    int _maxAdc;
    float _refVoltage;
    float _luxCalcScalar;
    float _luxCalcExp;
    LightFormat _publishFormat;
};

#endif