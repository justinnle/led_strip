#include <Adafruit_NeoPixel.h>
int MAX_BRIGHTNESS = 150;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(144, 13, NEO_GRB + NEO_KHZ800);
const int analogInPin = A4;

boolean running = false;
void setup() {
  digitalWrite(analogInPin, HIGH);
  Serial.begin(9600);
  strip.begin();
  for(int i = 0; i < 144; i++) {
    turnOff(i);
  }
  strip.show();
}

void loop() {
  int input = analogRead(analogInPin);
  Serial.println(input);
  delay(75);
  if(input < 100) {
    running = true;
  }
  if(running) {
    Serial.print("on");
    wholeStripShades();
    running = false;
  }
}

void fourColorBlink() {
  turnOff(16);
  strip.setPixelColor(10,100,0,0);
  delay(500);
  strip.show();
  turnOff(10);
  strip.setPixelColor(12,0,100,0);
  delay(500);
  strip.show();
  turnOff(12);
  strip.setPixelColor(14,0,0,100);
  delay(500);
  strip.show();
  turnOff(14);
  strip.setPixelColor(16,100,100,100);
  delay(500);
  strip.show();
}

void wholeStripShades() {
  for(int i=0; i < 144; i++) { 
    turnOff(i - 1);
    strip.setPixelColor(i, i*MAX_BRIGHTNESS/144, 0, MAX_BRIGHTNESS - i*MAX_BRIGHTNESS/144);  
    delay(10);
    strip.show();
  }
  turnOff(143);
  strip.show();
}

void testTouchSensor() {
    if(analogRead(4) > 20) {
    strip.setPixelColor(60,00,100,0);
    strip.show();
  } else {
    turnOff(60);
    strip.show();
  }
}
void turnOff(int n) {
  strip.setPixelColor(n, 0, 0, 0);
}

