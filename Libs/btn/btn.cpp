#include "Arduino.h"
#include "btn.h"

btn::btn(uint8_t _pin, HoldType _hType){
	pin = _pin;
	hType = _hType;
}
bool btn::CheckButton(){
  
  if(hType == CONSTANT){
    return digitalRead(pin);
  }
  
  bool btnState = false;
  if ((millis() - lTime) > dly) {
    btnState = digitalRead(pin);
    if(btnState != lstState || hType == TURBO){
            lstState = btnState;
      
      if(btnState){
        lTime = millis();
        return true;
      }

    }
  }
  return false;  
}