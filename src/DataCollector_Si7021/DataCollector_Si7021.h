#include "Constants.h"
#include "Arduino.h"
#include "Adafruit_Si7021.h"
#include "TypesDefines.h"

class DataCollector_Si7021
{
public:
    int begin();
    float readTemperature(TemperatureFormat format = TEMP_C);
    float readHumidity();
    int enableHeater(bool state);

private:
    Adafruit_Si7021 _sensor = Adafruit_Si7021();
};