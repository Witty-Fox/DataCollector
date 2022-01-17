#include "DataCollector_LDR.h"

void DataCollector_LDR::begin(int pin, int res)
{
    pinMode(pin, INPUT);
    _pin = pin;
    _res = res;
    _maxAdc = DEFAULT_MAX_ADC_VALUE;
    _refVoltage = DEFAULT_MAX_VOLTAGE_VALUE;
    _luxCalcScalar = DEFAULT_LUX_SCALE_VALUE;
    _luxCalcExp = DEFAULT_LUX_EXP_VALUE;
    _publishFormat = DEFAULT_LDR_PUBLISH_FORMAT;
}

void DataCollector_LDR::begin(int pin, int res, int maxAdc, int voltage, float scalar, float exp)
{
    pinMode(pin, INPUT);
    _pin = pin;
    _res = res;
    _maxAdc = maxAdc;
    _refVoltage = voltage;
    _luxCalcScalar = scalar;
    _luxCalcExp = exp;
}

int DataCollector_LDR::readRaw()
{
    return analogRead(_pin);
}

void DataCollector_LDR::setMaxAdc(int adc)
{
    _maxAdc = adc;
}

void DataCollector_LDR::setRefVoltage(int voltage)
{
    _refVoltage = voltage;
}

void DataCollector_LDR::setLuxCalcScalar(float scalar)
{
    _luxCalcScalar = scalar;
}

void DataCollector_LDR::setLuxCalcExp(float exp)
{
    _luxCalcExp = exp;
}

float DataCollector_LDR::readLux()
{
    if (_res == 0)
    {
        return -1;
    }
    int raw = readRaw();

    // calculate lux using res
    float resistorVoltage, ldrVoltage, ldrResistance, ldrLux;
    resistorVoltage = (_refVoltage / _maxAdc) * raw;
    ldrResistance = (_refVoltage / resistorVoltage - 1)* _res;
    ldrLux = _luxCalcScalar * pow(ldrResistance, _luxCalcExp);

    return ldrLux;
}

void DataCollector_LDR::setPublishMode(LightFormat format)
{
    _publishFormat = format;
}

float DataCollector_LDR::publish()
{
    return (_publishFormat == LIGHT_LUX) ? readLux() : readRaw();
}

String DataCollector_LDR::prettyPublish()
{
    return (_publishFormat == LIGHT_LUX) ? "LDR (lux): " + String(readLux()) : "LDR (raw): " + String(readRaw());
}