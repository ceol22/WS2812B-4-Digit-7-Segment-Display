#include <Arduino.h>
#include <FastLED.h>
#include "RTClib.h"

//Define led settings
#define NUM_LEDS 30
#define DATA_PIN 6
#define BRIGHTNESS 255
#define FADEDELAY 100



// Define the array of leds
CRGB leds[NUM_LEDS];

// Name the RTC : rtc
RTC_DS3231 rtc;

//define ghue for rainbow fade effect
uint8_t gHue = 0;


void setup() {
  // Add the leds to FastLED
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);

  //Set defined BRIGHTNESS
  FastLED.setBrightness(BRIGHTNESS);

Serial.begin(9600);

delay(3000); // wait for console opening


if (! rtc.begin()) {  //Enable the RTC
  Serial.println("Couldn't find RTC");
  while (1);
}

if (rtc.lostPower()) { // Notify when RTC lost power
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
       leds[23] = CRGB::Black;
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
  int potVal = analogRead(1);

  Serial.println(potVal);
  if(potVal <100){ // IF potentiometer left: Rainbow Fade

      fill_solid(leds, NUM_LEDS, CHSV( gHue, 255, 255));
      EVERY_N_MILLISECONDS(FADEDELAY) {gHue++;}
  }

  if(potVal >= 100 && potVal <= 900 ){ // Map center of potentiometer to the colorspectrum
    int hsvcolor = map(potVal,100,900,0,255);
    fill_solid( leds, NUM_LEDS, CHSV(hsvcolor, 255, 255));
  }

  if(potVal >= 900){  // IF potentiometer Right fill with Rainbow
    fill_rainbow( leds, NUM_LEDS, 0, 8);

  }

 // set for every minute and hour which leds should be off
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

switch(minute){
  case 0:
    digit3(0);
    digit4(0);
  break;
  case 1:
    digit3(0);
    digit4(1);
  break;
  case 2:
    digit3(0);
    digit4(2);
  break;
  case 3:
    digit3(0);
    digit4(3);
  break;
  case 4:
    digit3(0);
    digit4(4);
  break;
  case 5:
    digit3(0);
    digit4(5);
  break;
  case 6:
    digit3(0);
    digit4(6);
  break;
  case 7:
    digit3(0);
    digit4(7);
  break;
  case 8:
    digit3(0);
    digit4(8);
  break;
  case 9:
    digit3(0);
    digit4(9);
  break;
  case 10:
    digit3(1);
    digit4(0);
  break;
  case 11:
    digit3(1);
    digit4(1);
  break;
  case 12:
    digit3(1);
    digit4(2);
  break;
  case 13:
    digit3(1);
    digit4(3);
  break;
  case 14:
    digit3(1);
    digit4(4);
  break;
  case 15:
    digit3(1);
    digit4(5);
  break;
  case 16:
    digit3(1);
    digit4(6);
  break;
  case 17:
    digit3(1);
    digit4(7);
  break;
  case 18:
    digit3(1);
    digit4(8);
  break;
  case 19:
    digit3(1);
    digit4(9);
  break;
  case 20:
    digit3(2);
    digit4(0);
  break;
  case 21:
    digit3(2);
    digit4(1);
  break;
  case 22:
    digit3(2);
    digit4(2);
  break;
  case 23:
    digit3(2);
    digit4(3);
  break;
  case 24:
    digit3(2);
    digit4(4);
  break;
  case 25:
    digit3(2);
    digit4(5);
  break;
  case 26:
    digit3(2);
    digit4(6);
  break;
  case 27:
    digit3(2);
    digit4(7);
  break;
  case 28:
    digit3(2);
    digit4(8);
  break;
  case 29:
    digit3(2);
    digit4(9);
  break;
  case 30:
    digit3(3);
    digit4(0);
  break;
  case 31:
    digit3(3);
    digit4(1);
  break;
  case 32:
    digit3(3);
    digit4(2);
  break;
  case 33:
    digit3(3);
    digit4(3);
  break;
  case 34:
    digit3(3);
    digit4(4);
  break;
  case 35:
    digit3(3);
    digit4(5);
  break;
  case 36:
    digit3(3);
    digit4(6);
  break;
  case 37:
    digit3(3);
    digit4(7);
  break;
  case 38:
    digit3(3);
    digit4(8);
  break;
  case 39:
    digit3(3);
    digit4(9);
  break;
  case 40:
    digit3(4);
    digit4(0);
  break;
  case 41:
    digit3(4);
    digit4(1);
  break;
  case 42:
    digit3(4);
    digit4(2);
  break;
  case 43:
    digit3(4);
    digit4(3);
  break;
  case 44:
    digit3(4);
    digit4(4);
  break;
  case 45:
    digit3(4);
    digit4(5);
  break;
  case 46:
    digit3(4);
    digit4(6);
  break;
  case 47:
    digit3(4);
    digit4(7);
  break;
  case 48:
    digit3(4);
    digit4(8);
  break;
  case 49:
    digit3(4);
    digit4(9);
  break;
  case 50:
    digit3(5);
    digit4(0);
  break;
  case 51:
    digit3(5);
    digit4(1);
  break;
  case 52:
    digit3(5);
    digit4(2);
  break;
  case 53:
    digit3(5);
    digit4(3);
  break;
  case 54:
    digit3(5);
    digit4(4);
  break;
  case 55:
    digit3(5);
    digit4(5);
  break;
  case 56:
    digit3(5);
    digit4(6);
  break;
  case 57:
    digit3(5);
    digit4(7);
  break;
  case 58:
    digit3(5);
    digit4(8);
  break;
  case 59:
    digit3(5);
    digit4(9);
  break;
}


  FastLED.show();

}
