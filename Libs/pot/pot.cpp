#include "Arduino.h"
#include "pot.h"



pot::pot(uint8_t _pin){
  pin = _pin;
}

uint32_t pot::GetVal(){
  return analogRead(pin);
  // uint32_t retVal = Reads[0];
  // for(int i =1; i < sReadsCount; i++){
  //   retVal = (retVal + Reads[i]) / 2;
  // }
  // return retVal;
}

void pot::Read(){
    // Reads[CurrentReadIndex] = analogRead(pin);
    // CurrentReadIndex = (CurrentReadIndex + 1) % sReadsCount;
}
