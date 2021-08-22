/**
* * Example on how to use the ARDUINO MOTOR SHIELD with a DC motor
*
* Information on the shield:
*  https://www.arduino.cc/en/Main/ArduinoMotorShieldR3
*  
*/

#include "util.h"

//== CHANNEL A =======================================
//---- pin assignment --------------------------------
int pinDirA = 12;       // pin for motor direction (digital)
int pinPWMA = 3;        // pin for speed control (PWM)
int pinBrkA = 9;        // pin for brake (digital, HIGH = active)
int pinSnsA = A0;       // pin to measure current (3.3V = 2A = max current, don't use for anything else)

//== CHANNEL B =======================================
//---- pin assignment --------------------------------
int pinDirB = 13;       // pin for motor direction (digital)
int pinPWMB = 11;       // pin for speed control (PWM)
int pinBrkB = 8;        // pin for brake (digital, HIGH = active)
int pinSnsB = A1;       // pin to measure current (3.3V = 2A = max current, don't use for anything else)

//---- variable declarations -------------------------
boolean dirB = 1;       // save current direction
boolean brkB = false;   // save current brake state
float velB = 0;         // save current speed (velocity)
long lastToggleB = 0;   // save time of last direction toggle


void setup() {
  pinMode(pinDirA, OUTPUT);                        // direction control pin is OUTPUT
  pinMode(pinPWMA, OUTPUT);                        // speed control pin is OUTPUT
  pinMode(pinBrkA, OUTPUT);                        // brake control pin is OUTPUT

  Serial.begin(9600);                              // start serial connection for debugging
}


void loop() {

  if (millis() - lastToggleB > 5000) {             // ↓ toggle direction every 5 seconds
    dirB = !dirB;                                  //
    lastToggleB = millis();                        // ↑
  }

  velB = (sin(millis() * 0.003) + 1) * 0.5;        // generate sine wave for motor velocity with an amplitude of 0.0 to 1.0
  
  printInfo("B", dirB, velB);                      // print current settings to serial monitor

  velB = velB * 200 + 55;                          // map sine wave to analog values ( 0.0 … 1.0 ⇒ 55 … 255 )
  
  digitalWrite(pinBrkA, brkB);                     // set brake to current brake-state (OFF)
  digitalWrite(pinDirA, dirB);                     // set direction
  analogWrite(pinPWMA, velB);                      // set speed
  
}




















