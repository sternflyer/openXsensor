## OpenXsensor with extended HoTT functionalities

This poject is forked from the original openXsensor project
For more details about openXsensor in general, please visit the project page at https://github.com/openXsensor/openXsensor.

## OpenXsensor New Home
_from may 2015_

![OXS logo](https://github.com/openXsensor/openXsensor/wiki/images/OXS_Logo.png)


### Introduction

OpenXsensor is the evolution of [OpenXvario](https://code.google.com/p/openxvario/) and extends it to multi-sensing applications.

Discussion about this project: http://openrcforums.com/forum/viewforum.php?f=86

Based on an [Arduino](http://arduino.cc/) platform, it connects to different sensors and transmits the measurements via several telemetry capabilities.

It is compatible with :
  * The Multiplex receivers
  * The Frsky receivers : *D series* (HUB protocol) and *X series* (Smart Port protocol).
  * The Graupner receivers (Hott protocol)
  * The Jeti receivers (EX protocol only)

### Functionalities provided at your choice :

  * Altimeter / Variometer
    * Uses normally a MS5611 sensor (GY-63 or GY-86 module)
	* Alternatives: a BMP085, a BMP180 or a BMP280 sensor can be used as first sensor
	* A second barometric sensor can be added
	* Possibility to change vario sensitivity and/or to switch between 2 vertical speeds from TX while flying
  * Air Speed
    * Uses normally a 4525DO-DS5AI001DP sensor
	* Alternative: ADS1115 + MPXV7002DP
	* Can also be used by oXs to compensate vertical speed measurements (dTE)
  * GPS
    * Can be connected to a GPS (NEO6/NEO7/NEO8) and transmit collected data
  * Accelerometer/gyroscope
    * Can be connected to a MPU6050 sensor (e.g. GY-86 module)
    * Can calculate vertical speed based on acceleration + baro (faster reaction of vario)
	* Can calculate Roll and Pitch for attitude indicator (using a Lua script on OpenTx) 
  * Up to 6 voltages measurements with Arduino
    * Battery voltage measurements
    * Lipo battery cell measurements
  * Up to 4 more accurate (and/or lower) voltages measurements with an extra ADC
    * Uses a ADS1115 module
    * Can be combined with Current and Airspeed sensor
  * RPM sensor
  * Current sensor
    * Max Amp depends on the sensor being used (e.g. ACS712, ACS754, ACS758) 
	* Can calculate the consumed current
  * Flow sensor (provides actual flow, remaining tank capacity in ml and %)	
  * Can use any sensor outputting voltage
    * Conversion from Volt to other units (e.g. to degree for temperature sensor)
	* Can be associate with termistor
  * Can calculate glider ratio to improve glider setup while flying
  * Can generate several sequences of signal (e.g. for light sequencer)
  
Note: Setup is done editing manually the files oXs_config_basic.h and (in some cases oXs_config_advanced.h)
	  All details about the requirements and the way to configure oXs are given in the file oXs_config_description.h
	  Some explanations are given in wiki (but are not 100% up to date). It is safe to higtly recommended to read oXs_config_description.h 

Note: Latest version ( recommended) of oXs is the branch "master".
	In old version of openXsensor (oXs), it was possible to use a configurator program in order to create the config.h file.
	The Wiki refers to this configurator. Still, after version 2.5, the configurator program has not been updated.
	So, when using the latest versions of oXs (recommended), you must edit the config.h file with a text editor (or the Arduino IDE).
