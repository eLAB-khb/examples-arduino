/**
* * Example on how to use the ARDUINO MOTOR SHIELD with a stepper motor
* * without additional libraries
*
* Information on the shield:
*  https://www.arduino.cc/en/Main/ArduinoMotorShieldR3
*  
*/

// CHANNEL A
const int pinDirA = 12;
const int pinPWMA = 3;
const int pinBrkA = 9;
const int pinSnsA = A0;

// Channel B
const int pinDirB = 13;
const int pinPWMB = 11;
const int pinBrkB = 8;
const int pinSnsB = A1;

boolean dir = 1;
boolean brk = false;
float vel = 0;
long start = 0;

void setup() {
  pinMode(pinDirA, OUTPUT);
  pinMode(pinPWMA, OUTPUT);
  pinMode(pinBrkA, OUTPUT);

  pinMode(pinDirB, OUTPUT);
  pinMode(pinPWMB, OUTPUT);
  pinMode(pinBrkB, OUTPUT);

  digitalWrite(pinBrkA, brk);
  digitalWrite(pinBrkB, brk);

  Serial.begin(9600);
}

void loop() {
  // EXAMPLE 1 -----------------------------
  //*
    if (millis() - start > 5000) {
    dir = !dir;
    start = millis();
    }

    vel = (sin(millis() * 0.001) + 1) * 0.5;


    int del = vel*5+1;
    stepLeft(del);

  // EXAMPLE 2 -----------------------------
  /*/
    for (int i = 0; i < 200; i++)
    {
    stepLeft(1);
    }

    delay(500);

    for (int i = 0; i < 100; i++)
    {
    stepRight(5);
    }
    delay (500);
  //*/
}

void stepLeft(int theDelay)
{
  boolean polarity = 0;
  digitalWrite(pinDirA, polarity);
  digitalWrite(pinPWMA, 255);
  digitalWrite(pinPWMB, 0);

  delay(theDelay);

  digitalWrite(pinDirB, polarity);
  digitalWrite(pinPWMA, 0);
  digitalWrite(pinPWMB, 255);

  delay(theDelay);

  digitalWrite(pinDirA, !polarity);
  digitalWrite(pinPWMA, 255);
  digitalWrite(pinPWMB, 0);

  delay(theDelay);

  digitalWrite(pinDirB, !polarity);
  digitalWrite(pinPWMA, 0);
  digitalWrite(pinPWMB, 255);

  delay(theDelay);
}

void stepRight(int theDelay)
{
  boolean polarity = 0;
  digitalWrite(pinDirA, polarity);
  digitalWrite(pinPWMA, 255);
  digitalWrite(pinPWMB, 0);

  delay(theDelay);

  digitalWrite(pinDirB, !polarity);
  digitalWrite(pinPWMA, 0);
  digitalWrite(pinPWMB, 255);

  delay(theDelay);

  digitalWrite(pinDirA, !polarity);
  digitalWrite(pinPWMA, 255);
  digitalWrite(pinPWMB, 0);

  delay(theDelay);

  digitalWrite(pinDirB, polarity);
  digitalWrite(pinPWMA, 0);
  digitalWrite(pinPWMB, 255);

  delay(theDelay);
}
