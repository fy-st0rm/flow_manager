#include "keypad.h"
#include "lcd.h"
#include "flow_sensor.h"
#include "relay.h"
#include "store.h"

#define STORE_ADDR 0

typedef enum {
	MODE_INPUT,
	MODE_FLOW
} Mode;

String input = "";
Mode mode = INPUT;
long int desired_vol = 0;

FlowSensor* sensor = calloc(1, sizeof(FlowSensor));

void sensor_callback() {
	sensor->pulse++;
}

void setup() {
	Serial.begin(9600);
	lcd_init();
	sensor_init(&sensor_callback);
	relay_init();
	relay_close();

	long int val = read_value(STORE_ADDR);
	if (val) {
		input = String(val);
		lcd_display(input);
	}
}

//#define DEBUG

void loop() {
#ifdef DEBUG
	int val = get_key_value();
	//Serial.println(val);
	lcd_display(String(val));
	delay(500);
#endif

#ifndef DEBUG
	char key = get_pressed_key();

	if (mode == MODE_INPUT) {
		switch (key) {
			case 'A':
				if (input.length()) {
					desired_vol = input.toInt();
					store_value(STORE_ADDR, desired_vol);
					mode = MODE_FLOW;
					relay_open();
				}
				break;
			case 'B': {
				if (input.length()) {
					input.remove(input.length() - 1);
				}
				if (input.length()) {
					lcd_display(input);
				} else {
					lcd_display(" ");
				}
				break;
			}
			case 'C': {
				input = "";
				lcd_display(" ");
				break;
			}
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': {
				if (input.length() <= 8) {
					input += key;
					lcd_display(input);
				}
				break;
			}
		}
	} else if (mode == MODE_FLOW) {
		float vol = get_volumn(sensor);
		Serial.print(vol);
		Serial.print("/");
		Serial.println(desired_vol);
		if (vol >= desired_vol) {
			mode = MODE_INPUT;
			sensor_reset(sensor);
			relay_close();
		}
	}
#endif
}
