#include "DataCollector_OLED.h"

void DataCollector_OLED::begin(uint8_t address, uint16_t color, int size, int cursor_x, int cursor_y)
{  
    _display.begin(address);
    _display.clearDisplay();
    _display.display();
    _display.setTextColor(color);
    _display.setTextSize(size);
    _display.setCursor(cursor_x, cursor_y);
}

void DataCollector_OLED::clear()
{
    _display.clearDisplay();
}

void DataCollector_OLED::display()
{
    _display.display();
}

void DataCollector_OLED::textSize(int size)
{
    _display.setTextSize(size);
}

void DataCollector_OLED::setCursor(int cursor_x, int cursor_y)
{
    _display.setCursor(cursor_x, cursor_y);
}

void DataCollector_OLED::displayText(String text)
{
    _display.println(text);
}