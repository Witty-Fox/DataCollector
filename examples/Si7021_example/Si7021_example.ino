#include <DataCollector.h>                      // Importing the DataCollector library

DataCollector_Si7021 si7021;                    // Creating Si7021 object

void setup() 
{
  si7021.begin();                               // Initializing Si7021 object
  Serial.begin(9600);                           // Initializing Serial port
}

void loop() 
{
  float si7021_cel = si7021.readTemp(TEMP_C);   // Reading temperature in Celsius
  float si7021_fah = si7021.readTemp(TEMP_F);   // Reading temperature in Fahrenheit
  float si7021_hum = si7021.readHum();          // Reading humidity in percentage
  Serial.print("Temperature in Celsius: ");
  Serial.print(si7021_cel);                     // Printing temperature in Celsius
  Serial.println(" C");
  Serial.print("Temperature in Fahrenheit: ");
  Serial.print(si7021_fah);                     // Printing temperature in Fahrenheit
  Serial.println(" F");
  Serial.print("Humidity: ");
  Serial.print(si7021_hum);                     // Printing humidity in percentage
  Serial.println(" %");

}
