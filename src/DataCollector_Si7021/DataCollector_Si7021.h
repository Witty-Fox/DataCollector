#ifndef DataCollector_Si7021_h
#define DataCollector_Si7021_h

#include "Constants.h"
#include "Arduino.h"
#include "Adafruit_Si7021.h"
#include "TypeDefines.h"
#include "DataCollector_base.h"

class DataCollector_Si7021 : public DataCollector_base
{
public:
    int begin();
    float readTemperature();
    float readHumidity();
    int enableHeater(bool state);
    void setTemperatureFormat(TemperatureFormat format);
    void setPublishMode(Si7021PublishMode publishMode);
    float publish();
    String prettyPublish();

private:
    Adafruit_Si7021 _sensor = Adafruit_Si7021();
    TemperatureFormat _temperatureFormat = TEMP_C;
    Si7021PublishMode _publishMode = TEMPERATURE;
};

#endif