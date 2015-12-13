#include <Adafruit_NeoPixel.h>

const int analogInPin = 1;  // Physical pin 2, is analog pin 1
const int neopixelPin = 6;
const int numPixels = 10;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numPixels, neopixelPin, NEO_GRB + NEO_KHZ800);
int sensorValue = 0;        // value read from the pot

void setup() {
  pinMode(9, INPUT_PULLUP); 
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);              

  if (sensorValue < 100){
    colorWipe(strip.Color(255, 0, 0), 25);
    colorWipe(strip.Color(0, 0, 0), 25);
  }  
}

void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
