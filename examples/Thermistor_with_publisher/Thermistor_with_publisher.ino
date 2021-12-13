#include <DataCollector.h>                      // Importing the DataCollector library

DataCollector_Thermistor Thermistor;            // Creating Thermistor object
DataCollector_Publisher publisher;              // Creating Publisher object

void setup()                            
{
    Thermistor.begin(14);                       // Initializing Thermistor object
    Thermistor.setTemperatureFormat(TEMP_RAW);  // Initializing mode of temperature for publishing
    publisher.begin();                          // Initializing publisher object, default baud rate is 115200 and freqency is set to 50 Hz
    publisher.addSensor(&Thermistor);           // Adding sensor to publisher
}

void loop() 
{
    publisher.publish();                        // running publish function
    // publisher.prettyPublish();               // running publish function with messages
}
