#include <DataCollector.h>                             // Importing the DataCollector library

DataCollector_Si7021 si7021;                           // Creating Si7021 object

void setup() 
{
    si7021.begin();                                      // Initializing Si7021 object
    Serial.begin(115200);                                // Initializing Serial port
}

void loop() 
{
    si7021.setTemperatureFormat(TEMP_C);                 // Setting temperature format to Celsius
    float si7021_cel = si7021.readTemperature();         // Reading temperature in Celsius
    si7021.setTemperatureFormat(TEMP_F);                 // Setting temperature format to Fahrenheit
    float si7021_fah = si7021.readTemperature();         // Reading temperature in Fahrenheit
    float si7021_hum = si7021.readHumidity();            // Reading humidity in percentage

    Serial.print("Temperature in Celsius: ");
    Serial.print(si7021_cel);                            // Printing temperature in Celsius
    Serial.print(" C");
    Serial.print("\t\tTemperature in Fahrenheit: ");
    Serial.print(si7021_fah);                            // Printing temperature in Fahrenheit
    Serial.println(" F");
    Serial.print("Humidity: ");
    Serial.print(si7021_hum);                            // Printing humidity in percentage
    Serial.println(" %\n");
    delay(1000);                                         // Adding a delay of 1sec before each reading
}
