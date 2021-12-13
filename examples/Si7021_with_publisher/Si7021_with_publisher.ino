#include <DataCollector.h>               // Importing the DataCollector library

DataCollector_Si7021 Si7021;             // Creating Si7021 object
DataCollector_Publisher publisher;       // Creating publisher object

void setup() 
{
    Si7021.begin();                      // Initializing Si7021 object with the default I2C address as 0x40
    // Si7021.setPublishMode(HUMIDITY);  // By default, the library publishes the temperature. Uncomment this line to publish humidity instead.
    Si7021.setTemperatureFormat(TEMP_C); // Initializing unit of temperature
    publisher.begin();                   // Initializing publisher object, default baud rate is 115200 and freqency is set to 50 Hz
    publisher.addSensor(&Si7021);        // Adding sensor to publisher
}

void loop() 
{
    publisher.publish();                 // running publish function
    // publisher.prettyPublish();        // running publish function with messages
}
