#include <Arduino.h>
#include <FastLED.h>
#include "RTCLib.h"

//Define led settings
#define NUM_LEDS 30
#define DATA_PIN 6
#define BRIGHTNESS 255



// Define the array of leds
CRGB leds[NUM_LEDS];

RTC_DS3231 rtc;


void setup() {
  // Add the leds to FastLED
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);

  //Set defined BRIGHTNESS
  FastLED.setBrightness(BRIGHTNESS);

Serial.begin(9600);

delay(3000); // wait for console opening

if (! rtc.begin()) {
  Serial.println("Couldn't find RTC");
  while (1);
}

if (rtc.lostPower()) {
  Serial.println("RTC lost power, lets set the time!");
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}
}

//Functions for deciding which leds have to turn off based on the number

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
    case 2:
       leds[0] = CRGB::Black;
       leds[6] = CRGB::Black;
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
    case 2:
       leds[7] = CRGB::Black;
       leds[13] = CRGB::Black;
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
    case 2:
       leds[16] = CRGB::Black;
       leds[22] = CRGB::Black;
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
    case 2:
       leds[25] = CRGB::Black;
       leds[29] = CRGB::Black;
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
  DateTime now = rtc.now();
  int hour = now.hour();
  int minute = now.minute();

  fill_solid( leds, NUM_LEDS, CRGB::Red);

  switch(hour){
    case 0:
      digit1(0);
      digit2(0);
    break;
    case 1:
      digit1(0);
      digit2(1);
    break;
    case 2:
      digit1(0);
      digit2(3);
    break;
    case 3:
      digit1(0);
      digit2(3);
    break;
    case 4:
      digit1(0);
      digit2(4);
    break;
    case 5:
      digit1(0);
      digit2(5);
    break;
    case 6:
      digit1(0);
      digit2(6);
    break;
    case 7:
      digit1(0);
      digit2(7);
    break;
    case 8:
      digit1(0);
      digit2(8);
    break;
    case 9:
      digit1(0);
      digit2(9);
    break;
    case 10:
      digit1(1);
      digit2(0);
    break;
    case 11:
      digit1(1);
      digit2(1);
    break;
    case 12:
      digit1(1);
      digit2(2);
    break;
    case 13:
      digit1(1);
      digit2(3);
    break;
    case 14:
      digit1(1);
      digit2(4);
    break;
    case 15:
      digit1(1);
      digit2(5);
    break;
    case 16:
      digit1(1);
      digit2(6);
    break;
    case 17:
      digit1(1);
      digit2(7);
    break;
    case 18:
      digit1(1);
      digit2(8);
    break;
    case 19:
      digit1(1);
      digit2(9);
    break;
    case 20:
      digit1(2);
      digit2(0);
    break;
    case 21:
      digit1(2);
      digit2(1);
    break;
    case 22:
      digit1(2);
      digit2(2);
    break;
    case 23:
      digit1(2);
      digit2(3);
    break;
  }
}
