#ifndef HOTT_EEPROM_h
#define HOTT_EEPROM_h

#include "Arduino.h"
#include "oXs_config_basic.h"
#include "oXs_config_advanced.h"
#include <EEPROM.h>

#define HOTT_TELEMETRY_GAM_SENSOR_ID    0x8D // General Air Module ID 
#define HOTT_TELEMETRY_EAM_SENSOR_ID    0x8E // Electric Air Module ID

#define EEPROM_ADDR 512			//The EEprom offset address to save the data to
#define EEPROM_TEST_VALUE 0xAC		//(BYTE) Value will be written to eeprom and read back to check if EEPROM has been initalized

class HOTT_EEPROM{
	
	public:
	void write_eeprom();
	void read_eeprom();
	float get_voltage_coef();
	float get_current_coef();
	int get_current_offset();
	byte get_protocol();
	void write_voltage_coef(float new_voltage_coef);
	void write_current_coef(float new_current_coef);
	void write_current_offset(int new_current_offset);
	void write_protocol(byte new_protocol);
	
	private:
	
};

#endif	//HOTT_EEPROM_h