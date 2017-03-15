#include <Adafruit_NeoPixel.h>
#include <btn.h>
#include <pot.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif


#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(316, PIN, NEO_GRB + NEO_KHZ800);
btn BtnColor = btn(12, btn::HoldType::ONE_CLICK);
btn BtnBrght = btn(11, btn::HoldType::ONE_CLICK);
pot PotBrght = pot(4);
bool UpdateAnimation = false;
bool Blackout = false;

long NextColorUpdate = 0;
long NextBrghtUpdate = 0;

uint32_t pc1, pc2;

void setup() {
  Serial.begin(9600);
  pinMode(12, INPUT);
  pinMode(11, INPUT);
  strip.begin();
  strip.show();
  strip.setPixelColor(0, 0xFFFFFF);
  strip.show();
}


int incomingByte = -1;
void loop(){
    if (Serial.available() > 0) {
      Serial.println("Working...");
      incomingByte = Serial.parseInt();   
      Serial.print("Done: ");
      Serial.println(incomingByte);
      strip.setBrightness(incomingByte);
      UpdateAnimation = true;
  }
  ColorAnimationUpdate();
  
  if(BtnColor.CheckButton()){
    ChangeColorAnimation();
  }
  if(BtnBrght.CheckButton()){
    NextColorUpdate = millis();
  }

  UpdateStrip();
} 

//void BrghtByPot(){
//  //TODO: Fix PotSmoothing
//  uint8_t t = 4;
//  uint8_t brt = min(max(map(PotBrght.GetVal(), 50, 900, 1, 255), 1), 255);
//  uint8_t cBrt = strip.getBrightness();
//  if((cBrt - t) > brt ){
//    cBrt = brt;
//  }else if((cBrt + t) < brt){
//    cBrt = brt;
//  }
//  
//  strip.setBrightness(cBrt);
//  
//  
//  NextBrghtUpdate = millis() + 100;
//}


