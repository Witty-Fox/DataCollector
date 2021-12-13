#include <DataCollector.h>                     // Importing the DataCollector library

DataCollector_INA228 ina228;                   // Creating INA228 object

void setup() 
{
    Serial.begin(115200);
    int err = ina228.begin();                  // Initializing the INA228, by default address = 0x45 and units in SI
    if (err != 0)
    {
        Serial.println("Error initializing INA228");
        return;
    } else {
        Serial.println("INA228 initialized");
    }
}

void loop()
{
    Serial.print("Die Temperature (C): ");
    Serial.println(ina228.getDieTemp());       // Printing the temperature in Celsius

    Serial.print("Bus Voltage (V): ");
    Serial.println(ina228.getVoltage());       // Printing the die temperature in Volts

    Serial.print("Current (A): ");
    Serial.println(ina228.getCurrent());       // Printing the current in Amps

    Serial.print("Power (W): ");
    Serial.println(ina228.getPower());         // Printing the temperature in Watts

    Serial.print("Energy (J): ");
    Serial.println(ina228.getEnergy());        // Printing the temperature in Joules

    Serial.print("Charge (C): ");
    Serial.println(ina228.getCharge());        // Printing the temperature in Coulombs

    Serial.println();
    delay(2000);
}