BOARD = arduino:avr:uno
PORT = /dev/ttyACM*

default: compile flash monitor

compile:
	arduino-cli compile --fqbn ${BOARD} ./

flash:
	arduino-cli upload --fqbn ${BOARD} -p ${PORT} ./

monitor:
	arduino-cli monitor -p ${PORT}
