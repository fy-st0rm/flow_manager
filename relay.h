#ifndef __RELAY_H__
#define __RELAY_H__
#define RELAY_PIN 3
#define LED_PIN 10

static void relay_init() {
	pinMode(RELAY_PIN, OUTPUT);
	pinMode(LED_PIN, OUTPUT);
}

static void relay_open() {
	Serial.println("Opening relay");
	digitalWrite(RELAY_PIN, LOW);
	digitalWrite(LED_PIN, HIGH);
}

static void relay_close(){
	Serial.println("Closing relay");
	digitalWrite(RELAY_PIN, HIGH);
	digitalWrite(LED_PIN, LOW);
}

#endif //__RELAY_H__
