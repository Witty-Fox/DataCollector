#include "ClosedCube_OPT3001.h"
#include "Arduino.h"
#include "Constants.h"

class DataCollector_OPT3001
{
public:
    int begin(uint8_t address = DEFAULT_OPT_ADDR);
    float readLux();

private:
    uint8_t address;
    ClosedCube_OPT3001 _sensor;
};