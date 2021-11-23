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
  int thermistor_readingC = thermistor.readTemperature();      // Calculating temperature values from thermistor in Celsius
  int thermistor_readingF = thermistor.readTemperature(TEMP_F);// Calculating temperature values from thermistor in Fahrenheit
  Serial.print("Raw Value: ");
  Serial.println(thermistor_reading);                          // Printing raw values from thermistor
  Serial.print("Temperature in Celsius: ");
  Serial.print(thermistor_readingC);                           // Printing temperature values from thermistor in Celsius
  Serial.print("\t\tTemperature in Fahrenheit: ");
  Serial.println(thermistor_readingF);                         // Printing temperature values from thermistor in Fahrenheit
  Serial.println();                                            // Printing an empty line
  delay(100);                                                  // adding delay of 100 ms between each loop
}
