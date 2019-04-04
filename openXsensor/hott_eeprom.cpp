#include "hott_eeprom.h"

struct HOTT_EEPROMDATA{
	float voltage_coef;
	float current_coef;
	int current_offset;
	byte protocol;
};

HOTT_EEPROMDATA hott_eepromdata;

void HOTT_EEPROM::write_eeprom(){
	#ifdef DEBUG
		Serial.println("Writing EEPROM");
	#endif
	EEPROM.write(EEPROM_ADDR, EEPROM_TEST_VALUE);
	EEPROM.put(EEPROM_ADDR +1 , hott_eepromdata);	
}

void HOTT_EEPROM::read_eeprom(){
	
	if (EEPROM.read(EEPROM_ADDR) == EEPROM_TEST_VALUE){			//EEPROM has been initialized, just read the data
		EEPROM.get(EEPROM_ADDR +1 , hott_eepromdata);
		#ifdef DEBUG
			Serial.print("Protocol: ");
			Serial.println(hott_eepromdata.protocol, HEX);
			Serial.print("V_Coef: ");
			Serial.println(hott_eepromdata.voltage_coef);
			Serial.print("C_Coef: ");
			Serial.println(hott_eepromdata.current_coef);
			Serial.print("C_Offs: ");
			Serial.println(hott_eepromdata.current_offset);			
		#endif
	} else {													//EEPROM not initialized, set initial data
		#ifdef DEBUG
			Serial.println("Writing standard values");
		#endif
		hott_eepromdata.voltage_coef = 128.2f;
		hott_eepromdata.current_coef = 100.0f;
		hott_eepromdata.current_offset = 0.0f;
		hott_eepromdata.protocol = HOTT_TELEMETRY_GAM_SENSOR_ID;
		write_eeprom();
	}	
}

float HOTT_EEPROM::get_voltage_coef(){ return hott_eepromdata.voltage_coef;}
float HOTT_EEPROM::get_current_coef(){ return hott_eepromdata.current_coef;}
int HOTT_EEPROM::get_current_offset(){ return hott_eepromdata.current_offset;}
byte HOTT_EEPROM::get_protocol(){ return hott_eepromdata.protocol;}

void HOTT_EEPROM::write_voltage_coef(float new_voltage_coef){
	hott_eepromdata.voltage_coef = new_voltage_coef;
}

void HOTT_EEPROM::write_current_coef(float new_current_coef){
	hott_eepromdata.current_coef = new_current_coef;
}

void HOTT_EEPROM::write_current_offset(int new_current_offset){
	hott_eepromdata.current_offset = new_current_offset;
}

void HOTT_EEPROM::write_protocol(byte new_protocol){
	hott_eepromdata.protocol = new_protocol;
}

