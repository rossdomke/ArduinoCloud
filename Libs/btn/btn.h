#ifndef btn_h
#define btn_h
// #include "Arduino.h"
class btn{
public:
	enum HoldType{ CONSTANT, TURBO, ONE_CLICK };

	HoldType hType;
	long lTime;
	uint8_t 
		dly,
		pin;
	bool
	  btnState,
	  lstState;
	bool CheckButton();

	btn(uint8_t _pin, HoldType _hType);
private: 
};

#endif //btn_h


/*
enum HoldType{ CONSTANT, TURBO, ONE_CLICK };

long lTime = 0;
uint8_t dly = 50;
bool btnState = 0;
bool lstState = 0; 

bool CheckButton(uint8_t btnPin, int8_t hType){
  if(hType == CONSTANT){
    return digitalRead(btnPin);
  }
  if ((millis() - lTime) > dly) {
    btnState = digitalRead(btnPin);
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

*/