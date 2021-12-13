#include<DataCollector.h>            // Importing DataCollector library

DataCollector_OLED oled;             // Creating OLED object

void setup() 
{
  oled.begin();                      // Initializing OLED object with i2c address
}

void loop() 
{
  oled.clear();                      // Clearing the screen
  oled.textSize(1);                  // changes text size for displaying new text
  oled.setCursor(0, 0);              // changes cursor position for the text to be printed
  oled.displayText("DataCollector"); // Sending text to be displayed on the OLED
  oled.display();                    // Asking OLED to display the text
  delay(2000);                       // Adding a delay for 2 sec
  oled.clear();                      // clear's the display
  oled.setCursor(0, 15);             // changes cursor position for the text to be printed
  oled.textSize(2);                  // changes text size for displaying new text
  oled.displayText("WittyFox");      // Sending text to be displayed on the OLED
  oled.display();                    // Asking OLED to display the text
  delay(2000);                       // Adding a delay for 2 sec
}
