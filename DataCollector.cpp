/*
  DataCollector.h - Library for reading various sensors.
*/

#include "DataCollector.h"

void DataCollector_LDR::begin(int pin, int res)
{
    pinMode(pin, INPUT);
    _pin = pin;
    _res = res;
}

int DataCollector_LDR::readRaw()
{
    return analogRead(_pin);
}

float DataCollector_LDR::readLux()
{
    if (_res == 0)
    {
        return -1;
    }
    int raw = readRaw();
    
    // calculate lux using res
    // float lux = (1.25 * pow(10, 7)) * pow(_res, -1.4059); // not sure if this is right

    // calculate lux using res
    double resistorVoltage, ldrVoltage, ldrResistance, ldrLux;
    float MAX_ADC_READING = 4096; /* Maximum reading */
    float ADC_REF_VOLTAGE = 3.3;
    float LUX_CALC_SCALAR = 12518931;
    float LUX_CALC_EXPONENT = -1.405;
    resistorVoltage = (float)raw / MAX_ADC_READING * ADC_REF_VOLTAGE;
    ldrVoltage = ADC_REF_VOLTAGE - resistorVoltage;
    ldrResistance = ldrVoltage / resistorVoltage * _res;
    ldrLux = LUX_CALC_SCALAR * pow(ldrResistance, LUX_CALC_EXPONENT);
    return ldrLux;
}


void DataCollector_Thermistor::begin(int pin, int res)
{
    pinMode(pin, INPUT);
    _pin = pin;
    _res = res;
}

int DataCollector_Thermistor::readRaw()
{
    return analogRead(_pin);
}

float DataCollector_Thermistor::readTemp(TemperatureFormat format)
{
    if (_res == 0)
    {
        return -1;
    }
    int raw = readRaw();

    // calculating temperature using res
    double output_voltage, thermistor_resistance, therm_res_ln, temperature;
    output_voltage = ((raw * 5.0) / 1023.0);
    thermistor_resistance = ((5 * (10.0 / output_voltage)) - 10); /* Resistance in kilo ohms */
    thermistor_resistance = thermistor_resistance * 1000;         /* Resistance in ohms   */
    therm_res_ln = log(thermistor_resistance);
    temperature = (1 / (0.001129148 + (0.000234125 * therm_res_ln) + (0.0000000876741 * therm_res_ln * therm_res_ln * therm_res_ln))); /* Temperature in Kelvin */
    float temp_cel = temperature - 273.15;  /* Temperature in degree Celsius */                                                                                            /* Temperature in degree farhrentine */
    
    if (format == TEMP_C)
    {
        return temp_cel;
    }
    else if (format == TEMP_F)
    {
        float temp_fahn = ((temp_cel * 1.8) + 32);
        return temp_fahn;
    }
}

int DataCollector_Si7021::begin()
{
    if (!_sensor.begin()) {
        return -1; // error codes needs to be properly decided
    }
    else {
        return 0;
    }
}

float DataCollector_Si7021::readTemp(TemperatureFormat format)
{
    if (format == TEMP_C)
    {
        return (_sensor.readTemperature());
    }
    else if (format == TEMP_F)
    {
        float temp_fahn = ((_sensor.readTemperature() * 1.8) + 32);
        return (temp_fahn);
    }
}

float DataCollector_Si7021::readHum()
{
    return (_sensor.readHumidity());
}

// int DataCollector_Si7021::enableHeater(bool state)
// {
//     _sensor.heater(state);
//     if (_sensor.isHeaterEnabled()) {
//         return 1;
//     }
//     else {
//         return 0;
//     }
// }