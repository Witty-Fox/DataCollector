#include <DataCollector.h>                             // Importing the DataCollector library

#define address 0x44                                   // Defining the i2c address of the sensor

DataCollector_OPT3001 opt3001;                         // Creating OPT3001 object

void setup() 
{
  Serial.begin(115200);                               // Initializing Serial port
  int err = opt3001.begin(address);                    // Initializing OPT3001 object
  if (err != 0)
    {
        Serial.println("Error initializing OPT3001");
        return;
    } else {
        Serial.println("OPT3001 initialized");
    }
}

void loop() 
{
  float Lux = opt3001.readLux();                       // Reading the lux value from the OPT sensor
  Serial.print("Ambient light in Lux: ");
  Serial.print(Lux);                                   // Printing the lux value
  Serial.println(" Lux\n");
  delay(1000);                                         // Adding a delay of 1sec before each reading
}
