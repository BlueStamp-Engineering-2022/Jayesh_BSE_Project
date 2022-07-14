#include <RTClib.h>
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 5

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 60 // Popular NeoPixel ring size

#define NOTEC3 131

RTC_DS3231 rtc;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
//for the piezosensor
const int threshold = 1000; //needs to change based on testing
const int piezoSensor = A0; 

int reading = 0; //variable to store what the piezo crystal reads

/*
   function to update RTC time using user input
*/
void updateRTC()
{

  // ask user to enter new date and time
  const char txt[6][15] = { "year [4-digit]", "month [1~12]", "day [1~31]",
                            "hours [0~23]", "minutes [0~59]", "seconds [0~59]"};
  String str = "";
  long newDate[6];

  while (Serial.available()) {
    Serial.read();  // clear serial buffer
  }

  for (int i = 0; i < 6; i++) {

    Serial.print("Enter ");
    Serial.print(txt[i]);
    Serial.print(": ");

    while (!Serial.available()) {
      ; // wait for user input
    }

    str = Serial.readString();  // read user input
    newDate[i] = str.toInt();   // convert user input to number and save to array

    Serial.println(newDate[i]); // show user input
  }

  // update RTC
  rtc.adjust(DateTime(newDate[0], newDate[1], newDate[2], newDate[3], newDate[4], newDate[5]));
  Serial.println("RTC Updated!");
}

DateTime now = rtc.now();
int mins = now.minute();
int hrs = now.hour();
int sec = now.second();
int flag = hrs/12;

//for the potentiometer
const int pmeter = A5;
const int value = 1;

int turnRead = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PIN, OUTPUT);
  pinMode(A5, INPUT);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(150);
  pixels.show();
  rtc.begin();
}

void trigger() {
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



void loop() {
  int NUMLIGHTED = NUMPIXELS/(720/(hrs*60 + mins));
  for (int i = 0; i < NUMLIGHTED; i ++) {
    pixels.setPixelColor(i, pixels.Color(255,0,255));
    pixels.show();
  }
  if (hrs == 7 && mins == 15)
  {
    while (reading < threshold) {
      if (reading >= threshold) {
        trigger();
      }
    }
  }
}
