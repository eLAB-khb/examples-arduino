/**
* * Example on how to use the ARDUINO MOTOR SHIELD for LED control
*
* Information on the shield:
*  https://www.arduino.cc/en/Main/ArduinoMotorShieldR3
*  
*/

int pwmA = 3;
int brakeA = 9;
int dirA = 12;

int pwmB = 11;
int brakeB = 8;
int dirB = 13;

void setup()
{
  // Initialize Motor Shield
  pinMode(pwmA, OUTPUT);
  pinMode(brakeA, OUTPUT);
  pinMode(dirA, OUTPUT);
  digitalWrite(brakeA, LOW);
  digitalWrite(dirA, HIGH);     //! see shield polarity

  pinMode(pwmB, OUTPUT);
  pinMode(brakeB, OUTPUT);
  pinMode(dirB, OUTPUT);
  digitalWrite(brakeB, LOW);
  digitalWrite(dirB, HIGH);     //! see shield polarity

  // Initialize Serial Communication
  Serial.begin(9600);
}

void loop()
{
  int valueA = int(sin(millis() * 0.0010) * 255.0);
  int valueB = int(sin(millis() * 0.0005) * 255.0);
  Serial.println(String(valueA) + "\t" + String(valueB));

  // Set LEDs
  analogWrite(pwmA, valueA);
  analogWrite(pwmB, valueB);
}
