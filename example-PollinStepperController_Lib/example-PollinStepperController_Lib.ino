/**
* * Example for the ULN2003A stepper motor controller
* * in combination with the Arduino Stepper Library
*   commonly used in conjunction with 28BYJ-48 stepper motors
*   (https://www.pollin.de/images/1600x1200x90/I310543.1-Schrittmotor-Set-DAYPOWER-S-SPSM-5V.jpg)
*
*   based on code by Stefan Thesens (https://blog.thesen.eu)
*   modified 24 Oct. 2017 by Felix Groll
*/

/**
*   Get steps per turn and RPM out of datasheet:
*   ============================================
*   5.625/64 deg per step --> 4096 steps for 360 deg
*   step relates to half-step sequencing, which means 8 steps
*   We use 4 full steps ==> 2048 steps per turn
*
*   recommended frequency range 600-1000Hz for 8 half-steps
*   1000Hz/4096 half-steps --> approx 4sec per turn is max speed
*   ==> 15rpm
*   Note: actually we will use ~500Hz using the 4 step approach
*   but motor will not be able to turn faster.
*
*   Get stepping sequence out of datasheet:
*   =======================================
*   Stepping sequence as given in datasheet
*   this is an 8-step half-step approach
*           Steps
*   Wire  1  2  3  4  5  6  7  8
*   1                    x  x  x
*   2              x  x  x
*   3        x  x  x
*   4     x  x                 x
*
*   We use only even / full steps thus:
*           Steps
*   Wire  2  4  6  8
*     1         x  x
*     2      x  x
*     3   x  x
*     4   x        x
*
*   Code of Arduino Stepper Lib has implemented:
*           Steps
*   Wire  1  2  3  4
*     1         x  x
*     2   x  x
*     3      x  x
*     4   x        x
*
*   ==> Simple Solution: exchange wire 2&3
*/

#include <Stepper.h>

const int stepsPerRevolution = 2048;

// D08 -> IN1
// D09 -> IN2
// D10 -> IN3
// D11 -> IN4

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup()
{
  myStepper.setSpeed(10); // Sets the speed at 10 rpm:
  Serial.begin(9600);     // Initializes the serial port
}

void loop()
{
  Serial.println("clockwise");
  myStepper.step(2 * stepsPerRevolution);     // two revolutions in one direction:
  delay(500);                                 // wait half a second

  Serial.println("counterclockwise");
  myStepper.step(-2 * stepsPerRevolution);    // two revolutions in the other direction:
  delay(500);                                 // wait half a second
}
