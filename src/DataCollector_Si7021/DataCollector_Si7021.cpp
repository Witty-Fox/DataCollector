#include "DataCollector_Si7021.h"

int DataCollector_Si7021::begin()
{
    if (!_sensor.begin())
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

float DataCollector_Si7021::readTemperature(TemperatureFormat format)
{
    float temp = _sensor.readTemperature();

    if (format == TEMP_C)
    {
        return (temp);
    }
    else if (format == TEMP_F)
    {
        return ((temp * 1.8) + 32);
    }
}

float DataCollector_Si7021::readHumidity()
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