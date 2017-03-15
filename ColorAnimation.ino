const int COLOR_ANIMATIONS = 6;
enum ColorAnimations{ RANDOM_SOLID, RAINBOW, RAINBOW_SOLID, WHITE_LIGHTNING, COLOR_LIGHTNING, SOLID_TWO_TONE };
ColorAnimations ActiveColorAnimation = SOLID_TWO_TONE;
uint8_t ColorStep = 254, 
    MaxColorSteps = 255;
void ColorAnimationUpdate(){
  if(CheckTime(NextColorUpdate)){

    switch(ActiveColorAnimation)
    {
      case RANDOM_SOLID:
        RandomSolid();
        break;
      case RAINBOW:
        
        Rainbow();
        break;
       case RAINBOW_SOLID:
        RainbowSolid();
        break;
      case WHITE_LIGHTNING:
        Lightning(0xFFFFFF);
        break;
      case COLOR_LIGHTNING:
        Lightning(Wheel(random(0,256)), Wheel(random(0,256)));
        break;
      case SOLID_TWO_TONE:
        SolidTwoTone();
        break;
      default:
        SolidColor(0xFF00FF);
        NextColorUpdate = millis() + 200;
        break;
    }
    UpdateAnimation = true;
  }
}

void SolidTwoTone(){
  NextColorUpdate = millis() + 60000 * 5;
  pc1 = Wheel(random(0,255));
  pc2 = Wheel(random(0,255));
  LightZone(0, pc1);
  LightZone(1, pc2);
  LightZone(2, pc2);
  LightZone(3, pc1);
  LightZone(4, pc1);
  LightZone(5, pc2);
  LightZone(6, pc1);
  LightZone(7, pc2);
}
void RainbowSolid(){
  ColorStep = (ColorStep + 1) % MaxColorSteps;
  for(int i = 0; i < strip.numPixels(); i++){
    strip.setPixelColor(i, Wheel(ColorStep));
  }
  NextColorUpdate = millis() + 20;
}
void Rainbow(){
  ColorStep = (ColorStep + 1) % MaxColorSteps;
  
  for(int i = 0; i < strip.numPixels(); i++){
    strip.setPixelColor(i, Wheel((ColorStep + i) % 255));
  }
  NextColorUpdate = millis() + 4;
}
void RandomSolid(){
  SolidColor(Wheel(random(0,255)));
  NextColorUpdate = millis() + 60000 * 5;
}

void ChangeColorAnimation(){
  ActiveColorAnimation = static_cast<ColorAnimations>((ActiveColorAnimation + 1) % COLOR_ANIMATIONS);
  NextColorUpdate = millis();
  switch(ActiveColorAnimation){
    case WHITE_LIGHTNING:
    case COLOR_LIGHTNING:
      Serial.println("Thunder Setup");
      ColorStep = 2;
      MaxColorSteps = 2;
      pc1 = 0;
      reset();
      break;
    case SOLID_TWO_TONE:
      pc1 = Wheel(random(0,256));
      pc2 = Wheel(random(0, 256));
    default:
      Serial.println("Defulat Setup");
      ColorStep = 0;
      MaxColorSteps = 255;
      break;
  }
}
