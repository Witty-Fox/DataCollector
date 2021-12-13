#include "DataCollector_OPT3001.h"

int DataCollector_OPT3001::begin(uint8_t address)
{
    _sensor.begin(address);
    OPT3001_Config newConfig;
    newConfig.RangeNumber = B1100;	
    newConfig.ConvertionTime = B0;
    newConfig.Latch = B1;
    newConfig.ModeOfConversionOperation = B11;
    OPT3001_ErrorCode errorConfig = _sensor.writeConfig(newConfig);
    if (errorConfig == NO_ERROR)
		return 0;
	else
        return -1;
}

float DataCollector_OPT3001::readLux()
{
    return (_sensor.readResult().lux);
}

float DataCollector_OPT3001::publish()
{
    return readLux();
}

String DataCollector_OPT3001::prettyPublish()
{
    return "OPT3001 (lux): " + String(readLux());
}