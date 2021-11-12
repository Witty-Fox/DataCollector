#include <DataCollector.h>                                     // Importing the DataCollector library

DataCollector_Thermistor thermistor;                           // Creating LDR object

void setup() 
{
  thermistor.begin(33);                                        // Initializing Thermistor object
  Serial.begin(115200);                                        // Initializing Serial port
}

void loop() 
{
  int thermistor_reading = thermistor.readRaw();               // Reading raw values from thermistor
  int thermistor_readingC = thermistor.readTemp();             // Calculating temperature values from thermistor in Celsius
  int thermistor_readingF = thermistor.readTemp(TEMP_F);       // Calculating temperature values from thermistor in Fahrenheit
  Serial.println(thermistor_reading);                          // Printing raw values from thermistor
  Serial.println(thermistor_readingC);                         // Printing temperature values from thermistor in Celsius
  Serial.println(thermistor_readingF);                         // Printing temperature values from thermistor in Fahrenheit
  delay(100);                                                  // adding delay of 100 ms between each loop
}
