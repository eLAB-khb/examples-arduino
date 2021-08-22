/**
* * Example on how to use the ARDUINO MOTOR SHIELD with a stepper motor
* * in combination with the Arduino Stepper Library
*
* Information on the shield:
*  https://www.arduino.cc/en/Main/ArduinoMotorShieldR3
*  
*/

#include <Stepper.h>

const int pwmA = 3;
const int pwmB = 11;
const int brakeA = 9;
const int brakeB = 8;
const int dirA = 12;
const int dirB = 13;

const int stepsPerRevolution = 200;

Stepper myStepper(stepsPerRevolution, dirA, dirB);


void setup() {
  Serial.begin(9600);

  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(brakeA, OUTPUT);
  pinMode(brakeB, OUTPUT);

  digitalWrite(pwmA, HIGH);
  digitalWrite(pwmB, HIGH);

  digitalWrite(brakeA, LOW);
  digitalWrite(brakeB, LOW);

  Serial.begin(9600);

  myStepper.setSpeed(60);
}


void loop() {

  myStepper.setSpeed(60);
  myStepper.step(2000);
  delay(1000);
}
