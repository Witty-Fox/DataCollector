#include <DataCollector.h>               // Importing the DataCollector library

DataCollector_LDR ldr;                   // Creating LDR object
DataCollector_Publisher publisher;       // Creating Publisher object

void setup()
{
    ldr.begin(13);                       // Initializing LDR object
    ldr.setPublishMode(LIGHT_RAW);       // Setting publish mode to LIGHT_RAW
    publisher.begin();                   // Initializing publisher object, default baud rate is 115200 and freqency is set to 50 Hz
    publisher.addSensor(&ldr);           // Adding sensor to publisher
}

void loop()
{
    publisher.publish();                 // running publish function
// publisher.prettyPublish();            // running publish function with messages
}
