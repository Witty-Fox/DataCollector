#include "DataCollector_INA228.h"

int DataCollector_INA228::begin(uint8_t address, int unit_multiplier)
{
    Wire.begin();
    _ina_addr = address;
    _multiplier = unit_multiplier;
    _currentLSB = 0.0000062942505;
    int err = setShuntCal(_shunt_cal);
    return err;
}

void DataCollector_INA228::setMultiplier(int unit_multiplier)
{
    _multiplier = unit_multiplier;
}

int DataCollector_INA228::getMultiplier()
{
    return _multiplier;
}

int DataCollector_INA228::setShuntCal(int val)
{
    int err = _writeRegister(INA228_REGISTER_ADDR_SHUNT_CAL, INA228_REGISTER_BITS_SHUNT_CAL, val);
    return err;
}

int DataCollector_INA228::getShuntCal()
{
    int val = 0;
    _readRegister(INA228_REGISTER_ADDR_SHUNT_CAL, INA228_REGISTER_BITS_SHUNT_CAL, val);
    return val;
}

double DataCollector_INA228::getDieTemp(TemperatureFormat format)
{
    int val = 0;
    _readRegister(INA228_REGISTER_ADDR_DIETEMP, INA228_REGISTER_BITS_DIETEMP, val);
    double temp = getDieTempfromRaw(val);
    return (format == TEMP_C ? temp : cToF(temp));
}

double DataCollector_INA228::getVoltage()
{
    int val = 0;
    _readRegister(INA228_REGISTER_ADDR_VBUS, INA228_REGISTER_BITS_VBUS, val);
    double vbus = getVoltagefromRaw(val) * _multiplier;
    return vbus;
}

double DataCollector_INA228::getCurrent()
{
    int val = 0;
    _readRegister(INA228_REGISTER_ADDR_CURRENT, INA228_REGISTER_BITS_CURRENT, val);
    double current = getCurrentfromRaw(val) * _currentLSB *_multiplier;
    return current;
}

double DataCollector_INA228::getPower()
{
    int val = 0;
    _readRegister(INA228_REGISTER_ADDR_POWER, INA228_REGISTER_BITS_POWER, val);
    double power = getPowerfromRaw(val) * _currentLSB * _multiplier;
    return power;
}

double DataCollector_INA228::getEnergy()
{
    int val = 0;
    _readRegister(INA228_REGISTER_ADDR_ENERGY, INA228_REGISTER_BITS_ENERGY, val);
    double energy = getEnergyfromRaw(val) * _currentLSB * _multiplier;
    return energy;
}

double DataCollector_INA228::getCharge()
{
    int val = 0;
    _readRegister(INA228_REGISTER_ADDR_CHARGE, INA228_REGISTER_BITS_CHARGE, val);
    double charge = val * _currentLSB * _multiplier;
    return charge;
}

int DataCollector_INA228::_writeRegister(int reg, int bits, int _value)
{
    int bytes = bits / INA228_BYTES;
    Wire.beginTransmission(_ina_addr);
    Wire.write(reg);
    for (int i = 0; i < bytes; i++)
    {
        int val = (_value >> (8 * (bytes - i - 1))) & 0xFF;
        Wire.write(val);
    }
    int err = Wire.endTransmission();
    return err;
}

int DataCollector_INA228::_readRegister(int reg, int bits, int &_value)
{
    int bytes = bits / INA228_BYTES;
    Wire.beginTransmission(_ina_addr);
    Wire.write(reg);
    int error = Wire.endTransmission(false);
    if (error != 0)
        return error;
    int n = Wire.requestFrom(_ina_addr, byte(bytes));
    if (n != bytes)
    {
        return -1;
    }
    else
    {
        int val = 0;
        for (int i = 0; i < bytes; i++)
        {
            int raw = Wire.read();
            val += raw << (8 * (bytes - i - 1));
        }
        _value = val;
        return 0;
    }
}

int DataCollector_INA228::setShuntOvervoltageLimit(int val)
{
    int err = _writeRegister(INA228_REGISTER_ADDR_SOVL, INA228_REGISTER_BITS_SOVL, val);
    return err;
}

int DataCollector_INA228::setShuntUndervoltageLimit(int val)
{
    int err = _writeRegister(INA228_REGISTER_ADDR_SUVL, INA228_REGISTER_BITS_SUVL, val);
    return err;
}

int DataCollector_INA228::setBusOvervoltageLimit(int val)
{
    int err = _writeRegister(INA228_REGISTER_ADDR_BOVL, INA228_REGISTER_BITS_BOVL, val);
    return err;
}

int DataCollector_INA228::setBusUndervoltageLimit(int val)
{
    int err = _writeRegister(INA228_REGISTER_ADDR_BUVL, INA228_REGISTER_BITS_BUVL, val);
    return err;
}

int DataCollector_INA228::setTempOverLimit(int val)
{
    int err = _writeRegister(INA228_REGISTER_ADDR_TEMP_LIMIT, INA228_REGISTER_BITS_TEMP_LIMIT, val);
    return err;
}

int DataCollector_INA228::setPowerOverLimit(int val)
{
    int err = _writeRegister(INA228_REGISTER_ADDR_PWR_LIMIT, INA228_REGISTER_BITS_PWR_LIMIT, val);
    return err;
}

int DataCollector_INA228::getDiagnostics()
{
    // Please refer Table 7-16 of the INA228 Datasheet to interpret the return value
    // https://www.ti.com/lit/ds/symlink/ina228.pdf
    int val = 0;
    _readRegister(INA228_REGISTER_ADDR_DIAG_ALRT, INA228_REGISTER_BITS_DIAG_ALRT, val);
    return val;
}

float DataCollector_INA228::publish()
{
    return 0; // Not implemented yet
}

String DataCollector_INA228::prettyPublish()
{
    return ""; // Not implemented yet
}