#ifndef pot_h
#define pot_h
// #include "Arduino.h"
class pot{
public:
  static const uint8_t sReadsCount = 3;
  uint16_t WaitUntil;
	uint32_t Reads[sReadsCount];
	uint8_t 
    CurrentReadIndex = 0,
		pin;
	uint32_t GetVal();
  void Read();

	pot(uint8_t _pin);
private: 
};

#endif //pot_h