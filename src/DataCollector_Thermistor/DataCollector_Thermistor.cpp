#include "DataCollector_Thermistor.h"

void DataCollector_Thermistor::begin(int pin, int res)
{
    pinMode(pin, INPUT);
    _pin = pin;
    _res = res;
    _maxAdc = DEFAULT_MAX_ADC_VALUE;
    _refVoltage = DEFAULT_MAX_VOLTAGE_VALUE;
}

void DataCollector_Thermistor::begin(int pin, int res, int maxAdc, int voltage)
{
    pinMode(pin, INPUT);
    _pin = pin;
    _res = res;
    _maxAdc = maxAdc;
    _refVoltage = voltage;
}

void DataCollector_Thermistor::setMaxAdc(int adc)
{
    _maxAdc = adc;
}

void DataCollector_Thermistor::setRefVoltage(int voltage)
{
    _refVoltage = voltage;
}

int DataCollector_Thermistor::readRaw()
{
    return analogRead(_pin);
}

float DataCollector_Thermistor::readTemperature(TemperatureFormat format)
{
    if (_res == 0)
    {
        return -1;
    }
    int raw = readRaw();

    // calculating temperature using res
    double output_voltage, thermistor_resistance, therm_res_ln, temperature;
    output_voltage = ((raw * _refVoltage) / _maxAdc);
    thermistor_resistance = ((5 * (10.0 / output_voltage)) - 10) * 1000; /* Resistance in ohms */
    therm_res_ln = log(thermistor_resistance);
    temperature = (1 / (0.001129148 + (0.000234125 * therm_res_ln) + (0.0000000876741 * therm_res_ln * therm_res_ln * therm_res_ln))); /* Temperature in Kelvin */
    float temp_cel = temperature - 273.15;                                                                                             /* Temperature in degree Celsius */

    if (format == TEMP_C)
    {
        return temp_cel;
    }
    else if (format == TEMP_F)
    {
        return ((temp_cel * 1.8) + 32);
    }
}