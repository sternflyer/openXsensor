#ifndef HOTT_EEPROM_h
#define HOTT_EEPROM_h

#include "Arduino.h"
#include "oXs_config_basic.h"
#include "oXs_config_advanced.h"
#include <EEPROM.h>

#define HOTT_TELEMETRY_GAM_SENSOR_ID    0x8D // General Air Module ID 
#define HOTT_TELEMETRY_EAM_SENSOR_ID    0x8E // Electric Air Module ID

#define EEPROM_ADDR 512			//The EEprom offset address to save the data to
#define EEPROM_TEST_VALUE 0xAD		//(BYTE) Value will be written to eeprom and read back to check if EEPROM has been initalized

class HOTT_EEPROM{
	
	public:
	void write_eeprom();
	void read_eeprom();
	byte get_voltage_pin(byte volt_number);
	float get_voltage_coef(byte volt_number);
	int get_voltage_offset(byte volt_number);
	byte get_current_pin();
	float get_current_coef();
	int get_current_offset();
	byte get_sensor_type();
	void write_voltage_pin(byte volt_number, byte new_voltage_pin);
	void write_voltage_coef(byte volt_number, float new_voltage_coef);
	void write_voltage_offset(byte volt_number, int new_voltage_coef);
	void write_current_pin(byte new_current_pin);
	void write_current_coef(float new_current_coef);
	void write_current_offset(int new_current_offset);
	void write_sensor_type(byte new_sensor_type);
	
	private:
	
};

#endif	//HOTT_EEPROM_h