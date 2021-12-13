#ifndef DataCollector_OLED_h
#define DataCollector_OLED_h

#include "Adafruit_GFX.h"
#include "Adafruit_SH1106.h"
#include "Arduino.h"
#include "Constants.h"

class DataCollector_OLED 
{
public:
    void begin(uint8_t address = DEFAULT_OLED_ADDR, uint16_t color = WHITE, int size = DEFAULT_SIZE, int cursor_x = DEFAULT_CURSOR_X, int cursor_y = DEFAULT_CURSOR_Y);
    void clear();
    void display();
    void setCursor(int cursor_x, int cursor_y);
    void textSize(int size);
    void displayText(String text);

private:
    uint8_t address;
    int cursor_1;
    int cursor_2;
    int size;
    uint16_t color;
    String text;
    Adafruit_SH1106 _display;
};

#endif