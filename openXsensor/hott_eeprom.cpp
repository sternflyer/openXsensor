#include "hott_eeprom.h"

struct HOTT_EEPROMDATA{
	float voltage_coef[6];
	int voltage_offset[6];
	byte voltage_pin[6];
	float current_coef;
	byte current_pin;
	int current_offset;
	byte sensor_type;
};

HOTT_EEPROMDATA hott_eepromdata;

void HOTT_EEPROM::write_eeprom(){
	EEPROM.write(EEPROM_ADDR, EEPROM_TEST_VALUE);
	EEPROM.put(EEPROM_ADDR +1 , hott_eepromdata);	
}

void HOTT_EEPROM::read_eeprom(){
	
	if (EEPROM.read(EEPROM_ADDR) == EEPROM_TEST_VALUE){			//EEPROM has been initialized, just read the data
		EEPROM.get(EEPROM_ADDR +1 , hott_eepromdata);
		#ifdef DEBUG
			Serial.print("Sensor Type: ");
			Serial.println(hott_eepromdata.sensor_type, HEX);
			for (byte i = 0; i < 6; i++){
				Serial.print("V_Coef");
				Serial.print(i);
				Serial.print(": ");
				Serial.println(hott_eepromdata.voltage_coef[i]);
				
				Serial.print("V_Offs");
				Serial.print(i);
				Serial.print(": ");
				Serial.println(hott_eepromdata.voltage_offset[i]);
				
			}
			Serial.print("C_Coef: ");
			Serial.println(hott_eepromdata.current_coef);
			Serial.print("C_Offs: ");
			Serial.println(hott_eepromdata.current_offset);			
		#endif
	} else {													//EEPROM not initialized, set initial data
		#ifdef DEBUG
			Serial.println("Writing standard values");
		#endif
		
		for (byte i = 0; i < 6; i++){
			hott_eepromdata.voltage_coef[i] = 128.2f;
			hott_eepromdata.voltage_offset[i] = 0.0f;
			hott_eepromdata.voltage_pin[i] = 8;
		}
		hott_eepromdata.current_coef = 100.0f;
		hott_eepromdata.current_offset = 0.0f;
		hott_eepromdata.current_pin = 8;
		hott_eepromdata.sensor_type = HOTT_TELEMETRY_GAM_SENSOR_ID;
		write_eeprom();
	}	
}

float HOTT_EEPROM::get_voltage_coef(byte volt_number){ return hott_eepromdata.voltage_coef[volt_number];}

int HOTT_EEPROM::get_voltage_offset(byte volt_number){ return hott_eepromdata.voltage_offset[volt_number];}

byte HOTT_EEPROM::get_voltage_pin(byte volt_number){ return hott_eepromdata.voltage_pin[volt_number];}

byte HOTT_EEPROM::get_current_pin(){ return hott_eepromdata.current_pin;}

float HOTT_EEPROM::get_current_coef(){ return hott_eepromdata.current_coef;}

int HOTT_EEPROM::get_current_offset(){ return hott_eepromdata.current_offset;}

byte HOTT_EEPROM::get_sensor_type(){ return hott_eepromdata.sensor_type;}

void HOTT_EEPROM::write_voltage_pin(byte volt_number, byte new_voltage_pin){
	hott_eepromdata.voltage_pin[volt_number] = new_voltage_pin;
}

void HOTT_EEPROM::write_voltage_coef(byte volt_number, float new_voltage_coef){
	hott_eepromdata.voltage_coef[volt_number] = new_voltage_coef;
}
	
void HOTT_EEPROM::write_voltage_offset(byte volt_number, int new_voltage_offset){
	hott_eepromdata.voltage_offset[volt_number] = new_voltage_offset;
}

void HOTT_EEPROM::write_current_pin(byte new_current_pin){
	hott_eepromdata.current_pin = new_current_pin;
}

void HOTT_EEPROM::write_current_coef(float new_current_coef){
	hott_eepromdata.current_coef = new_current_coef;
}

void HOTT_EEPROM::write_current_offset(int new_current_offset){
	hott_eepromdata.current_offset = new_current_offset;
}

void HOTT_EEPROM::write_sensor_type(byte new_sensor_type){
	hott_eepromdata.sensor_type = new_sensor_type;
}

