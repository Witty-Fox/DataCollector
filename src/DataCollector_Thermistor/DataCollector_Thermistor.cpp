#include "DataCollector_Thermistor.h"

void DataCollector_Thermistor::begin(int pin, int res)
{
    pinMode(pin, INPUT);
    _pin = pin;
    _thermistorOffset = DEFAULT_THERM_OFFSET;
    _res = res;
    _maxAdc = DEFAULT_MAX_ADC_VALUE;
    _refVoltage = DEFAULT_MAX_VOLTAGE_VALUE;
}

void DataCollector_Thermistor::begin(int pin, float thermistorOffset, int res, int maxAdc, float voltage)
{
    pinMode(pin, INPUT);
    _pin = pin;
    _thermistorOffset = thermistorOffset;
    _res = res;
    _maxAdc = maxAdc;
    _refVoltage = voltage;
}

void DataCollector_Thermistor::setThermistorOffset(float offset)
{
    _thermistorOffset = offset;
}

void DataCollector_Thermistor::setMaxAdc(int adc)
{
    _maxAdc = adc;
}

void DataCollector_Thermistor::setRefVoltage(float voltage)
{
    _refVoltage = voltage;
}

int DataCollector_Thermistor::readRaw()
{
    return analogRead(_pin);
}

float DataCollector_Thermistor::readTemperature()
{
    if (_res == 0)
    {
        return -1;
    }
    int raw = readRaw();

    if (_temperatureFormat == TEMP_RAW)
    {
        return raw;
    }

    // calculating temperature using res
    float output_voltage, thermistor_resistance, therm_res_ln, temperature;
    output_voltage = raw;
    thermistor_resistance = _res * (4096.0 / (float)output_voltage - 1.0);                                                                  /* Resistance in ohms */
    therm_res_ln = log(thermistor_resistance);
    temperature =  (1.0 / (_thermistorOffset + (2.378405444e-04*therm_res_ln) + (2.019202697e-07*therm_res_ln*therm_res_ln*therm_res_ln))); /* Temperature in Kelvin */
    float temp_cel = temperature - 273.15;                                                                                                  /* Temperature in degree Celsius */

    return (_temperatureFormat == TEMP_C) ? temp_cel : cToF(temp_cel);
}

void DataCollector_Thermistor::setTemperatureFormat(TemperatureFormat format)
{
    _temperatureFormat = format;
}

float DataCollector_Thermistor::publish()
{
    return (_temperatureFormat == TEMP_RAW) ? readRaw() : readTemperature();
}

String DataCollector_Thermistor::prettyPublish()
{
    if (_temperatureFormat == TEMP_C)
    {
        return "Thermistor temperature (C): " + String(readTemperature());
    }
    else if (_temperatureFormat == TEMP_F)
    {
        return "Thermistor temperature (F): " + String(readTemperature());
    }
    else 
    {
        return "Thermistor (raw): " + String(readRaw());
    }
}
