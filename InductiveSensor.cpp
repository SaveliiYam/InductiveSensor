#include <InductiveSensor.h>

InductiveSensor::InductiveSensor(byte pin){
	_pin = pin;
	pinMode(_pin, INPUT_PULLUP);
}

bool InductiveSensor::targetMetall(){
	bool stateNow = digitalRead(_pin);
	if(!stateNow && !_state && millis() - _currentTime >= 2){
		_currentTime = millis();
		_state = true;
		return true;
	}
	if(!stateNow && _state && millis() - _currentTime >= 1){
		_currentTime = millis();
		return true;
	}
	if(stateNow && !_state){
		_state = false;
	}
	return false;
}