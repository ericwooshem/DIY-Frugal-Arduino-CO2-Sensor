# DIY Frugal Arduino CO₂ Sensor

CC BY-NC-SA [Eric Woo-Shem](https://github.com/ericwooshem) & [Brian Woo-Shem](www.brianwooshem.com)

![CO2 Sensor Complete Assembly in Cardboard](https://github.com/ericwooshem/DIY-Frugal-Arduino-CO2-Sensor/blob/main/Graphics/CO2_Sensor_Complete.png) ![CO2 Sensor Header Pic](https://github.com/ericwooshem/DIY-Frugal-Arduino-CO2-Sensor/blob/main/Graphics/CO2_SensorOpen_Graph.png)

## Features

- Displays the current CO₂ level so you can quickly check if the current conditions are safe or not. 
- Records CO₂ levels over time. Good for repeated events like school or office when it is impossible to check while there. 
- Accurate within ~60 ppm under typical conditions.
- Costs $60 to $110 - less than half the cost of commercial sensors

## Introduction: Why measure CO₂?

As society reopens amid the ongoing COVID-19 pandemic, preventing the spread of the virus is crucial to keeping doors open. Scientists and engineers studying aerosols at major research institutions have identified that good ventilation plays a major role in reducing contagion in addition to vaccines, regular testing, and masks [1]. Since [COVID-19 spreads primarily through airborne virus particles](https://www.science.org/doi/10.1126/science.abd9149), outdoor and well-ventilated areas are much safer because infectious particles blow away before they can be inhaled by a susceptible person. The challenge is identifying which spaces are poorly ventilated and could contain high concentrations of the virus.

Ideally, we would measure the concentration of COVID-19 virus particles in the air directly, however such a sensor does not exist. Instead, researchers identified [carbon dioxide as a proxy measurement](https://www.washingtonpost.com/health/2021/02/10/carbon-dioxide-device-coronavirus/) to determine if a space is well-ventilated, as doubling the CO₂ concentration doubles the risk of infection [2][3]. Humans exhale carbon dioxide at approximately 100 times the concentration of the ambient air. High CO₂ levels indicate inadequate ventilation so if a contagious person were present, virus particles remain in the air and there is a high risk that others in the space will get sick. 

The typical outdoor air CO₂ levels are between 410-420 ppm in remote locations, and up to 450 ppm in urban environments [4]. We exhale roughly 40000 ppm CO₂ [5]. Aerosol researchers recommend keeping CO₂ below 800 ppm to prevent the spread of COVID-19 [1][2][3][6]. Aside from the pandemic, elevated CO₂ levels make a room feel “stuffy” and can cause a decline in cognitive ability [7].

## Instructions

### Parts

This is a *frugal* CO₂ sensor so most of the parts can be interchanged with similar ones. A detailed Bill of Materials with the exact components used in this version of the sensor is provided as "CO2_Sensor_Bill_of_Materials.xlsx". Different sheets show suggestions for products to purchase for the lowest cost for varying numbers of sensors. The quantities and exact cost will autocompute if you plug in the number of sensors you want to build. 

**Note:** Product suggestions in Bill of Materials are for convenience only. This project does not receive any incentive, financial or otherwise, for suggesting any particular product.

#### Cost

One sensor can be built for roughly $100, and 10 sensors for about $87 each if all parts are purchased new. Reusing components you already have reduces the cost significantly.

#### List of Parts

| Part Description | QTY per Sensor |
|---|---|
| Arduino: Nano (recommended), Uno, Mega, etc. | 1|
|[SCD-30 NDIR CO2 Sensor](http://www.adafruit.com/product/4867)| 1|
|[STEMMA QT Cable Headers for SCD-30](http://www.adafruit.com/product/4209)|1|
|Breadboard: Mini breadboards recommended, but any size can work|1-2|
|Micro SD Card Adapter Module (Or SD Card Adapter Module)|1|
| Micro SD (or SD) Card. Small is fine - 1 GB is overkill|1|
|DS3231 Real Time Clock Module|1|
| CR2032 Battery|1|
|Jumper wires|10-20|
|USB Power Bank Battery 5V: optional; 9V battery adapter or other power supplies work as well|1|
|16x2 LCD Display: Optional; only needed if you want to display the current CO₂ levels|1|
|Small Box: Cardboard, 3D printed, etc. Just large enough to hold everything, and with holes for the CO₂ sensor intake and LCD screen if used|1|

### Assembly

![Connection Diagram](https://github.com/ericwooshem/DIY-Frugal-Arduino-CO2-Sensor/blob/main/Graphics/SCD_30_Logger.png)

Complete connection diagram.

1. Insert the CR2032 battery into the RTC, and your memory card into your card reader.

	![Micro SD](https://github.com/ericwooshem/DIY-Frugal-Arduino-CO2-Sensor/blob/main/Graphics/I1.png) ![RTC](https://github.com/ericwooshem/DIY-Frugal-Arduino-CO2-Sensor/blob/main/Graphics/I2.png)

2. Attach 4 male-to-female wires onto the GND, VCC, SDA, and SCL ports on the RTC. If you have a new set of jumper wires, you may need to break them off of the bundle. Wire colors may vary.

	![RTC-Wires](https://github.com/ericwooshem/DIY-Frugal-Arduino-CO2-Sensor/blob/main/Graphics/I4.png)

3. Attach 6 male-to-female wires for all 6 pins on the card reader.

	![Card Reader Wires](https://github.com/ericwooshem/DIY-Frugal-Arduino-CO2-Sensor/blob/main/Graphics/I3.png)

4a. (For Nano only) Place and push in the Arduino Nano into one of the breadboards, as shown.

	![Arduino Nano Breadboard](https://github.com/ericwooshem/DIY-Frugal-Arduino-CO2-Sensor/blob/main/Graphics/I5.png)

4b. (For Uno or Mega) The connectors are built in, so this step is not necessary. However, you may need to run a wire from a particular pin to a breadboard row if more than one connection is required. 

5. Plug the SCD-30 cable headers into either port of the CO₂ sensor. Both ports are the same, but the plug has a correct orientation.

	![SCD-30 Cable](https://github.com/ericwooshem/DIY-Frugal-Arduino-CO2-Sensor/blob/main/Graphics/I6.png)

6. (If using display) Poke the LCD into a breadboard. Mini-breadboards: use a second breadboard. Connect wires to pins 2-6 and 11-16. Note: you can also use male-to-female wires and connect to the LCD pins directly, but we found this to be more difficult.

	![LCD](https://github.com/ericwooshem/DIY-Frugal-Arduino-CO2-Sensor/blob/main/Graphics/I7.png)

7. Connect the Ground on the Arduino to an unused row on the breadboard. Connect the 5V on the Arduino to a different unused row. Below is an example for mini-breadboards.

	![Arduino-Breadboard](https://github.com/ericwooshem/DIY-Frugal-Arduino-CO2-Sensor/blob/main/Graphics/I8.png)

8. Connect the Real Time Clock module wires:

|Sensor Wire|Breadboard Row|
|---|---|
|VCC | 5V row created in step 7|
|GND | the ground row created in step 7|
|SDA | Arduino pin A4|
|SCL | Arduino pin A5|

	![RTC-Wires](https://github.com/ericwooshem/DIY-Frugal-Arduino-CO2-Sensor/blob/main/Graphics/I9.png)

9. Connect the SD Card Reader wires:

|Sensor Wire|Breadboard Row|
|---|---|
|GND |ground row created in step 7|
|VCC to 5V row created in step 7|
|MISO | Arduino pin D12|
|MOSI | Arduino pin D11|
|SCK | Arduino pin D13|
|CS | Arduino pin D10|

	![SD Wires](https://github.com/ericwooshem/DIY-Frugal-Arduino-CO2-Sensor/blob/main/Graphics/I10.png)

10. Connect the SCD-30 Sensor wires:

|Sensor Wire|Breadboard Row|
|---|---|
|Black| ground row created in step 7|
|Red| 5V row created in step 7|
|Blue| Arduino pin A4|
|Yellow| Arduino pin A5|

	![SCD-30 Wires](https://github.com/ericwooshem/DIY-Frugal-Arduino-CO2-Sensor/blob/main/Graphics/I11.png)

11. Connect the LCD Wires:

|LCD Pin No.|Arduino Pin|
|---|---|
|2|5V|
|3|D6|
|5|Ground|
|6|D8|
|11|D5|
|12|D4|
|13|D3|
|14|D2|
|15|D7|
|16|Ground|

![LCD to Arduino](https://github.com/ericwooshem/DIY-Frugal-Arduino-CO2-Sensor/blob/main/Graphics/I12.png)

12. Connect the Arduino USB cable between the Arduino and your computer.

13. (If not already installed) Download [ArduinoIDE](https://www.arduino.cc/en/software/).

14. Set the time on the RTC: Download the code file *Set_RTC_Time.ino* and open it in ArduinoIDE.

15. Go to Tools>Board and select your Arduino type.

	![Select board](https://github.com/ericwooshem/DIY-Frugal-Arduino-CO2-Sensor/blob/main/Graphics/I15.png)

16. (Arduino Nano only) Go to Tools>Processor and select "ATmega328P (Old Bootloader)".

	![Arduino Nano Processor](https://github.com/ericwooshem/DIY-Frugal-Arduino-CO2-Sensor/blob/main/Graphics/I16.png)

17. Go to Tools>Port, and select the one including “USBx”, where “x” is the port you plugged the Arduino into. If you are unsure which port, start with the first option and click “Get Board Info". If you get an error, it is the wrong one. Try the next port and repeat until one works.

18. Go to Tools>Programmer, and select “AVR ISP”.

	![AVR ISP](https://github.com/ericwooshem/DIY-Frugal-Arduino-CO2-Sensor/blob/main/Graphics/I18.png)

19. In the *RTC_Time_Set.ino* code, go to line 19 with the code `rtc.adjust(DateTime(2021, 10, 13, 18, 17, 00));`. Change the numbers to match the form '(Year, month, day, hour in 24 hour time, minute, second)' for the current date and time. The RTC module will be set to the time specified when you upload the code. Tip: If you want very precise time, set the minutes and seconds for about a minute out, then watch the clock and hit upload about 4-6 seconds before the time you set. However, within ~5 minutes is usually good enough.

20. Upload the program to the Arduino by clicking on the right arrow button next to the check mark button. Warning: Do not touch until it says, "Done uploading."

	![Arduino Upload Code](https://github.com/ericwooshem/DIY-Frugal-Arduino-CO2-Sensor/blob/main/Graphics/I22.png)

21. Upload the CO₂ sensor code: Download *CO2SensorCode.ino* and open it in Arduino IDE. Upload the program to the Arduino by clicking on the arrow button next to the check mark button.

22. Plug the Arduino into a computer, USB Power Bank, or other power supply to turn the sensor on. Whenever it is given power, the sensor system will display the current CO₂ readings on the screen and save them to a file on the SD card.

## Troubleshooting

[Arduino IDE / Code Upload Issues](https://support.arduino.cc/hc/en-us/articles/4403365313810-Errors-when-uploading-a-sketch)
[Arduino Nano Select Processor](https://support.arduino.cc/hc/en-us/articles/4401874304274-Select-the-right-processor-for-Arduino-Nano)
[Wiring Intro for Beginners](https://learn.adafruit.com/breadboards-for-beginners/introduction)   
[SCD-30 Sensor](https://learn.adafruit.com/adafruit-scd30)   
[Alternative Method to Set Date and Time on RTC](https://create.arduino.cc/projecthub/tittiamo68/clock-set-date-time-0d46a4) Note: Use the LCD wiring from this project instead.
[Intro to SD and Micro SD Card Modules with Arduino](https://create.arduino.cc/projecthub/electropeak/sd-card-module-with-arduino-how-to-read-write-data-37f390)

### Arduino to computer connection not working / code won't upload

- Check [Arduino IDE / Code Upload Issues](https://support.arduino.cc/hc/en-us/articles/4403365313810-Errors-when-uploading-a-sketch)
- Try each port option
- Try each processor option
- Swap the USB cable with another - sometimes the cables break
- Try a [Loopback Test](https://support.arduino.cc/hc/en-us/articles/360020366520-How-to-do-a-loopback-test)

### Most components appear to work, but one does not

- Most likely this is a wiring issue. Check that the wires leading to that component are matched to the correct pins and firmly attached.
- Re-upload the sensor code.
- Try a different power supply. If the current one is too weak, some components may work but others will not have enough power to operate.

### Sensor returns ridiculously large or small readings

- Anything between 400 ppm outdoors or in well-ventilated areas to 4000 ppm in stuffy buildings and inside cars is probably valid.
- If the first value is 0, this is a known bug. Simply ignore that value.
- If unusual values persist, check that the cable is firmly plugged into the sensor, and the wires are properly connected to the breadboard and Arduino.
- Try swapping the cable to the other port on the SCD-30 sensor.

## Accessing and Using Collected CO₂ Data

When using the sensor, you can simply read the values from the screen. However, to get a more complete picture of how safe each place you have been is, it is necessary to analyze the data in aggregate. You can upload the data to your computer from the (micro) SD card, put it into a spreadsheet program, and create graphs or analyze it.

1. Remove the (Micro) SD card from the adapter module by pressing firmly and releasing until it springs out, then pulling it out gently. 
2. Connect the (Micro) SD card to your computer, using adapters if necessary.
3. Copy the file on the card “CO2_Data.TXT” and change the file extension to ".csv". 
4. Open it with Microsoft Excel, Libre Office Calc, Google Sheets, or other spreadsheet software. You may need to right click then select "Open with" and choose your spreadsheet software if the computer defaults to another application.
3. If you get a pop-up window asking how to import the data, choose the automatic selection or split by ";".
5. Click "OK."The data should be imported.

![Data import demo](https://github.com/ericwooshem/DIY-Frugal-Arduino-CO2-Sensor/blob/main/Graphics/CO2_Data_Import_Demo.png)

### Data Analysis Tricks

- We suggest that you download the data file and delete it from the SD card after you use the sensor each day so that you can more easily keep track of your data and where you collected the data.
- To convert time in HH:MM:SS to separate columns for hours, minutes, and seconds, open the text file in a text editor and do "Find & Replace." Find ":" and replace with ";" then import to the spreadsheet software with the ";" delimiter. 
- The first data point is recorded as 0 because the Arduino tries to record data before the initial reading is complete. This is incorrect and should be deleted.
- Every time the Arduino is powered off and restarted, it will append the initial set of data but add a new line with the date in the form YYYY-MM-DD. 
	- Sometimes the sensor gets bumped and restarts unexpectedly. Searching for "-" can detect these errors. The date line needs to be removed before graphing.
	- If you use the sensor for several days between downloading the data, look for these date lines to figure out when each chunk of data was collected.
	- If the sensor is left on continuously past midnight, it will not create a new date line but simply jump to 00:00:00.

## Testing & Validation

- Outside away from people and buildings, the sensor should read between 400 and 500 ppm.
- If you breathe directly on the sensor, it should read over 10,000 and up to 40,000.
- The sensor is very sensitive to nearby sources of CO₂. For example, we observed that the sensor reads 500-550 ppm when we walk outside with it in our backpack because our breath is enough to raise the CO₂ levels locally.
- A version of this sensor was used in a college undergraduate lab course. Students were asked to analyze the sensor's accuracy. The sensor typically performed with readings consistently about 50 ppm too high. 
- Calibration is very difficult and not recommended. The sensors come pre-calibrated if ordered from Adafruit.

## Comparison to Aranet Sensor

A company called Aranet produces CO₂ sensors that are ready to use out of the box. Many researchers have recommended them. Here's how our DIY sensor compares.

|  |[Adafruit SCD-30](https://www.adafruit.com/product/4867)|[Aranet4](https://www.co2meter.com/products/aranet4-home-indoor-air-quality-monitor)|
|---|---|---|
|Range:|400-10000ppm|0-9999ppm
|Accuracy:|±30 ppm + 3%|0-2000ppm, ±50ppm ± 3% reading;     2001-9999ppm ±10% of reading |
| | | |
|Accuracy At:  |
|	420ppm (outside)|	±42.6ppm|±62.6ppm|
|	800ppm	|±54 ppm|±74ppm|
|	1000ppm|±60 ppm|±80ppm|
|	2000ppm|±90 ppm|±110ppm|
|	3000ppm|±120 ppm|±300ppm|
| | | |
|Fastest supported measurement interval: 	|2 seconds|1 minute|
|Length of stored measurement data at fastest measurement interval|	>30 days/GB-SD*|3.5 days|
|Accuracy of other measurements:
|Temperature:|±0.3 °C|±0.3 °C
|Rel. Humidity: |± 2 %|± 3 %
| | | |
|Atmospheric Pressure: 
|Range: |Not included|0.3 to 1.1 atm (4.4 to 16.0 psi)|
|Accuracy:|N/A|± 1 hPa|
| | | |
|Battery Type:|Rechargeable USB|2 x AA|
|Battery Life:|~3 days|Up to 2 years|
|Cost:|est $60-110|$249|

\* Multiply by the size in GB of micro SD card

## Contributors
[Eric Woo-Shem](https://github.com/ericwooshem): Sensor design, electrical connections & diagrams, RTC and sensor data code, part selection.

[Brian Woo-Shem](www.brianwooshem.com): Engineering guidance, research, documentation, sensor testing and validation.

## License

All text, graphics, and non-code content is licensed [CC BY-NC-SA](https://creativecommons.org/licenses/by-nc-sa/4.0/)    
All code is licensed under the [GNU General Public License v3](https://www.gnu.org/licenses/gpl-3.0.en.html)

RTClib and Adafruit_SCD30 are Copyright (c) Adafruit Industries and used under the open source MIT license.   
Arduino IDE and related components are open source and licensed under the GNU GPL v2 and/or CC BY-SA Arduino.

## References

[1] Wang et al., Science Vol 373, Issue 981 (2021). https://www.science.org/doi/10.1126/science.abd9149   
[2] Z. Peng and J. Jimenez, “Exhaled CO₂ as a COVID-19 Infection Risk Proxy for Different Indoor Environments and Activities, ACS, 2021. https://pubs.acs.org/doi/10.1021/acs.estlett.1c00183   
[3] C. Mooney, “The Coronavirus is Airborne. Here’s How to Know if You’re Breathing Other People’s Breath,” The Washington Post, 2021. https://www.washingtonpost.com/health/2021/02/10/carbon-dioxide-device-coronavirus/   
[4] NOAA Global Monitoring Laboratory, “Trends in Atmospheric Carbon Dioxide.” https://gml.noaa.gov/ccgg/trends/   
[5] K. Alhambra and D. Czernia, CO₂ Breathing Emission Calculator. https://www.omnicalculator.com/ecology/co2-breathing-emission   
[6] UK Health and Safety Executive, Ventilation and Air Conditioning During the Coronavirus Pandemic.
 https://www.hse.gov.uk/coronavirus/equipment-and-machinery/air-conditioning-and-ventilation/identifying-poorly-ventilated-areas.htm   
[7] V. Greenwood, "Is Conference Room Air Making You Dumber?" The New York Times, 2019. https://www.nytimes.com/2019/05/06/health/conference-room-air.html   
[8] Adafruit SCD-30 Resources. https://learn.adafruit.com/adafruit-scd30   
[9] G. Lambert, "How to Write Data to Files on an SD Card with Arduino," Circuit Basics. https://www.circuitbasics.com/writing-data-to-files-on-an-sd-card-on-arduino/   
[10] "Arduino - RTC" Arduino Get Started. https://arduinogetstarted.com/tutorials/arduino-rtc   
[11] Adafruit RTClib, GitHub. https://github.com/adafruit/RTClib/tree/master/examples    

