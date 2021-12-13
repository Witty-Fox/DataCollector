#ifndef DataCollector_OPT3001_h
#define DataCollector_OPT3001_h

#include "ClosedCube_OPT3001.h"
#include "Arduino.h"
#include "Constants.h"
#include "DataCollector_base.h"

class DataCollector_OPT3001 : public DataCollector_base
{
public:
    int begin(uint8_t address = DEFAULT_OPT_ADDR); 
    float readLux();
    float publish();
    String prettyPublish();

private:
    uint8_t address;
    ClosedCube_OPT3001 _sensor;
    OPT3001_ErrorCode Data_ErrorCode;
    LightFormat _publishFormat;
};

#endif