#pragma once
#include <Arduino.h>

class InductiveSensor{
	private:
		byte _pin;
		bool _state = false;
		uint32_t _currentTime;
	public:
		InductiveSensor(byte pin);
		bool targetMetall();
};

