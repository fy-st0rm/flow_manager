#ifndef __STORE_H__
#define __STORE_H__

#include <EEPROM.h>

static void store_value(int addr, long int value) {
	Serial.print("Storing: ");
	Serial.println(value);
	for (int i = 0; i < (24/4); i++) {
		int x = (value >> (4 * i)) & 0x0F;
		EEPROM.write(addr++, x);
	}
}

static long int read_value(int addr) {
	long int val = 0;
	for (int i = 0; i < (24/4); i++) {
		long int x = EEPROM.read(addr++);
		val += (x << (4 * i));
	}

	Serial.print("Reading: ");
	Serial.println(val);
	return val;
}

#endif // __STORE_H__
