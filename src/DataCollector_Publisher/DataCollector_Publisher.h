#ifndef DataCollector_Publisher_h
#define DataCollector_Publisher_h

#include "Arduino.h"
#include "Constants.h"
#include "DataCollector_base.h"

class DataCollector_Publisher
{
public:
    void begin(long baud = DEFAULT_PUBLISH_BAUD_RATE, int frequency = DEFAULT_PUBLISH_FREQ);
    void setFrequency(int frequency);
    void publish();
    bool addSensor(DataCollector_base *sensor);
    void prettyPublish();

private:
    int _numSensors = 0;
    DataCollector_base *publishSensors[MAX_SENSORS];
    int _publishRate;
    double _interval_ms;
    double _last_interval_ms;
};

#endif
