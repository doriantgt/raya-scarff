#include "FastLED.h"
#define COLOR_ORDER GRB
#define NUM_LEDS 50   ////50 for rays 150 for room
#define NUM_STRIPS 1
CRGB leds[NUM_LEDS];

byte HueA=0;
byte SaturationA=255;
int BrightnessA=64;
CRGB Color1= CHSV(HueA,SaturationA,BrightnessA); //this is the unused Hue used for changinge numberd Hues

byte pushButton=10;
bool gButtonPressed;
bool gButtonWasPressed;
int gMode=10;

 byte chanceOfGlitter=50;

void setup() {
    FastLED.addLeds<WS2811,6,COLOR_ORDER>(leds, NUM_LEDS);
//pin 6 for ray
   pinMode(pushButton, INPUT_PULLUP);
  FastLED.setMaxPowerInMilliWatts(1200);

}

void loop() {
         gButtonPressed=digitalRead(pushButton);

if(gButtonPressed==false && gButtonWasPressed==true){
  gMode++; gMode%=11; gButtonWasPressed=false; delay(20);
  } 
if(gButtonPressed==true){
  gButtonWasPressed=true; delay(20);
  }
   EVERY_N_MILLISECONDS( 5000 ) {HueA++; HueA%=8; }

  
   EVERY_N_MILLISECONDS( 100 ) { 

    if(gMode<=6){
      colorpick();
    }
    if(gMode==7){
      whiteglitter();
    }
     if(gMode==8){
      whiteishglitter();
    }
      if(gMode==9){
      rainbowglitter();
    }
      if(gMode==10){
      colorCycle();
    }
    FastLED.show(); }
    
  

}
void colorpick(){
  
   SaturationA=255; BrightnessA=64;
   fadeToBlackBy( leds, NUM_LEDS, 1);

  if( random8() > chanceOfGlitter) {
    leds[ random8(NUM_LEDS) ] += CHSV(random8(gMode*32,((gMode*32)+32)),SaturationA,BrightnessA);
   }
    if( random8() > chanceOfGlitter) {
    leds[ random8(NUM_LEDS) ] += CHSV(random8(gMode*32,((gMode*32)+32)),SaturationA,BrightnessA);
   }
}

void whiteglitter(){
   
   SaturationA=0; BrightnessA=64;
   fadeToBlackBy( leds, NUM_LEDS, 1);

  if( random8() > chanceOfGlitter) {
    leds[ random8(NUM_LEDS) ] += CHSV(random8(),SaturationA,BrightnessA);
   }
    if( random8() > chanceOfGlitter) {
    leds[ random8(NUM_LEDS) ] += CHSV(random8(),SaturationA,BrightnessA);
   }
}

void whiteishglitter(){
   
   SaturationA=80; BrightnessA=64;
   fadeToBlackBy( leds, NUM_LEDS, 1);

  if( random8() > chanceOfGlitter) {
    leds[ random8(NUM_LEDS) ] += CHSV(random8(),SaturationA,BrightnessA);
   }
    if( random8() > chanceOfGlitter) {
    leds[ random8(NUM_LEDS) ] += CHSV(random8(),SaturationA,BrightnessA);
   }
}

void rainbowglitter(){
     SaturationA=255; BrightnessA=64;
   fadeToBlackBy( leds, NUM_LEDS, 1);

  if( random8() > chanceOfGlitter) {
    leds[ random8(NUM_LEDS) ] += CHSV(random8(),SaturationA,BrightnessA);
   }
    if( random8() > chanceOfGlitter) {
    leds[ random8(NUM_LEDS) ] += CHSV(random8(),SaturationA,BrightnessA);
   }
}

void colorCycle(){
  
   SaturationA=255; BrightnessA=64;
   fadeToBlackBy( leds, NUM_LEDS, 1);

  if( random8() > chanceOfGlitter) {
    leds[ random8(NUM_LEDS) ] += CHSV(random8(HueA*32,((HueA*32)+32)),SaturationA,BrightnessA);
   }
    if( random8() > chanceOfGlitter) {
    leds[ random8(NUM_LEDS) ] += CHSV(random8(HueA*32,((HueA*32)+32)),SaturationA,BrightnessA);
   }
}


void color1function(){Color1= CHSV(HueA,SaturationA,BrightnessA);}
