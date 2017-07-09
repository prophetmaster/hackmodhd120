/* Transform 12v led strip input to WS2812B CORSAIR HD120 RGB */
#include "EasyNeopixels.h"

#define PIN_G 9     // define pin pwm is attached input green
#define PIN_R 10    // define pin pwm is attached input red
#define PIN_B 11    // define pin pwm is attached input blue

#define OUTPUT_PIN 3 // pin to drive fan controler DA pin in controller board
#define LEDNUMBER 24 // number of led in strips 12 led's per fan
//#define MAXINTENSITY 255 // intensity 0 -255 

unsigned long pwm_g=0;
unsigned long pwm_r=0;
unsigned long pwm_b=0;


void setup() {
  Serial.begin(9600);

  pinMode(5, OUTPUT);             // sets the digital pin G
  pinMode(PIN_G, INPUT);          // sets the digital pin G
  pinMode(PIN_R, INPUT);          // sets the digital pin R
  pinMode(PIN_B, INPUT);          // sets the digital pin B

  setupEasyNeoPixels(OUTPUT_PIN, LEDNUMBER); // initialize led
}


void loop() {
  
  byte i = 0;

  int val = analogRead(0);        // read the input pin
  int val1 = analogRead(1);       // read the input pin
  int val2 = analogRead(2);       // read the input pin
  
  pwm_g = pulseIn(PIN_G, LOW);    // read the pwm from G pin map(val, 0, 1024, 0, MAXINTENSITY)
  pwm_r = pulseIn(PIN_R, LOW);    // read the pwm from R pin map(val1, 0, 1024, 0, MAXINTENSITY)
  pwm_b = pulseIn(PIN_B, LOW);    // read the pwm from B pin map(val2, 0, 1024, 0, MAXINTENSITY)

  while (i < LEDNUMBER){
    writeEasyNeoPixel(i, pwm_r, pwm_g, pwm_b);
  i++;
  }
  
  delay(10); // Wait (ms)
  
}
