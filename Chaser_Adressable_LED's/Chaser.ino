#include <Adafruit_NeoPixel.h>

#define PIN 6
#define LENGTH 20

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LENGTH, PIN, NEO_GRB + NEO_KHZ800);

void setup(){
  strip.begin();
  strip.show();
}

void loop(){
  for (int i = 0; i <= strip.numpixels(); i++;){
    strip.setPixelColor(i,255,0,0);
    if (i>=1){ 
      strip.setPixelColor((i-1),0,0,0);
    }
    strip.show();
  }
  for (int i = 0; i <= strip.numpixels(); i++;){
    strip.setPixelColor((strip.numpixels-i),255,0,0);
    if (i>=1){
      strip.setPixelColor((strip.numpixels-i-1),0,0,0);
    }
    strip.show();
  }
}



