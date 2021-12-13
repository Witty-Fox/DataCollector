#include "DataCollector_Publisher.h"

void DataCollector_Publisher::begin(long baud, int frequency)
{
    setFrequency(frequency);
    Serial.begin(baud);
}

void DataCollector_Publisher::setFrequency(int frequency) 
{ 
    _publishRate = frequency;
    _interval_ms = 1000.0 / (_publishRate + 1);
}

bool DataCollector_Publisher::addSensor(DataCollector_base *sensor)
{
    if (_numSensors < MAX_SENSORS)
    {
        publishSensors[_numSensors++] = sensor;
        return true;
    }
    return false;
}

void DataCollector_Publisher::publish() {

    if (millis() > _last_interval_ms + _interval_ms) {

        _last_interval_ms = millis();
        String value = String(publishSensors[0]->publish());
        for (int i = 1; i < _numSensors; i++)
        {
            value += "," + String(publishSensors[i]->publish());
        }
        Serial.println(value);
    }
}

void DataCollector_Publisher::prettyPublish()
{
    if (millis() > _last_interval_ms + _interval_ms)
    {
        _last_interval_ms = millis();
        String value = String(publishSensors[0]->prettyPublish());
        for (int i = 1; i < _numSensors; i++)
        {
            value += " | " + String(publishSensors[i]->prettyPublish());
        }
        Serial.println(value);
    }
}