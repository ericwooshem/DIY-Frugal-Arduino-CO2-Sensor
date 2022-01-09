// RTC Time Set Code, CC By-NC 2022 Eric Woo-Shem
/*
Info:
RTC = Real Time Clock

Time given will be in military time (24 hour clock)

Resources Used:
https://learn.adafruit.com/adafruit-scd30
https://www.circuitbasics.com/writing-data-to-files-on-an-sd-card-on-arduino/
https://arduinogetstarted.com/tutorials/arduino-rtc
https://github.com/adafruit/RTClib/tree/master/examples
*/

#include "RTClib.h"
RTC_DS1307 rtc;
void setup() {
  rtc.begin();
  rtc.adjust(DateTime(2021, 10, 14, 18, 02, 00)); // Sets date to 10/13/2021, Time: 18:17:00 in 24 hour time
  /*
   * To set Date/Time, change the numbers in the parenthesis to be current (Year, month, day, hour(24 hr time), minute, second)
   */
}
void loop() {}
