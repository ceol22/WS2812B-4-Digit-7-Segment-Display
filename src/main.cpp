#include <Arduino.h>
#include <FastLED.h>

//Define led settings
#define NUM_LEDS 30
#define DATA_PIN 6
#define BRIGHTNESS 50


// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
  // Add the leds to FastLED
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  //Set defined BRIGHTNESS
    FastLED.setBrightness(BRIGHTNESS);
}

void digit1(int num1){
  switch(num1){
    case 0:
      leds[3] = CRGB::Black;
    break;
    case 1:
       leds[0] = CRGB::Black;
       leds[1] = CRGB::Black;
       leds[3] = CRGB::Black;
       leds[4] = CRGB::Black;
       leds[5] = CRGB::Black;
    break;
    case 3:
      leds[0] = CRGB::Black;
      leds[4] = CRGB::Black;
    break;
    case 4:
      leds[1] = CRGB::Black;
      leds[4] = CRGB::Black;
      leds[5] = CRGB::Black;
    break;
    case 5:
      leds[2] = CRGB::Black;
      leds[4] = CRGB::Black;
    break;
    case 6:
      leds[2] = CRGB::Black;
    break;
    case 7:
      leds[0] = CRGB::Black;
      leds[3] = CRGB::Black;
      leds[4] = CRGB::Black;
      leds[5] = CRGB::Black;
    break;
    case 9:
      leds[4] = CRGB::Black;
    break;

  }
}

void digit2(int num2){
  switch(num2){
    case 0:
      leds[10] = CRGB::Black;
    break;
    case 1:
       leds[7] = CRGB::Black;
       leds[8] = CRGB::Black;
       leds[10] = CRGB::Black;
       leds[11] = CRGB::Black;
       leds[12] = CRGB::Black;
    break;
    case 3:
      leds[7] = CRGB::Black;
      leds[11] = CRGB::Black;
    break;
    case 4:
      leds[8] = CRGB::Black;
      leds[11] = CRGB::Black;
      leds[12] = CRGB::Black;
    break;
    case 5:
      leds[9] = CRGB::Black;
      leds[11] = CRGB::Black;
    break;
    case 6:
      leds[9] = CRGB::Black;
    break;
    case 7:
      leds[7] = CRGB::Black;
      leds[10] = CRGB::Black;
      leds[11] = CRGB::Black;
      leds[12] = CRGB::Black;
    break;
    case 9:
      leds[11] = CRGB::Black;
    break;

  }
}

void digit3(int num3){
  switch(num3){
    case 0:
      leds[19] = CRGB::Black;
    break;
    case 1:
       leds[16] = CRGB::Black;
       leds[17] = CRGB::Black;
       leds[19] = CRGB::Black;
       leds[20] = CRGB::Black;
       leds[21] = CRGB::Black;
    break;
    case 3:
      leds[16] = CRGB::Black;
      leds[20] = CRGB::Black;
    break;
    case 4:
      leds[17] = CRGB::Black;
      leds[20] = CRGB::Black;
      leds[21] = CRGB::Black;
    break;
    case 5:
      leds[18] = CRGB::Black;
      leds[20] = CRGB::Black;
    break;
    case 6:
      leds[18] = CRGB::Black;
    break;
    case 7:
      leds[16] = CRGB::Black;
      leds[19] = CRGB::Black;
      leds[20] = CRGB::Black;
      leds[21] = CRGB::Black;
    break;
    case 9:
      leds[20] = CRGB::Black;
    break;

  }
}

void digit4(int num4){
  switch(num4){
    case 0:
      leds[26] = CRGB::Black;
    break;
    case 1:
       leds[23] = CRGB::Black;
       leds[24] = CRGB::Black;
       leds[26] = CRGB::Black;
       leds[27] = CRGB::Black;
       leds[28] = CRGB::Black;
    break;
    case 3:
      leds[23] = CRGB::Black;
      leds[27] = CRGB::Black;
    break;
    case 4:
      leds[24] = CRGB::Black;
      leds[27] = CRGB::Black;
      leds[28] = CRGB::Black;
    break;
    case 5:
      leds[25] = CRGB::Black;
      leds[27] = CRGB::Black;
    break;
    case 6:
      leds[25] = CRGB::Black;
    break;
    case 7:
      leds[23] = CRGB::Black;
      leds[26] = CRGB::Black;
      leds[27] = CRGB::Black;
      leds[28] = CRGB::Black;
    break;
    case 9:
      leds[27] = CRGB::Black;
    break;

  }
}

void loop() {
  // put your main code here, to run repeatedly:
  fill_solid( leds, NUM_LEDS, CRGB::Red);
  digit1(1);
  FastLED.show();
  delay(500);
}
