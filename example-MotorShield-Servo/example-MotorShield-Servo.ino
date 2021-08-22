/**
* * Example on how to use the ARDUINO MOTOR SHIELD with a servo motor
*
* Information on the shield:
*  https://www.arduino.cc/en/Main/ArduinoMotorShieldR3
*  
*/

#include "util.h"
#include <Servo.h>

Servo myservo;                           // create servo object to control a servo

const int pinServo = 5;
float val;

void setup() {
  myservo.attach(pinServo);              // attaches the servo on pin X to the servo object
  Serial.begin(9600);
}

void loop() {
  val = (sin(millis() * 0.003) + 1) * 0.5;
  
  printPercentage(val);
  Serial.print("\t");
  Serial.println(val);
  
  myservo.write(val*160);         // tell servo to got to the new position

  delay(15);                      // wait for the servo to get there
}
