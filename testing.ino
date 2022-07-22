#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 5

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 60 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//set up constants (threshold to determine if its a dart, which pin the piezo is connected to)
const int threshold = 1023; //needs to change based on testing
const int piezoSensor = A0; 

int reading = 0; //variable to store what the piezo crystal reads



void setup() {
  Serial.begin(19200);
  pinMode(PIN, OUTPUT);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

}

void loop() {
  reading = analogRead(piezoSensor);
  Serial.println(reading);
  if (reading >= threshold) {
    for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

      // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
      // Here we're using a moderately bright purple color:
      pixels.setPixelColor(i, pixels.Color(120, 100, 50));
      pixels.show();
      delay(10);
    }
    for(int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      pixels.show();
      delay(14.3);
    }
    Serial.println(reading);
  }
}
