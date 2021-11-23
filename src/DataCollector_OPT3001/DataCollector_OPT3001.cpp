#include "DataCollector_OPT3001.h"

int DataCollector_OPT3001::begin(uint8_t address)
{
    return (_sensor.begin(address));
}

float DataCollector_OPT3001::readLux()
{
    return (_sensor.readResult().lux);
}