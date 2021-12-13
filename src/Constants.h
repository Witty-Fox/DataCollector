#ifndef Constants_h
#define Constants_h

#include "TypeDefines.h"

// Macros
#define cToF(c) (c * 1.8 + 32.0)

// Universal Constants
#define DEFAULT_MAX_ADC_VALUE 4096
#define DEFAULT_MAX_VOLTAGE_VALUE 3.3

// Publisher Constants
#define MAX_SENSORS 5
#define DEFAULT_PUBLISH_FREQ 50
#define DEFAULT_PUBLISH_BAUD_RATE 115200

// LDR Constants
#define DEFAULT_LDR_RES_VALUE 10000
#define DEFAULT_LUX_SCALE_VALUE 12518931
#define DEFAULT_LUX_EXP_VALUE -1.405
#define DEFAULT_LDR_PUBLISH_FORMAT LIGHT_RAW

// Thermistor Constants
#define DEFAULT_THERM_RES_VALUE 10000

// OPT3001 Constants
#define DEFAULT_OPT_ADDR 0x44

// OLED Constants
#define DEFAULT_OLED_ADDR 0x3C
#define DEFAULT_CURSOR_X 0
#define DEFAULT_CURSOR_Y 0
#define DEFAULT_SIZE 1

// INA228 Constants
#define DEFAULT_INA228_ADDR 0x45
#define DEFAULT_MULTIPLIER 1
#define DEFAULT_SHUNT_CALIBRATION_VALUE 8250

#endif