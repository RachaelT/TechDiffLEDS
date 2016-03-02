
#include <FastLED.h>


//#include <Adafruit_NeoPixel.h>
//#include "WS2812_Definitions.h"


  // put your setup code here, to run once:
#define DATA_PIN 4
#define NUM_LEDS 61
#define NUM_FRAMES 3
char frame[][NUM_LEDS]= {{"1a2a3a4a5a6a7a8a9a0a1a2a3a4a5a6a7a8a9a0a1a2a3a4a5a6a7a8a9a0a"}, 
                         {"a1a2a3a4a5a6a7a8a9a0a1a2a3a4a5a6a7a8a9a0a1a2a3a4a5a6a7a8a9a0"},
                         {"1a2a3a4a5a6a7a8a9a0a1a2a3a4a5a6a7a8a9a0a1a2a3a4a5a6a7a8a9a0a"}};

char unicorn[] = "azazaazaazazazazaazazaazazaazaazaazazaazazaazazzzzzzzzzzzzzz";
// Create an instance of the Adafruit_NeoPixel class called "leds".
// That'll be what we refer to from here on...
//Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);
CRGB leds[NUM_LEDS];
void setup()
{
  
   FastLED.addLeds<NEOPIXEL, 4>(leds, 60); 
  clearLEDS();
}


void loop() {
  
  // put your main code here, to run repeatedly:

  ///static uint8_t hue = 0;
 //readFrame(frame[0], 0);
animate(frame, 0, 100);
 }
void chaser(){
  for(int k = 0; k < NUM_LEDS; k++){
  for(int i = 0; i < NUM_LEDS; i+=3){
    int j =(i+k)%NUM_LEDS;
    leds[j] = CHSV(255, 255, 255);
  }
  for(int i = 1; i < NUM_LEDS; i+=3){
    int j =(i+k)%NUM_LEDS;
    leds[j] = CRGB::White;
  }
  for(int i = 2; i < NUM_LEDS; i+=3){
    int j =(i+k)%NUM_LEDS;
    leds[j] = CHSV(170, 255, 255);
  }
  FastLED.show();
  delay(100);
  }
}

void blue50(){
   uint8_t hue = 130;
  for(int i = 0; i < NUM_LEDS; i++){
    leds[i] = CHSV(hue++, 255, 255);
  }
  FastLED.show();
}

void animate(char f[][NUM_LEDS], int startPt, int d){
  for(int i = 0; i < NUM_FRAMES; i++){
    readFrame(f[i], startPt);
    delay(d);
  }
}
 
 void shiftForward(char f[], int d){
  for(int i = 0; i < NUM_LEDS; i++){
     readFrame(f, i);
     delay(d);
  }
 }

  void shiftReverse(char f[], int d){
  for(int i = NUM_LEDS - 1; i > 0; i--){
     readFrame(f, i);
     delay(d);
  }
  }
 
void readFrame(char f[], int startPt){
  for(int i = 0; i < NUM_LEDS; i++){
    int k = (i + startPt) % NUM_LEDS;
    leds[i] = CHSV(int(f[k]), 255, 255);
  }
  FastLED.show();
}

void clearLEDS()
{
  FastLED.showColor(CHSV(0, 0, 0));
}



