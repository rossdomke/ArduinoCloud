void UpdateStrip(){
  if(UpdateAnimation){
    strip.show();
    UpdateAnimation = false;
  }
}

void reset(){
  for(int i = 0; i< strip.numPixels(); i++){
    strip.setPixelColor(i, 0);
  }
}


bool CheckTime(long &Nxt){
  if(millis() > Nxt){
    return true;
  }
  return false;
}

void SolidColor(uint32_t c){
  for(uint16_t i=0; i < strip.numPixels(); i++){
      strip.setPixelColor(i,c);
  }
}
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void LightZone(int ZoneIndex, uint32_t c){
  uint16_t low, high;
  low = Zones[ZoneIndex];
  high = Zones[ZoneIndex + 1];
  
  for(int i = 0; i < strip.numPixels(); i++){
    if(i >= low && i < high){
        strip.setPixelColor(i, c);
    }
  }
}
bool Between(uint16_t x, uint16_t l, uint16_t h){
  if(l <= x && x < h){
    return true;
  }
  return false;
}

