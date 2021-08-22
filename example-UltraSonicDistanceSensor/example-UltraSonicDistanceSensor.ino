/*
 *  Example for the HC-SR04 Ultra Sonic Distance Sensor
 */

// Defines pins numbers
const int triggerPin = A4;
const int echoPin = A5;

void setup() {
  pinMode(triggerPin, OUTPUT);            // Sets the triggerPin as an Output
  pinMode(echoPin, INPUT);                // Sets the echoPin as an Input
  Serial.begin(9600);                     // Starts the serial communication
}
void loop() {
  Serial.print("Distance: ");
  Serial.println(checkDistance());
  delay(10);
}

int checkDistance()
{
  digitalWrite(triggerPin, LOW);          // Clears the triggerPin
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);         // Sets the triggerPin HIGH for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);          // Sets the triggerPin LOW again
  long duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  int distance = duration * 0.034 / 2;    // Calculates the distance
  return distance;
}
