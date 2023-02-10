// указывается пин с датчика через и тип датчика

#pragma once
#include <Arduino.h>

class InductiveSensor{
	private:
		byte _pin;
		uint64_t _tmr;
		bool _flag;
    bool _type;
	public:
		InductiveSensor(byte pin, String typeSensor){
			_pin = pin;
			pinMode(_pin, INPUT_PULLUP);
      if(typeSensor == "NPN"){
        _type = true;
      }
      else if(typeSensor == "PNP"){
        _type = false;
      }
		}
		bool approach(){
			bool inductiveState = digitalRead(_pin);
      if(_type){
        if(inductiveState && !_flag && millis() - _tmr >= 50){
  				_tmr = millis();
  				_flag = true;
  				return true;
  			}
  			if(inductiveState && _flag && millis() - _tmr >= 80){
  				_tmr = millis();
  				return true;
  			}
  			if(!inductiveState && _flag){
  				_tmr = millis();
  				_flag = false;
  			}
  			return false;
      }
			else{
        if(!inductiveState && !_flag && millis() - _tmr >= 50){
          _tmr = millis();
  				_flag = true;
  				return true;
        }
        if(!inductiveState && _flag && millis() - _tmr >= 80){
          _tmr = millis();
          return true;
        }
        if(inductiveState && _flag){
          _tmr = millis();
  				_flag = false;
        }
        return false;
      }
		}
};
