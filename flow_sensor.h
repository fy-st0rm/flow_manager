#ifndef __FLOW_SENSOR_H__
#define __FLOW_SENSOR_H__

#define BIAS 2.663
#define SENSOR_PIN 2

typedef struct {
	long pulse;
} FlowSensor;

static void sensor_init(void (*callback)()) {
	pinMode(SENSOR_PIN, INPUT);
	attachInterrupt(
		digitalPinToInterrupt(SENSOR_PIN),
		callback,
		RISING
	);
}

static void sensor_reset(FlowSensor* sensor) {
	Serial.println("Reseting sensor");
	sensor->pulse = 0;
}

static float get_volumn(FlowSensor* sensor) {
	float vol = BIAS * sensor->pulse;
	return vol;
}

#endif // __FLOW_SENSOR_H__
