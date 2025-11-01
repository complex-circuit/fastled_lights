#include <FastLED.h>
#define NUM_LEDS 240
#define DATA_PIN 8 
CRGB leds[NUM_LEDS];
void setup() {
  FastLED.addLeds<WS2812B,DATA_PIN>(leds,NUM_LEDS);
}
boolean direction=true;
CRGB color;
CRGB color2;

short light=0;
void loop() {

  color.setHue( (millis()/13)%256 );
  color2.setHue( (millis())%256 );

  short light2=random(0,NUM_LEDS);
  if(light>=NUM_LEDS-1)direction=false;
  if(light<=0)direction=true;
  light=light+(direction?1:-1);
  for(short i=0;i<NUM_LEDS;i++){
    //I put .g first because the LED strip I'm working with has red and green swapped.
    //This may or may not be due to not knowing what chipset it uses...
    leds[i].g=color.r*(i==light) + color2.r*(i==light2) + leds[i].r*0.9*(i!=light&&i!=light2);
    leds[i].r=color.g*(i==light) + color2.g*(i==light2) + leds[i].g*0.9*(i!=light&&i!=light2);
    leds[i].b=color.b*(i==light) + color2.b*(i==light2) + leds[i].b*0.9*(i!=light&&i!=light2);
  }
  FastLED.show();

}
