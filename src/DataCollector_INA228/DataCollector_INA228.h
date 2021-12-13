#ifndef DataCollector_INA228_h
#define DataCollector_INA228_h

#include "Wire.h"
#include "Arduino.h"
#include "Constants.h"
#include "DataCollector_base.h"

// Addresses for INA288 registers
#define INA228_REGISTER_ADDR_CONFIG 0x00
#define INA228_REGISTER_ADDR_ADC_CONFIG 0x01
#define INA228_REGISTER_ADDR_SHUNT_CAL 0x02
#define INA228_REGISTER_ADDR_SHUNT_TEMPCO 0x03
#define INA228_REGISTER_ADDR_VSHUNT 0x04
#define INA228_REGISTER_ADDR_VBUS 0x05
#define INA228_REGISTER_ADDR_DIETEMP 0x06
#define INA228_REGISTER_ADDR_CURRENT 0x07
#define INA228_REGISTER_ADDR_POWER 0x08
#define INA228_REGISTER_ADDR_ENERGY 0x09
#define INA228_REGISTER_ADDR_CHARGE 0x0A
#define INA228_REGISTER_ADDR_DIAG_ALRT 0x0B
#define INA228_REGISTER_ADDR_SOVL 0x0C
#define INA228_REGISTER_ADDR_SUVL 0x0D
#define INA228_REGISTER_ADDR_BOVL 0x0E
#define INA228_REGISTER_ADDR_BUVL 0x0F
#define INA228_REGISTER_ADDR_TEMP_LIMIT 0x010
#define INA228_REGISTER_ADDR_PWR_LIMIT 0x011
#define INA228_REGISTER_ADDR_MANUFACTURER_ID 0x03E
#define INA228_REGISTER_ADDR_DEVICE_ID 0x03F

// Register Sizes in bits
#define INA228_REGISTER_BITS_CONFIG 16
#define INA228_REGISTER_BITS_ADC_CONFIG 16
#define INA228_REGISTER_BITS_SHUNT_CAL 16
#define INA228_REGISTER_BITS_SHUNT_TEMPCO 16
#define INA228_REGISTER_BITS_VSHUNT 24
#define INA228_REGISTER_BITS_VBUS 24
#define INA228_REGISTER_BITS_DIETEMP 16
#define INA228_REGISTER_BITS_CURRENT 24
#define INA228_REGISTER_BITS_POWER 24
#define INA228_REGISTER_BITS_ENERGY 40
#define INA228_REGISTER_BITS_CHARGE 40
#define INA228_REGISTER_BITS_DIAG_ALRT 16
#define INA228_REGISTER_BITS_SOVL 16
#define INA228_REGISTER_BITS_SUVL 16
#define INA228_REGISTER_BITS_BOVL 16
#define INA228_REGISTER_BITS_BUVL 16
#define INA228_REGISTER_BITS_TEMP_LIMIT 16
#define INA228_REGISTER_BITS_PWR_LIMIT 16
#define INA228_REGISTER_BITS_MANUFACTURER_ID 16
#define INA228_REGISTER_BITS_DEVICE_ID 16

#define INA228_BYTES 8

// Macros for INA value calculations
#define getDieTempfromRaw(val) ((val) * 7.8125 / 1000)
#define getVoltagefromRaw(val) ((val >> 4) * 192.3125 / 1000000)
#define getCurrentfromRaw(val) ((val >> 4))
#define getPowerfromRaw(val) (val * 3.2)
#define getEnergyfromRaw(val) (val * 3.2 * 16)

class DataCollector_INA228 : public DataCollector_base
{
    public:
        int begin(uint8_t address = DEFAULT_INA228_ADDR, int unit_multiplier = DEFAULT_MULTIPLIER);
        int setShuntCal(int val);
        int getShuntCal();
        double getDieTemp(TemperatureFormat format = TEMP_C);
        double getVoltage();
        double getCurrent();
        double getPower();
        double getEnergy();
        double getCharge();
        void setMultiplier(int unit_multiplier);
        int getMultiplier();
        int setShuntOvervoltageLimit(int val);
        int setShuntUndervoltageLimit(int val);
        int setBusOvervoltageLimit(int val);
        int setBusUndervoltageLimit(int val);
        int setTempOverLimit(int val);
        int setPowerOverLimit(int val);
        int getDiagnostics();
        float publish();
        String prettyPublish();

    private:
        int _multiplier;
        uint8_t _ina_addr;
        int _shunt_cal = DEFAULT_SHUNT_CALIBRATION_VALUE;
        double _currentLSB;
        int _readRegister(int reg, int bits, int &_value);
        int _writeRegister(int reg, int bits, int _value);
};

#endif