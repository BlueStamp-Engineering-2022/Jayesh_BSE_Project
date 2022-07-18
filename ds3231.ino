// Date and time functions using a DS3231 RTC connected via I2C and Wire lib
#include "RTClib.h"
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 5

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 35 // Popular NeoPixel ring size

#define NOTE 2000

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
//for the piezosensor
const int threshold = 1000; //needs to change based on testing
const int piezoSensor = A0; 
int buzzer = 3;
int reading = 0; //variable to store what the piezoelectric sensor reads

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () {
  Serial.begin(57600);
  pinMode(PIN, OUTPUT);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(255);
  pixels.show();
#ifndef ESP8266
  while (!Serial); // wait for serial port to connect. Needed for native USB
#endif

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  // When time needs to be re-set on a previously configured device, the
  // following line sets the RTC to the date & time this sketch was compiled
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // This line sets the RTC with an explicit date & time, for example to set
  // January 21, 2014 at 3am you would call:
  // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
}

void trigger() {
  noTone(buzzer);
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright purple color:
    pixels.setPixelColor(i, pixels.Color(255, 0, 255));
    pixels.show();
    delay(14.3);
  }
  for(int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
    delay(14.3);
  }
}

void loop () {
    DateTime now = rtc.now();
    int NUMLIGHTED = NUMPIXELS/(round(double((720.0/((now.hour()%12)*60.0 + double(now.minute()))))));
//    Serial.println(now.minute());
    for (int i = 0; i < NUMLIGHTED; i ++) {
      pixels.setPixelColor(i, pixels.Color(137, 207, 240));
      pixels.show();
    }

    if(now.hour() == 16 && now.minute() == 29) {
      bool x = true;
      int min = now.minute();

      while (x == true) {
        reading = analogRead(A0);
        tone(buzzer, NOTE);
        if (reading >= threshold) {
          trigger();
          noTone(buzzer);
          x = false;
          buzzer = 9;
        }
      }

    }


    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println(); 


    delay(1000);
    
}
