// Co2 Sensor code, CC By-NC 2022 Eric Woo-Shem
/*
Info:
RTC = Real Time Clock
LCD = Liquid Crystal Display (Screen)

Time given will be in military time (24 hour clock)

Resources Used:
https://learn.adafruit.com/adafruit-scd30
https://www.circuitbasics.com/writing-data-to-files-on-an-sd-card-on-arduino/
https://arduinogetstarted.com/tutorials/arduino-rtc
https://github.com/adafruit/RTClib/tree/master/examples
*/
#include <Adafruit_SCD30.h> 
#include <SD.h>
#include "RTClib.h"
#include <LiquidCrystal.h>
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~// ^Import Packages^
LiquidCrystal lcd(9, 8, 5, 4, 3, 2); // Set LCD Screen pins
Adafruit_SCD30  scd30; // Define Sensor
RTC_DS1307 rtc; // Define RTC (Real Time Clock)
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
File myFile; // Define file "myFile"
String fileName = "CO2_Data.txt"; // Set variable holding filename (You can change the filename)
int debug=1; // Set to 1 for console debugging
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void setup() { // Start setup
  Serial.begin(115200); // Begin Serial (On computer)
  while (!Serial); // Wait until Serial is started

  lcd.begin(16, 2); // Set size of LCD screen
  pinMode(6, OUTPUT); // Set what pin 6 does (output)
  pinMode(7, OUTPUT); // Set what pin 7 does (output)
  if (! rtc.begin()) { // If fail to begin the RTC (Real Time Clock)
    Serial.println("Couldn't find RTC"); // Print through serial
    abort(); // Stop program
  }
  scd30.begin(); // Start CO2 Sensor
  SD.begin(10); // Start SD card reader/writer
  myFile = SD.open(fileName, FILE_WRITE); // Create or open a the file with name specified above as filename
  DateTime time = rtc.now(); // Get current time
  Serial.println(time.timestamp(DateTime::TIMESTAMP_DATE)); // Print time
  Serial.println(time.timestamp(DateTime::TIMESTAMP_TIME)); // Print date
  myFile.println(time.timestamp(DateTime::TIMESTAMP_DATE)); // Write date to SD card file
  myFile.close(); // Close file to save
  digitalWrite(7, HIGH); // Set LCD brightness, you can change it if you want to
  analogWrite(6, 120); // Setting LCD contrast, you can change it if you want to
} // End setup
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void loop() { // Start loop (forever)
  if (scd30.dataReady()){ // If CO2 data
    if (!scd30.read()) //If probelm reading data
      {
        Serial.println("Sensor Error"); // Print to serial
        return; // Don't do the the following ↓↓↓
       }
    if (debug==1) // If in debug mode
    {
      Serial.println("Temperature (C): "+String(scd30.temperature)); // Print temperature in celsius
      Serial.println("Relative Humidity: "+String(scd30.relative_humidity)+"%"); // Print humidity %
      Serial.println("CO2: "+String(scd30.CO2)+" ppm"); // Print CO2 ppm (Parts Per Million)
      Serial.println();
    }
    myFile = SD.open(fileName, FILE_WRITE); // Open file
    DateTime time = rtc.now(); // Get current time
    myFile.println(time.timestamp(DateTime::TIMESTAMP_TIME)+"; "+(scd30.CO2)); // Write the time, followed by the CO2 level, separated by a semi-colon (;)
    myFile.close(); // Close file (Save file)
    lcd.setCursor(0,0); // Set LCD Screen cursor position
    lcd.print(time.timestamp(DateTime::TIMESTAMP_TIME)); // Write the time to LCD Screen 
    lcd.setCursor(0,1); // Set LCD Screen cursor position
    lcd.print("Co2: "+String(scd30.CO2)); // Write the CO2 level to the LCD Screen
  } // End "If CO2 data"
} // End loop
