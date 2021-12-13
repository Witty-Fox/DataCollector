#include <DataCollector.h>              // Importing the DataCollector library

DataCollector_LDR ldr;                  // Creating LDR object

void setup() 
{
  ldr.begin(13);                        // Initializing LDR object
  Serial.begin(115200);                 // Initializing serial port
}

void loop() 
{
  int LDR_reading = ldr.readRaw();      // Reading raw value from LDR
  int LDR_reading_lux = ldr.readLux();  // Reading calculated lux value from LDR
  Serial.print("Raw value: ");
  Serial.print(LDR_reading);            // Printing raw value
  Serial.print("\t\tLux value: ");
  Serial.println(LDR_reading_lux);      // Printing calculated lux value
  Serial.println();                     // Printing an empty line
  delay(100);                           // adding delay of 100 ms between each loop

}
