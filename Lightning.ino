
int LightningMode = 20;
int LightningStep = 0;
int MaxLightningSteps = 2;
void Lightning(uint32_t c){
  Lightning(c, c);
}

void Lightning(uint32_t c1, uint32_t c2){
  
  if(LightningStep == MaxLightningSteps){
    pc1 = 0;
    reset();
    LightningMode = 20;
    LightningStep = 0;
  }
  if(pc1 == 0){
    pc1 = c1;
    pc2 = c2; 
  }
  switch(LightningMode){
    case 0:
      Rolling(pc1, pc2);
      break;
    case 1:
      crack(pc1);
      break;
    case 2:
      ZoneFlickerA(random(0,8), random(0,8), pc1, pc2);
      break;
    case 3:
      ZoneFlickerB(random(0,8), random(0,8), pc1, pc2);
      break;
    default:
      LightningMode = random(0,4);
      LightningSetups();
      NextColorUpdate = millis() + random(7000, 10000);
      break;
  }
  LightningStep++;
}
void LightningSetups(){
  switch(LightningMode){
    case 0:
      MaxLightningSteps = random(2,10);
      break;
    case 1:
      MaxLightningSteps = 1;
      break;
    case 2:
      MaxLightningSteps = 11;
      break;
    case 3:
      MaxLightningSteps = 16;
      break;
    default:
      break;
  }
}
void ZoneFlickerB(uint8_t z1, uint8_t z2, uint32_t c1, uint32_t c2){
  reset();
  switch(LightningStep){
    case 1:
    case 3:
    case 5:
      LightZone(z1, c1);
      break;
    case 7:
    case 9:
    case 11:
      LightZone(z2, c2);
      break;
    case 13:
    case 15:
      LightZone(z1, c1);
      LightZone(z2, c2);
      break;
    default:
      break;
  }
  NextColorUpdate = millis() + random(5,100);
}
void ZoneFlickerA(uint8_t z1, uint8_t z2, uint32_t c1, uint32_t c2){
  reset();
  switch(LightningStep){
    case 1:
    case 3:
      LightZone(z1, c1);
      break;
    case 5:
    case 7:
      LightZone(z2, c2);
      break;
    case 8:
    case 10:
      LightZone(z1, c1);
      LightZone(z2, c2);
    default:
      break;
    

  }
  NextColorUpdate = millis() + random(5,100);
}
void crack(uint32_t c){
  reset();
  for(int i=0;i<strip.numPixels();i++) {
    SolidColor(c);
  }
  NextColorUpdate = millis() + random(5,100);  
  return;
}
void Rolling(uint32_t c1, uint32_t c2){
  reset();
  for(int i=0;i<strip.numPixels();i++){
    if(random(0,100)>90){
      if(i % 2){
        strip.setPixelColor(i, c1);
      }else{
        strip.setPixelColor(i, c2);
      }
    }else{
      strip.setPixelColor(i, 0);
    }
  }
  NextColorUpdate = millis() + random(5,100);  
  
  return;
}
