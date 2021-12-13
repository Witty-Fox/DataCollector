#include <DataCollector.h>              // Importing the DataCollector library

#define address 0x44                    // Initializing I2C address of OPT3001

DataCollector_OPT3001 opt3001;          // Creating OPT3001 object
DataCollector_Publisher publisher;      // Creating publisher object

void setup() 
{
  int err = opt3001.begin(address);     // Initializing OPT3001 object with the I2C address 0x44
  if (err != 0)
  {
    Serial.println("Error initializing OPT3001");
    return;
  }
  else
  {
    Serial.println("OPT3001 initialized");
  }
  publisher.begin();                    // Initializing publisher object, default baud rate is 115200 and freqency is set to 50 Hz
  publisher.addSensor(&opt3001);        // Adding sensor to publisher
  

}

void loop() 
{
  publisher.publish();                  // running publish function
 // publisher.prettyPublish();          // running publish function with messages

}
