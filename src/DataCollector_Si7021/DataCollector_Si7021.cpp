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

float DataCollector_Si7021::readTemperature()
{
    float temp = _sensor.readTemperature();

    if (_temperatureFormat == TEMP_F)
    {
        return (cToF(temp));
    }
    else
    {
        return (temp);
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

void DataCollector_Si7021::setTemperatureFormat(TemperatureFormat format)
{
    _temperatureFormat = format;
}

void DataCollector_Si7021::setPublishMode(Si7021PublishMode publishMode)
{
    _publishMode = publishMode;
}

float DataCollector_Si7021::publish()
{
    return (_publishMode == TEMPERATURE) ? readTemperature() : readHumidity();
}

String DataCollector_Si7021::prettyPublish()
{
    if (_publishMode == TEMPERATURE)
    {
        return "Si7021 temperature : " + String(readTemperature());
    }
    else
    {
        return "Si7021 humidity : " + String(readHumidity());
    }
}
