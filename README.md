# arduino-GreenhouseController

This sketch file will activate a servo motor to open/close a small window and to start/stop a dc fan in response to the changing temperature. 

When the temperature is read above the highTempC value the servo will open a small window in the greenhouse enclosure and start a small dc fan. On the flipside, when the temperature is read below the lowTempC value, the servo will close the window and stop the fan. 

The servo motor is connected to PIN 9.
The DC motor to PIN 11 (via a common emitter amplifier). 
The temperature sensor is connected to A0.
